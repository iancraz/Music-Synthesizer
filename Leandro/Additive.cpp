#include "Additive.h"
#define _USE_MATH_DEFINES
#include <math.h>

additiveInstrument::additiveInstrument(adsrParams_t _params) {
	params.tAttack = _params.tAttack;
	params.tDecay = _params.tRelease;
	params.sustainRate = _params.sustainRate;
	params.tRelease = _params.tRelease;
}

int
additiveInstrument::synthFunction(
		float* outputBuffer,
		const unsigned int outputBufferSize,
		int keyNumber,
		float lengthInMilliseconds,
		int velocity,
		unsigned int sampleRate) {
	int noteDuration_n = (int)(lengthInMilliseconds * 1000 * sampleRate);
	int nAttack = params.tAttack * sampleRate;
	int nDecay = (int)(params.tDecay * sampleRate);
	int nRelease = (int)(params.tRelease * sampleRate);
	int synthDuration_n = (int)((lengthInMilliseconds * 1000 + params.tRelease) * sampleRate);
	float A0 = (float)velocity / 127.0;
	float* envelope = nullptr;
	envelope = new float[synthDuration_n];

	float freq = 440.0 * pow(2, (keyNumber - 69) / 12);

	int i = 0;
	if (noteDuration_n > nAttack + nDecay) {
		while (i < nAttack && i < outputBufferSize)
		{
			envelope[i] = (params.k * A0) / params.tAttack * (float)i / sampleRate;
			i++;
		}
		while (i < nAttack + nDecay && i < outputBufferSize) {
			envelope[i] = params.k * A0 - A0 * (params.k - 1) / params.tDecay * (float)(i - (nAttack + nDecay)) / sampleRate;
			i++;
		}
		int nSustain = noteDuration_n - (nAttack + nDecay);
		while (i < nAttack + nDecay + nSustain && i < outputBufferSize) {
			if (A0 - params.sustainRate * (float)(i - (nAttack + nDecay)) / sampleRate > 0)
				envelope[i] = A0 - params.sustainRate * (float)(i - (nAttack + nDecay)) / sampleRate;
			else
				break;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < nAttack + nDecay + nRelease && i < outputBufferSize) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - (nAttack + nDecay + nSustain)) / sampleRate;
			i++;
		}
	}
	else if (noteDuration_n > nAttack && noteDuration_n < nAttack + nDecay) {
		while (i < nAttack) {
			envelope[i] = (float)i / sampleRate * (params.k * (float)A0) / params.tAttack;
			i++;
		}
		while (i < (noteDuration_n)) {
			envelope[i] = params.k * A0 - A0 * (params.k - 1) / params.tDecay * (float)(i - nAttack) / sampleRate;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < noteDuration_n + nDecay) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - noteDuration_n) / sampleRate;
			i++;
		}
	}
	else if (noteDuration_n < nAttack) {
		while (i < noteDuration_n) {
			envelope[i] += (float)i / sampleRate * (params.k * (float)A0) / params.tAttack;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < noteDuration_n + nRelease) {
			envelope[i] += Ar - Ar / params.tRelease * (float)(i - noteDuration_n) / sampleRate;
			i++;
		}
	}

	int len = synthDuration_n < outputBufferSize ? synthDuration_n : outputBufferSize;
	for (int i = 0; i < len - 1; i++) {
		outputBuffer[i] = envelope[i] * (sin(2 * M_PI * freq / sampleRate * i) >= 0.0 ? 1.0 : -1.0);
	}

	return 0;

}