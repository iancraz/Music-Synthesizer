#include "Additive.h"
#include "Leandro.h"
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
		const int keyNumber,
		const float lengthInMilliseconds,
		const int velocity,
		const int sampleRate
) {
	int noteDuration_n = (int)(lengthInMilliseconds * 1000 * SAMPLE_RATE);
	int nAttack = params.tAttack * SAMPLE_RATE;
	int nDecay = (int)(params.tDecay * SAMPLE_RATE);
	int nRelease = (int)(params.tRelease * SAMPLE_RATE);
	int synthDuration_n = (int)((lengthInMilliseconds * 1000 + params.tRelease) * SAMPLE_RATE);
	float A0 = (float)velocity / 127.0;
	float* envelope = nullptr;
	envelope = new float[synthDuration_n];

	float freq = 440.0 * pow(2, (keyNumber - 69) / 12);

	int i = 0;
	if (noteDuration_n > nAttack + nDecay) {
		while (i < nAttack && i < outputBufferSize)
		{
			envelope[i] = (params.k * A0) / params.tAttack * (float)i / SAMPLE_RATE;
			i++;
		}
		while (i < nAttack + nDecay && i < outputBufferSize) {
			envelope[i] = params.k * A0 - A0 * (params.k - 1) / params.tDecay * (float)(i - (nAttack + nDecay)) / SAMPLE_RATE;
			i++;
		}
		int nSustain = noteDuration_n - (nAttack + nDecay);
		while (i < nAttack + nDecay + nSustain && i < outputBufferSize) {
			if (A0 - params.sustainRate * (float)(i - (nAttack + nDecay)) / SAMPLE_RATE > 0)
				envelope[i] = A0 - params.sustainRate * (float)(i - (nAttack + nDecay)) / SAMPLE_RATE;
			else
				break;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < nAttack + nDecay + nRelease && i < outputBufferSize) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - (nAttack + nDecay + nSustain)) / SAMPLE_RATE;
			i++;
		}
	}
	else if (noteDuration_n > nAttack && noteDuration_n < nAttack + nDecay) {
		while (i < nAttack) {
			envelope[i] = (float)i / SAMPLE_RATE * (params.k * (float)A0) / params.tAttack;
			i++;
		}
		while (i < (noteDuration_n)) {
			envelope[i] = params.k * A0 - A0 * (params.k - 1) / params.tDecay * (float)(i - nAttack) / SAMPLE_RATE;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < noteDuration_n + nDecay) {
			envelope[i] = Ar - Ar / params.tRelease * (float)(i - noteDuration_n) / SAMPLE_RATE;
			i++;
		}
	}
	else if (noteDuration_n < nAttack) {
		while (i < noteDuration_n) {
			envelope[i] += (float)i / SAMPLE_RATE * (params.k * (float)A0) / params.tAttack;
			i++;
		}
		float Ar = envelope[i - 1];
		while (i < noteDuration_n + nRelease) {
			envelope[i] += Ar - Ar / params.tRelease * (float)(i - noteDuration_n) / SAMPLE_RATE;
			i++;
		}
	}

	int len = synthDuration_n < outputBufferSize ? synthDuration_n : outputBufferSize;
	for (int i = 0; i < len - 1; i++) {
		outputBuffer[i] = envelope[i] * (sin(2 * M_PI * freq / SAMPLE_RATE * i) >= 0.0 ? 1.0 : -1.0);
	}

	return 0;

}