#include "Additive.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>

additiveInstrument::additiveInstrument(adsrParams_t _params, const unsigned int buffLength) {
	params = _params;
	envelope = new float[buffLength];
}

int additiveInstrument::generateEnvelope(float lengthInMilisecods, float A0, int sampleRate) {
	long noteDuration_n = lengthInMilisecods * sampleRate / 1000.0;
	int nAttack = params.tAttack * sampleRate;
	int nDecay = params.tDecay * sampleRate;
	int nRelease = params.tRelease * sampleRate;
	int synthDuration_n = (lengthInMilisecods / 1000.0 + params.tRelease) * sampleRate;

	unsigned long i = 0;

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
}

int
additiveInstrument::synthFunction(float* outputBuffer,
								  const unsigned int outputBufferSize,
								  const int keyNumber,
								  const float lengthInMilliseconds,
								  const int velocity,
								  const int sampleRate) {

	unsigned int envelopeDuration = generateEnvelope(lengthInMilliseconds, (float)velocity / 127.0, sampleRate);
	float freq = 440.0 * pow(2.0, (keyNumber - 69.0) / 12.0);
	unsigned int totalLength = (envelopeDuration < outputBufferSize) ? envelopeDuration : outputBufferSize;

	for (int j = 0; j < totalLength; j++) {
		outputBuffer[j] = envelope[j] * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
		if (outputBuffer[j] > 2.0 || outputBuffer[j] < -2.0) {
			float pedo = outputBuffer[j];
			float pedito = envelope[j];
		}
	}
	
	outputBuffer[totalLength - 1] = INFINITY;

	return 0;
}