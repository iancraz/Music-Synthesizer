#include "Instrument.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <stdlib.h> 
#include<time.h> 


void ADSRInstrument::setParams(adsrParams_t* _params) {
	if (_params->tAttack < 15.0 && _params->tDecay < 15.0 && _params->sustainLevel <= 1.0 && _params->sustainRate <= 1.0 && _params->tRelease < 15 && _params->k < 5.0 && _params->tAttack > 0.0 && _params->tDecay > 0.0 && _params->sustainLevel > 0.0 && _params->sustainRate > 0.0 && _params->tRelease > 0.0 && _params->k > 0.0)
	{
		params->tAttack = _params->tAttack;
		params->tDecay = _params->tDecay;
		params->sustainRate = _params->sustainRate;
		params->k = _params->k;
		params->tRelease = _params->tRelease;
		params->sustainLevel = _params->sustainLevel;
		params->sampleRate = _params->sampleRate;
		params->buffLength = _params->buffLength;
		
	}
	else
		throw "Error! ADSR parameters are invalid";
}

ADSRInstrument::ADSRInstrument(adsrParams_t* _params) {
	if (_params) setParams(_params);


	this->wform1 = _params->wform1;
	this->level1 = _params->level1;
	
	this->wform2 = _params->wform2;
	this->level2 = _params->level2;

	envelope= new float[_params->buffLength];
	envBuffer = new float[_params->buffLength];
	release = new float[_params->buffLength];
	relBuffer = new float[_params->buffLength];

	generateEnvelope(_params->sampleRate, _params->buffLength);

}

int ADSRInstrument::generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength) {
	//long noteDuration_n = durSeconds * (float)sampleRate;
	int nAttack = params->tAttack * (float)sampleRate;
	int nDecay = params->tDecay * (float)sampleRate;
	int nRelease = params->tRelease * (float)sampleRate;
	float sustainLevel = params->sustainLevel;
	float sustainRate = params->sustainRate;

	unsigned long i = 0;
	bool reachedEnd = false;

	while (i < nAttack) {
		envBuffer[i] = 1 - exp(-2 * 3.1415 * i / nAttack);
		i++;
	}
	while (i < nAttack + nDecay) {
		envBuffer[i] = ((1 - sustainLevel) * exp((-2 * 3.1415 / nDecay) * (-nAttack + i)));
		i++;
	}
	while (sustainLevel > 0.0 && !reachedEnd) {
		if (i - (nAttack + nDecay) >= 0 || i == buffLength)
			reachedEnd = true;
		else envBuffer[i] = sustainLevel - sustainRate * (i - (nAttack + nDecay));

		i++;
	}

	unsigned long k = 0;
	reachedEnd = false;
	while (k < nRelease) {
		relBuffer[k] = exp((-2 * 3.1415 / nRelease) * k);
		k++;
	}

	float* tempEnv = envelope;
	float* tempRel = release;
	envelope = envBuffer;
	release = relBuffer;
	envBuffer = tempEnv;
	relBuffer = tempRel;

	return i - 1;
}

int
ADSRInstrument::synthFunction(float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float durSeconds,
	const int velocity,
	const int sampleRate) {
	//unsigned int envelopeDuration = generateEnvelope(durSeconds, (float)velocity / 127.0, sampleRate);
	float freq = 440.0 * pow(2.0, ((float)keyNumber - 69.0) / 12.0);
	unsigned int nPressedLength = durSeconds * sampleRate;
	float finalSustainValue = 0.0;
	int j = 0;
	int nRelease = sampleRate * params->tRelease;
	float velocityFactor = (float)velocity / 127.0;
	while (envelope[j] >= 0 && j < outputBufferSize) {
		if (j < nPressedLength) {
			switch (wform1) {
			case waveform::square:
				outputBuffer[j] = level1 * envelope[j] * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
				break;
			case waveform::sine:
				outputBuffer[j] = level1 * envelope[j] * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j));
				break;
			case waveform::sawtooth:
				outputBuffer[j] = level1 * envelope[j] * velocityFactor * (((float)j / (float)freq) - (int)((float)j / (float)freq));
				break;
			}
			switch (wform2) {
			case waveform::square:
				outputBuffer[j] += level2 * envelope[j] * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
				break;
			case waveform::sine:
				outputBuffer[j] += level2 * envelope[j] * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j));
				break;
			case waveform::sawtooth:
				outputBuffer[j] += level2 * envelope[j] * velocityFactor * (((float)j / (float)freq) - (int)((float)j / (float)freq));
				break;
			}
			outputBuffer[j] = 0.5 * outputBuffer[j];
		}
		else {
			if (finalSustainValue == 0.0) finalSustainValue = outputBuffer[j - 1];
			if (j - nPressedLength < nRelease)
			{
				switch (wform1) {
				case waveform::square:
					outputBuffer[j] = level1 * (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
					break;
				case waveform::sine:
					outputBuffer[j] = level1 * (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j));
					break;
				case waveform::sawtooth:
					outputBuffer[j] = level1 * (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (((float)j / (float)freq) - (int)((float)j / (float)freq));
					break;
				}
				switch (wform2) {
				case waveform::square:
					outputBuffer[j] += level2 * (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
					break;
				case waveform::sine:
					outputBuffer[j] += level2 * (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j));
					break;
				case waveform::sawtooth:
					outputBuffer[j] += level2 * (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (((float)j / (float)freq) - (int)((float)j / (float)freq));
					break;
				}
				outputBuffer[j] = 0.5 * outputBuffer[j];
			}
			else break;
		}
		j++;
	}
	outputBuffer[j] = INFINITY;
	return 0;
}

