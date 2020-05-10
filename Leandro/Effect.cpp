#include "Effect.h"
#include <math.h>

#define MAX_BUFFER_SIZE 440000
#define E_PI	3.14159265359

Effect::Effect() {
	// Effect constructor here. Should set defaults, load data and allocate memory as needed.

}

Effect::~Effect() {
	// Effect destructor here. Should destruct all items and free all allocated memory on stack.

}

void Effect::callback(void* soundBuffer, const unsigned int soundBufferSize, int sampleRate) {
	// Data-processing callback here. Recieves input buffer and puts modified data into output buffer.
	return;
}

reverbEffect::reverbEffect(mode_t mode, float delay, float att) {
	this->mode = (short int)mode;
	this->delay = delay; //In seconds
	this->a = att;
	return;
}

void reverbEffect::callback(void* soundBuffer, const unsigned int soundBufferSize, const int sampleRate) {
	float* buff = (float*)soundBuffer;
	unsigned int numDelay = (int)(this->delay * sampleRate);

	//int k = 0;
	//while (buff[k] != INFINITY) k++;
	//int soundBufferSize = k;
	


	if (this->mode == E_PLAIN) {
		for (unsigned int i = 0; i < soundBufferSize; i++) {
			if (i >= numDelay) {
				buff[i] += this->a * buff[i - numDelay];
			}
		}
	}
	else if (this->mode == E_ECO) {
		for (int i = soundBufferSize-1; i >= 0; i--) {
			if (i >= numDelay) {
				buff[i] += this->a * buff[i - numDelay];
			}
		}
	}
	else if (this->mode == E_LOWPASS) {
		for (int i = soundBufferSize-1; i >= 0; i--) {
			if (i >= numDelay + 1) {
				buff[i] += 0.5 * this->a * (buff[i - numDelay] + buff[i - numDelay - 1]);
			}
			else if (i >= numDelay) {
				buff[i] += 0.5 * this->a * (buff[i - numDelay]);
			}
		}
	}
	return;
}

flangerEffect::flangerEffect(float fo, float Mo, float g_fb, float g_ff) {
	this->fo = fo;
	this->Mo = Mo;
	//this->offset = offset;
	this->g_fb = g_fb;
	this->g_ff = g_ff;
	this->in = new float[MAX_BUFFER_SIZE];
	return;
}

flangerEffect::~flangerEffect() {
	delete[] this->in;
}

void flangerEffect::callback(void* soundBuffer, const unsigned int soundBufferSize, const int sampleRate) {
	
	// SIMPLE
	/*
	float* buff = (float*)soundBuffer;
	for (int i = 0; i < soundBufferSize; i++)
		in[i] = buff[i];
	for (int i = 0; i < soundBufferSize; i++) {
		float M_avg = 0.5 * SAMPLE_RATE;
		float fo = 0.5;
		float W = 1e3 / (2 * E_PI * fo);
		float Mo = 1e-3 * SAMPLE_RATE;
		float Mw = Mo * 0.5;
		float Mn = Mo + (Mw / 2) * (1 + sinf(2 * E_PI * fo * i / SAMPLE_RATE));
		float g = 1;
		//float g_ff = 0.8;
		if (i - Mn > 0) {
			buff[i] =  in[i] + g * linearInterpolation(i - Mn, in);
		}
		else if (i - Mn < 0) {
			buff[i] =  in[i] + g * linearInterpolation(i - Mn + soundBufferSize, in);
		}
	}
	return;*/

	//FEEDBACK

	this->Mo = this->Mo * sampleRate;

	float* buff = (float*)soundBuffer;
	for (int i = 0; i < soundBufferSize; i++)
		in[i] = buff[i];
	for (int i = 0; i < soundBufferSize; i++) {
		//float fo = 0.5;
		//float Mo = 1e-3 * SAMPLE_RATE;
		float Mw = Mo * 1;
		float Mn = Mo + (Mw / 2) * (1 + sinf(2 * E_PI * fo * i / sampleRate));
		//float g_fb = 0.3;
		//float g_ff = 1;
		if (i - Mn > 0) {
			buff[i] = g_fb * linearInterpolation(i-Mn,buff) + in[i] + (g_ff - g_fb) * linearInterpolation(i - Mn, in);
		}
		/*else if (i - Mn < 0) {
			buff[i] = g_fb * buff[i] + in[i] + (g_ff - g_fb) * linearInterpolation(i - Mn + soundBufferSize, in);
		}*/
	}
}

float flangerEffect::linearInterpolation(float num, float * in) {
	float answr = (((int)(num)) + 1 - num) * in[(int)num] + (num - ((int)(num))) * in[(int)num + 1];
	return answr;
}

vibratoEffect::vibratoEffect(float W, float fo, float M_avg, const int sampleRate) {
	this->W = W / (2 * E_PI * fo);
	this->fo = fo;
	this->in = new float[MAX_BUFFER_SIZE];
	this->comodin = new float[MAX_BUFFER_SIZE];
	this->M_avg = M_avg * (float)sampleRate;
	return;
}

vibratoEffect::~vibratoEffect() {
	delete[] this->in;
	delete[] this->comodin;
	return;
}

void vibratoEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
	
	
	float* buff = (float*)soundBuffer;
	int i = 0;
	while(buff[i]!=INFINITY){
	
	//for (int i = 0; i < soundBufferSize; i++) {
		in[i] = buff[i];
		i++;
	}
	int soundBufferSize = i;
	for (int i = 0; i < soundBufferSize; i++) {
		float Mn = M_avg + W * sin(2 * E_PI * i * fo / (float)sampleRate);
		if (i - Mn > 0) {
			buff[i] = linearInterpolation(i - Mn);
		}
		else if (i - Mn < 0) {
			buff[i] = linearInterpolation(i - Mn + soundBufferSize);
		}
		comodin[i] = buff[i];
	}

	for (int i = 0; i < soundBufferSize; i++) {
		if (i + M_avg < soundBufferSize)
			buff[i] = comodin[(int)(i + M_avg)];
		else
			buff[i] = comodin[(int)(i + M_avg)-soundBufferSize];
	}
}

float vibratoEffect::linearInterpolation(float num) {
	float answr = (((int)(num)) + 1 - num) * this->in[(int)num] + (num - ((int)(num))) * this->in[(int)num + 1];
	return answr;
}

/*wahwahEffect::wahwahEffect(float damping, float width, float min_cutoff, float max_cutoff) {
	this->damping = damping;
	this->width = width;
	this->min_cutoff = min_cutoff;
	this->max_cutoff = max_cutoff;
	return;
}

void wahwahEffect::callback(void* soundBuffer, const unsigned int soundBufferSize) {
	float* buff = (float*)soundBuffer;
	float center_freq = this->width / SAMPLE_RATE;
	float pi = 3.14159265359;
	float F1 = 2 * sin(pi * this->min_cutoff) / SAMPLE_RATE;
	float Q1 = 2 * damping;

	return;
}*/