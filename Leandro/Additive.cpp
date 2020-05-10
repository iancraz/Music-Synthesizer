#include "Additive.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>

void additiveInstrument::setParams(adsrParams_t* _params) {
	if (_params->tAttack < 15.0 && _params->tDecay < 15.0 && _params->sustainLevel <= 1.0 && _params->sustainRate <= 1.0 && _params->tRelease < 15 && _params->k < 5.0 && _params->tAttack > 0.0 && _params->tDecay > 0.0 && _params->sustainLevel > 0.0 && _params->sustainRate > 0.0 && _params->tRelease > 0.0 && _params->k > 0.0)
		params = *_params;
	else 
		throw "Error! ADSR parameters are invalid";
}

additiveInstrument::additiveInstrument(adsrParams_t* _params, const unsigned int buffLength, const unsigned int sampleRate) {
	if (_params) setParams(_params);
	else {
		params.tAttack = 0.2;
		params.tDecay = 0.3;
		params.sustainLevel = 0.5;
		params.sustainRate = 0.05;
		params.tRelease = 1.0;
		params.k = 1.0;
	}
	
	envelope = new float[buffLength];
	release = new float[buffLength];
	generateEnvelope(sampleRate, buffLength);
}

int additiveInstrument::generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength) {
	//long noteDuration_n = durSeconds * (float)sampleRate;
	int nAttack = params.tAttack * (float)sampleRate;
	int nDecay = params.tDecay * (float)sampleRate;
	int nRelease = params.tRelease * (float)sampleRate;
	float sustainLevel = params.sustainLevel;
	float sustainRate = params.sustainRate;

	unsigned long i = 0;
	bool reachedEnd = false;

	while (i < nAttack) {
		envelope[i] = 1 - exp(-2 * 3.1415 * i / nAttack);
		i++;
	}
	while (i < nAttack + nDecay) {
		envelope[i] = ((1 - sustainLevel) * exp((-2 * 3.1415 / nDecay)*(-nAttack + i)));
		i++;
	}
	while (sustainLevel > 0.0 && !reachedEnd) {
		if (i - (nAttack + nDecay) >= 0 || i == buffLength)
			reachedEnd = true;
		else envelope[i] = sustainLevel - sustainRate*(i - (nAttack + nDecay));
		
		i++;
	}
	
	unsigned long k=0;
	reachedEnd = false;
	while (k<nRelease) {
		release[k]=exp((-2 * 3.1415 / nRelease)*k);
		k++;
	}
	
		return i-1;
/*

	if (noteDuration_n > nAttack + nDecay) {
		while (i < nAttack) {
			envelope[i] = (params.k * A0) / params.tAttack * (float)i / (float)sampleRate;
			i++;
		}
		while (i < nAttack + nDecay) {
			envelope[i] = params.k * A0 - A0 * (params.k - 1) / params.tDecay * (float)(i - nAttack) / (float)sampleRate;
			i++;
		}
		int nSustain = noteDuration_n - (nAttack + nDecay);
		while (i < nAttack + nDecay + nSustain) {
			if (A0 - params.sustainRate * (float)(i - (nAttack + nDecay)) / (float)sampleRate > 0)
				envelope[i] = A0 - params.sustainRate * (float)(i - (nAttack + nDecay)) / (float)sampleRate;
			else
				break;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < nAttack + nDecay + nSustain + nRelease) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - (nAttack + nDecay + nSustain)) / (float)sampleRate;
			i++;
		}
	}
	else if (noteDuration_n > nAttack && noteDuration_n < nAttack + nDecay) {
		while (i < nAttack) {
			envelope[i] = (float)i / (float)sampleRate * (params.k * (float)A0) / params.tAttack;
			i++;
		}
		while (i < (noteDuration_n)) {
			envelope[i] = params.k * A0 - A0 * (params.k - 1) / params.tDecay * (float)(i - nAttack) / (float)sampleRate;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < noteDuration_n + nDecay) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - noteDuration_n) / (float)sampleRate;
			i++;
		}
	}
	else if (noteDuration_n < nAttack) {
		while (i < noteDuration_n) {
			envelope[i] = (float)i / (float)sampleRate * (params.k * (float)A0) / params.tAttack;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < noteDuration_n + nRelease) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - noteDuration_n) / (float)sampleRate;
			i++;
		}
	}
	return i-1;
	*/
}

int
additiveInstrument::synthFunction(float* outputBuffer,
								  const unsigned int outputBufferSize,
								  const int keyNumber,
								  const float durSeconds,
								  const int velocity,
								  const int sampleRate) {

	//unsigned int envelopeDuration = generateEnvelope(durSeconds, (float)velocity / 127.0, sampleRate);
	float freq = 440.0 * pow(2.0, (keyNumber - 69.0) / 12.0);
	unsigned int nPressedLength = durSeconds * sampleRate;
	float finalSustainValue = 0.0;
	int j = 0;
	int nRelease = sampleRate * params.tRelease;
	float velocityFactor = (float)velocity / 127.0;
	while (envelope[j] >= 0 && j < outputBufferSize) {
		if(j < nPressedLength)
		outputBuffer[j] = envelope[j] * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
		else {
			if (finalSustainValue == 0.0) finalSustainValue = outputBuffer[j - 1];
			if (j - nPressedLength < nRelease) 
				outputBuffer[j] = (finalSustainValue* release[j-nPressedLength]) * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
			else break;
		}
		j++;
	}
	outputBuffer[j] = INFINITY;
	return 0;
}