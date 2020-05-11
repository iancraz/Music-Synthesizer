#include "Effect.h"
#include <math.h>

//#define MAX_BUFFER_SIZE 440000
#define E_PI	3.14159265359
#define E_AVERAGE_TRESHOLD	1e-3

Effect::Effect() {
	// Effect constructor here. Should set defaults, load data and allocate memory as needed.
	setArray2zero(average, AVERAGE_SIZE);
}

Effect::~Effect() {
	// Effect destructor here. Should destruct all items and free all allocated memory on stack.
}

void Effect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, int sampleRate) {
	// Data-processing callback here. Recieves input buffer and puts modified data into output buffer.
	return;
}

unsigned int Effect::getBufferSize(float* buffer) {
	unsigned int i;	//Habria que poner try y catch, pero por ahora vamos con esto
	for (i = 0; buffer[i] != INFINITY; i++);
	return i;
}

unsigned int Effect::copyBuffer2in(float* buffer, float* in, unsigned int maxSize) {
	unsigned int i;
	setArray2zero(in, maxSize);
	for (i = 0; buffer[i] != INFINITY; i++) {
		in[i] = buffer[i];
	}
	return i;
}

unsigned int Effect::setBufferCrap2zero(float* buffer, unsigned int maxBufferSize) {
	unsigned int i;	//Habria que poner try y catch, pero por ahora vamos con esto
	for (i = 0; buffer[i] != INFINITY; i++);
	for (unsigned int u = i; u < maxBufferSize; u++)
		buffer[u] = 0;
	return i;
}

void Effect::setArray2zero(float* arr, unsigned int size) {
	for (unsigned int i = 0; i < size; i++)
		arr[i] = 0;
	return;
}

float Effect::getAverage() {
	float avg = 0.0;
	for (unsigned int i = 0; i < AVERAGE_SIZE; i++)
		avg += average[i];
	return (avg / (float)AVERAGE_SIZE);
}

void Effect::pushBackandPop(float element) {
	if (element < 0)
		element = -element;
	if (avgPtr < AVERAGE_SIZE) {
		average[avgPtr] = element;
		avgPtr++;
	}
	else if (avgPtr >= AVERAGE_SIZE) {
		avgPtr = 0;
		average[avgPtr] = element;
		avgFull = true;
	}
}

bool Effect::isEffectFinished() {
	float temp = getAverage();
	bool exit = false;
	if (temp <= E_AVERAGE_TRESHOLD && (avgFull == true))
		exit = true;
	return exit;
}

