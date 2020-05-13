#include "Effect.h"
#include <math.h>

//#define MAX_BUFFER_SIZE 440000
#define E_PI	3.14159265359
#define E_AVERAGE_TRESHOLD	1e-4

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
	return i-1;
}

unsigned int Effect::copyBuffer2in(float* buffer, float* in, unsigned int maxSize) {
	unsigned int i;
	setArray2zero(in, maxSize);
	for (i = 0; buffer[i] != INFINITY; i++) {
		in[i] = buffer[i];
	}
	return i-1;
}

unsigned int Effect::setBufferCrap2zero(float* buffer, unsigned int maxBufferSize) {
	unsigned int i;	//Habria que poner try y catch, pero por ahora vamos con esto
	for (i = 0; buffer[i] != INFINITY; i++);
	for (unsigned int u = i-1; u < maxBufferSize; u++)
		buffer[u] = 0;
	return i-1;
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

ReverbEffect::ReverbEffect(mode_t mode, float delay, float att, unsigned int maxSoundBufferSize) {
	this->mode = (short int)mode;
	this->delay = delay; //In seconds
	this->a = att;
	this->x = new float[maxSoundBufferSize];
	setArray2zero(average, AVERAGE_SIZE);
	return;
}

ReverbEffect::~ReverbEffect() {
	delete[] this->x;
}

void ReverbEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
	float* y = (float*)soundBuffer;
	unsigned int M = (unsigned int)(this->delay * sampleRate);
	copyBuffer2in(y, x, maxSoundBufferSize);
	unsigned int soundBufferSize = setBufferCrap2zero(y, maxSoundBufferSize);
	bool exit = false;
	restartAverage();

	if (this->mode == E_PLAIN) {
		for (unsigned int n = 0; (n < maxSoundBufferSize) && (exit == false); n++) {
			if (n >= M) {
				y[n] = x[n] + this->a * y[n - M];
				pushBackandPop(y[n]);
				if (isEffectFinished()) {
					y[n] = INFINITY;
					exit = true;
				}
			}
		}
	}
	else if (this->mode == E_ECO) {
		for (unsigned int n = 0; (n < maxSoundBufferSize) && (exit == false); n++) {
			if (n >= M) {
				y[n] = x[n] + this->a * x[n - M];
			}
			pushBackandPop(y[n]);
			if (isEffectFinished()) {
				y[n] = INFINITY;
				exit = true;
			}
		}
	}
	else if (this->mode == E_LOWPASS) {
		for (unsigned int n = 0; (n < maxSoundBufferSize) && (exit == false); n++) {
			if (n > M + 1) {
				y[n] = x[n] + (float)(0.5 * this->a * (y[n - M] + y[n - M - 1]));
			}
			else if (n > M) {
				y[n] = x[n] + (float)(0.5 * this->a * (y[n - M]));
			}
			pushBackandPop(y[n]);
			if (isEffectFinished()) {
				y[n] = INFINITY;
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

FlangerEffect::FlangerEffect(float fo, const int sampleRate, unsigned int maxSoundBufferSize, float Mw, float Mo, float g_fb, float g_ff) {
	this->fo = fo;
	this->Mo = Mo * sampleRate;
	this->Mw = this->Mo * Mw;
	//this->offset = offset;
	this->g_fb = g_fb;
	this->g_ff = g_ff;
	this->x = new float[maxSoundBufferSize];
	setArray2zero(average, AVERAGE_SIZE);
	return;
}

FlangerEffect::~FlangerEffect() {
	delete[] this->x;
}

void FlangerEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
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
	float* y = (float*)soundBuffer;
	unsigned int soundBufferSize = copyBuffer2in(y, x, maxSoundBufferSize); //Copio el buffer a in, y tengo el tamaño del buffer hasta INF
	setBufferCrap2zero(y, maxSoundBufferSize);
	restartAverage();

	for (int n = 0; (n < (int)maxSoundBufferSize) && (exit == false); n++) {
		float Mw = Mo * 10;
		float Mn = (float)(Mo + (Mw / 2) * (1 + sinf((float)(2 * E_PI * fo * n / (float)sampleRate))));
		if (n - Mn > 0 && (n - Mn) < soundBufferSize) {
			y[n] = g_fb * linearInterpolation(n - Mn, y) + x[n] + (g_ff - g_fb) * linearInterpolation(n - Mn, x);
		}
		else if (n - Mn < 0) {
			float temp;
			for (temp = (n - Mn); temp < 0; temp += soundBufferSize);
			y[n] = g_fb * y[n] + x[n];//+ (g_ff - g_fb) * linearInterpolation(temp, x);
		}
		else if ((n - Mn) > soundBufferSize) {
			float temp;
			for (temp = (n - Mn); temp > soundBufferSize; temp -= soundBufferSize);
			y[n] = g_fb * y[n] + x[n] + (g_ff - g_fb) * linearInterpolation(temp, x);
		}
		pushBackandPop(y[n]);
		if (isEffectFinished()) {
			y[n] = INFINITY;
			exit = true;
		}
	}
	return;
}

float FlangerEffect::linearInterpolation(float num, float* in) {
	return ((((int)(num)) + 1 - num) * in[(int)num] + (num - ((int)(num))) * in[(int)num + 1]);
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//									VIBRATO EFFECT									  //

VibratoEffect::VibratoEffect(float fo, const int sampleRate, unsigned int maxSoundBufferSize, float W, float M_avg) {
	this->W = (float)(W / (2 * E_PI * fo));
	this->fo = fo;
	this->x = new float[maxSoundBufferSize];
	this->comodin = new float[maxSoundBufferSize];
	this->M_avg = M_avg * (float)sampleRate;
	restartAverage();
	return;
}

VibratoEffect::~VibratoEffect() {
	delete[] this->x;
	delete[] this->comodin;
	return;
}

void VibratoEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
	float* y = (float*)soundBuffer;
	unsigned int soundBufferSize = copyBuffer2in(y, x, maxSoundBufferSize);
	bool exit = false;

	for (int n = 0; (n < (int)soundBufferSize) && (exit == false); n++) {
		float Mn = (float)(M_avg + W * sin(2 * E_PI * n * fo / (float)sampleRate));
		if (((n - Mn) > 0) && ((n - Mn) < soundBufferSize)) {
			y[n] = linearInterpolation(n - Mn);
		}
		else if (n - Mn < 0) {
			float temp;
			for (temp = n - Mn; temp < 0; temp += soundBufferSize);
			y[n] = linearInterpolation(temp);
		}
		else if ((n - Mn) > soundBufferSize) {
			float temp;
			for (temp = n - Mn; temp > soundBufferSize; temp -= soundBufferSize);
			y[n] = linearInterpolation(temp);
		}
		comodin[n] = y[n];
	}
	comodin[soundBufferSize] = y[0];

	for (int n = 0; n < (int)soundBufferSize; n++) {
		if ((n + M_avg) < soundBufferSize)
			y[n] = comodin[(int)(n + M_avg)];
		else {
			float temp;
			for (temp = n + M_avg; temp > soundBufferSize; temp -= soundBufferSize);
			y[n] = comodin[(int)temp];
		}
	}
	return;
}

float VibratoEffect::linearInterpolation(float num) {
	return ((((int)(num)) + 1 - num) * this->x[(int)num] + (num - ((int)(num))) * this->x[(int)num + 1]);
}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//									EQUALIZATOR EFFECT								  //


EqualizatorEffect::EqualizatorEffect(float gainLow, float gainMid, float gainHigh, unsigned int maxSoundBufferSize) {
	float sampleRate = 44e3;
	this->x = new float[maxSoundBufferSize];
	lowFreq = 300.0  * 2 * E_PI / (sampleRate);
	midFreq = 700.0 * 2 * E_PI / sampleRate;
	midB = 400.0 * 2 * E_PI / sampleRate;
	highFreq = 1.5e3 * 2 * E_PI / sampleRate;
	changeGains(gainLow, gainMid, gainHigh);
	return;
}

EqualizatorEffect::~EqualizatorEffect() {
	delete[] this->x;
	return;
}

void EqualizatorEffect::compFilterParameters() {
	lowFilter.A = (float)(tan(lowFreq / 2) * gainLow + sqrt(gainLow));
	lowFilter.B = (float)(tan(lowFreq / 2) * gainLow - sqrt(gainLow));
	lowFilter.C = (float)(tan(lowFreq / 2) + sqrt(gainLow));
	lowFilter.D = (float)(tan(lowFreq / 2) - sqrt(gainLow));

	highFilter.A = (float)(tan(highFreq / 2) * sqrt(gainHigh) + gainHigh);
	highFilter.B = (float)(tan(highFreq / 2) * sqrt(gainHigh) - gainHigh);
	highFilter.C = (float)(tan(highFreq / 2) * sqrt(gainHigh) + 1);
	highFilter.D = (float)(tan(highFreq / 2) * sqrt(gainHigh) - 1);

	midFilter.A = (float)(sqrt(gainMid) + tan(midB / 2) * gainMid);
	midFilter.B = (float)(-2*cos(midFreq)* sqrt(gainMid));
	midFilter.C = (float)(sqrt(gainMid) - tan(midB / 2) * gainMid);
	midFilter.D = (float)(sqrt(gainMid) + tan(midB / 2));
	midFilter.E = (float)(sqrt(gainMid) - tan(midB / 2));
	return;
}

void EqualizatorEffect::changeGains(float gainLow, float gainMid, float gainHigh) {
	this->gainLow = (float)(0.25 + gainLow * 3.75);
	this->gainMid = (float)(0.25 + gainMid * 3.75);
	this->gainHigh = (float)(0.25 + gainHigh * 3.75);
	compFilterParameters();
}

void EqualizatorEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {

	float* y = (float*)soundBuffer;
	//Primero paso por el ecualizador de bajos
	unsigned int soundBufferSize = copyBuffer2in(y, x, maxSoundBufferSize);
	for (unsigned int n = 0; n < soundBufferSize; n++) {
		if (n >= 1) {
			y[n] = (lowFilter.A * x[n] + lowFilter.B * x[n - 1] - lowFilter.D * y[n - 1]) / lowFilter.C;
		}
		else {
			y[n] = (lowFilter.A * x[n]) / lowFilter.C;
		}
	}

	//Ecualizador de medios
	soundBufferSize = copyBuffer2in(y, x, maxSoundBufferSize);
	for (unsigned int n = 0; n < soundBufferSize; n++) {
		if (n >= 2) {
			y[n] = (midFilter.A * x[n] + midFilter.B * x[n - 1] + midFilter.C * x[n - 2]- midFilter.B * y[n-1] - midFilter.E * y[n-2]) / midFilter.D;
		}
		else if (n == 1) {
			y[n] = (midFilter.A * x[n] + midFilter.B * x[n - 1] - midFilter.B * y[n - 1]) / midFilter.D;
		}
		else {
			y[n] = (midFilter.A * x[n]) / midFilter.D;
		}
	}

	//Ecualizador de agudos
	soundBufferSize = copyBuffer2in(y, x, maxSoundBufferSize);
	for (unsigned int n = 0; n < soundBufferSize; n++) {
		if (n >= 1) {
			y[n] = (highFilter.A * x[n] + highFilter.B * x[n - 1] - highFilter.D * y[n - 1]) / highFilter.C;
		}
		else {
			y[n] = (highFilter.A * x[n]) / highFilter.C;
		}
	}

	return;
}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//									WAH-WAH EFFECT									  //


WahwahEffect::WahwahEffect(float f_min, float f_LFO, unsigned int samplingRate, unsigned int maxBufferSize) {
	this->f_LFO = f_LFO;
	this->f_min = f_min;
	this->samplingRate = samplingRate;
	this->x = new float[maxBufferSize];
	this->Q = 5; //De 2 a 10
	this->width = 500;
	this->G_c = 1.5; // Correción de volumen
	return;
}

WahwahEffect::~WahwahEffect() {
	delete[] this->x;
	return;
}

float WahwahEffect::getFrecuency(unsigned int n) {
	return (float)(f_min + ((width / 2) * (1 + cos(2 * E_PI * n * f_LFO / (float)samplingRate))));
}

void WahwahEffect::callback(void* soundBuffer, const unsigned int maxSoundBufferSize, const int sampleRate) {
	wahFilter_t filter;
	float* y = (float*)soundBuffer;
	unsigned int soundBufferSize = copyBuffer2in(y, x, maxSoundBufferSize);

	for (unsigned int n = 0; n < soundBufferSize; n++) {
		float f_c = getFrecuency(n);
		float K = (float)tan(E_PI * f_c/(float)sampleRate);
		filter = getFilterParameters(K);

		if (n >= 2) {
			y[n] = filter.b0 * x[n] + filter.b1 * x[n - 1] + filter.b2 * x[n - 2] - filter.a1 * y[n - 1] - filter.a2 * y[n - 2];
		}
		else if (n == 1) {
			y[n] = filter.b0 * x[n] + filter.b1 * x[n - 1] - filter.a1 * y[n - 1];
		}
		else if (n == 0) {
			y[n] = filter.b0 * x[n];
		}
	}

	return;
}

wahFilter_t WahwahEffect::getFilterParameters(float K) {
	wahFilter_t filter;
	filter.b0 = (float)(K / (pow(K, 2) * Q + K + Q)) * G_c;
	filter.b1 = 0;
	filter.b2 = -filter.b0 * G_c;
	filter.a0 = 1;
	filter.a1 = (float)((2 * Q * (pow(K, 2) - 1)) / (pow(K, 2) * Q + K + Q));
	filter.a2 = (float)((pow(K, 2) * Q - K + Q) / (pow(K, 2) * Q + K + Q));
	return filter;
}