void Effect::restartAverage() {
	setArray2zero(average, AVERAGE_SIZE);
	avgFull = false;
	avgPtr = 0;
	return;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//									REVERB EFFECT									  //

reverbEffect::reverbEffect(mode_t mode, float delay, float att, unsigned int maxSoundBufferSize) {
	this->mode = (short int)mode;
	this->delay = delay; //In seconds
	this->a = att;
	this->in = new float[maxSoundBufferSize];
	setArray2zero(average, AVERAGE_SIZE);
	return;
}

reverbEffect::~reverbEffect() {
	delete[] this->in;
}

void reverbEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
	float* buff = (float*)soundBuffer;
	unsigned int numDelay = (int)(this->delay * sampleRate);
	copyBuffer2in(buff, in, maxSoundBufferSize);
	unsigned int soundBufferSize = setBufferCrap2zero(buff, maxSoundBufferSize);
	bool exit = false;
	restartAverage();

	if (this->mode == E_PLAIN) {
		for (unsigned int i = 0; (i < maxSoundBufferSize) && (exit == false); i++) {
			if (i >= numDelay) {
				buff[i] += this->a * buff[i - numDelay];
				pushBackandPop(buff[i]);
				if (isEffectFinished()) {
					buff[i] = INFINITY;
					exit = true;
				}
			}
		}
	}
	else if (this->mode == E_ECO) {
		for (unsigned int i = 0; (i < maxSoundBufferSize) && (exit == false); i++) {
			if (i >= numDelay) {
				buff[i] = in[i] + this->a * in[i - numDelay];
			}
			pushBackandPop(buff[i]);
			if (isEffectFinished()) {
				buff[i] = INFINITY;
				exit = true;
			}
		}
	}
	else if (this->mode == E_LOWPASS) {
		for (unsigned int i = 0; (i < maxSoundBufferSize) && (exit == false); i++) {
			if (i > numDelay + 1) {
				buff[i] += (float)(0.5 * this->a * (in[i - numDelay] + in[i - numDelay - 1]));
			}
			else if (i > numDelay) {
				buff[i] += (float)(0.5 * this->a * (in[i - numDelay]));
			}
			pushBackandPop(buff[i]);
			if (isEffectFinished()) {
				buff[i] = INFINITY;
				exit = true;
			}
		}
	}
	return;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//									FLANGER EFFECT									  //

flangerEffect::flangerEffect(float fo, float Mw, float Mo, float g_fb, float g_ff, const int sampleRate, unsigned int maxSoundBufferSize) {
	this->fo = fo;
	this->Mo = Mo * sampleRate;
	this->Mw = this->Mo * Mw;
	//this->offset = offset;
	this->g_fb = g_fb;
	this->g_ff = g_ff;
	this->in = new float[maxSoundBufferSize];
	setArray2zero(average, AVERAGE_SIZE);
	return;
}

flangerEffect::~flangerEffect() {
	delete[] this->in;
}

void flangerEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
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
	bool exit = false;
	float* buff = (float*)soundBuffer;
	unsigned int soundBufferSize = copyBuffer2in(buff, in, maxSoundBufferSize); //Copio el buffer a in, y tengo el tamaño del buffer hasta INF
	setBufferCrap2zero(buff, maxSoundBufferSize);
	restartAverage();

	for (int i = 0; (i < (int)maxSoundBufferSize) && (exit == false); i++) {
		float Mw = Mo * 10;
		float Mn = (float)(Mo + (Mw / 2) * (1 + sinf((float)(2 * E_PI * fo * i / (float)sampleRate))));
		if (i - Mn > 0 && (i - Mn) < soundBufferSize) {
			buff[i] = g_fb * linearInterpolation(i - Mn, buff) + in[i] + (g_ff - g_fb) * linearInterpolation(i - Mn, in);
		}
		else if (i - Mn < 0) {
			float temp;
			for (temp = (i - Mn); temp < 0; temp += soundBufferSize);
			buff[i] = g_fb * buff[i] + in[i] + (g_ff - g_fb) * linearInterpolation(temp, in);
		}
		else if ((i - Mn) > soundBufferSize) {
			float temp;
			for (temp = (i - Mn); temp > soundBufferSize; temp -= soundBufferSize);
			buff[i] = g_fb * buff[i] + in[i] + (g_ff - g_fb) * linearInterpolation(temp, in);
		}
		pushBackandPop(buff[i]);
		if (isEffectFinished()) {
			buff[i] = INFINITY;
			exit = true;
		}
	}
	return;
}

float flangerEffect::linearInterpolation(float num, float* in) {
	return ((((int)(num)) + 1 - num) * in[(int)num] + (num - ((int)(num))) * in[(int)num + 1]);
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//									VIBRATO EFFECT									  //

vibratoEffect::vibratoEffect(float W, float fo, float M_avg, const int sampleRate, unsigned int maxSoundBufferSize) {
	this->W = (float)(W / (2 * E_PI * fo));
	this->fo = fo;
	this->in = new float[maxSoundBufferSize];
	this->comodin = new float[maxSoundBufferSize];
	this->M_avg = M_avg * (float)sampleRate;
	restartAverage();
	return;
}

vibratoEffect::~vibratoEffect() {
	delete[] this->in;
	delete[] this->comodin;
	return;
}

void vibratoEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
	float* buff = (float*)soundBuffer;
	unsigned int soundBufferSize = copyBuffer2in(buff, in, maxSoundBufferSize);
	bool exit = false;

	for (int i = 0; (i < (int)soundBufferSize) && (exit == false); i++) {
		float Mn = (float)(M_avg + W * sin(2 * E_PI * i * fo / (float)sampleRate));
		if (((i - Mn) > 0) && ((i - Mn) < soundBufferSize)) {
			buff[i] = linearInterpolation(i - Mn);
		}
		else if (i - Mn < 0) {
			float temp;
			for (temp = i - Mn; temp < 0; temp += soundBufferSize);
			buff[i] = linearInterpolation(temp);
		}
		else if ((i - Mn) > soundBufferSize) {
			float temp;
			for (temp = i - Mn; temp > soundBufferSize; temp -= soundBufferSize);
			buff[i] = linearInterpolation(temp);
		}
		comodin[i] = buff[i];
	}

	for (int i = 0; i < (int)soundBufferSize; i++) {
		if ((i + M_avg) < soundBufferSize)
			buff[i] = comodin[(int)(i + M_avg)];
		else {
			float temp;
			for (temp = i + M_avg; temp > soundBufferSize; temp -= soundBufferSize);
			buff[i] = comodin[(int)temp];
		}
	}
	return;
}

float vibratoEffect::linearInterpolation(float num) {
	return ((((int)(num)) + 1 - num) * this->in[(int)num] + (num - ((int)(num))) * this->in[(int)num + 1]);
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