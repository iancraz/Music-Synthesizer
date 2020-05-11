#include "Additive.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <boost/algorithm/string.hpp>

void ADSRInstrument::setParams(adsrParams_t* _params) {
	if (_params->tAttack < 15.0 && _params->tDecay < 15.0 && _params->sustainLevel <= 1.0 && _params->sustainRate <= 1.0 && _params->tRelease < 15 && _params->k < 5.0 && _params->tAttack > 0.0 && _params->tDecay > 0.0 && _params->sustainLevel > 0.0 && _params->sustainRate > 0.0 && _params->tRelease > 0.0 && _params->k > 0.0)
		params = *_params;
	else
		throw "Error! ADSR parameters are invalid";
}

ADSRInstrument::ADSRInstrument(adsrParams_t* _params, const unsigned int buffLength, const unsigned int sampleRate) {
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

int ADSRInstrument::generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength) {
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
		envelope[i] = ((1 - sustainLevel) * exp((-2 * 3.1415 / nDecay) * (-nAttack + i)));
		i++;
	}
	while (sustainLevel > 0.0 && !reachedEnd) {
		if (i - (nAttack + nDecay) >= 0 || i == buffLength)
			reachedEnd = true;
		else envelope[i] = sustainLevel - sustainRate * (i - (nAttack + nDecay));

		i++;
	}

	unsigned long k = 0;
	reachedEnd = false;
	while (k < nRelease) {
		release[k] = exp((-2 * 3.1415 / nRelease) * k);
		k++;
	}

	return i - 1;
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
	int nRelease = sampleRate * params.tRelease;
	float velocityFactor = (float)velocity / 127.0;
	while (envelope[j] >= 0 && j < outputBufferSize) {
		if (j < nPressedLength)
			outputBuffer[j] = envelope[j] * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
		else {
			if (finalSustainValue == 0.0) finalSustainValue = outputBuffer[j - 1];
			if (j - nPressedLength < nRelease)
				outputBuffer[j] = (finalSustainValue * release[j - nPressedLength]) * velocityFactor * (sin(2 * M_PI * (freq / (float)sampleRate) * j) > 0 ? 1.0 : -1.0);
			else break;
		}
		j++;
	}
	outputBuffer[j] = INFINITY;
	return 0;
}

AdditiveInstrument::AdditiveInstrument(std::string fileName, std::string _name) {
	std::ifstream file(fileName);
	// count lines
	int count = 0;
	if (file.is_open()) {
		std::string str;
		while (std::getline(file, str)) {
			count++;
		}
		file.close();
	}
	envelopeLength = count;
	// allocate memory
	for (int i = 0; i < 7; i++) {
		envelope[i] = new float[envelopeLength];
	}
	file.open(fileName);
	if (file.is_open()) {
		std::string line;
		int i = 0;
		while (std::getline(file, line)) {
			std::vector<std::string> parts;
			split(parts, line, boost::is_any_of("\t"));
			for (int k = 0; k < 7; k++) {
				envelope[k][i] = std::stof(parts[k]);
			}
			i++;
		}
	}
	releaseLength = 0.0005 * 44100;
	release = new float[releaseLength];
	int i = 0;
	while (i < releaseLength) {
		release[i] = exp(i * log(0.01) / releaseLength);
		i++;
	}
}

int AdditiveInstrument::synthFunction(float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float lengthInSeconds,
	const int velocity,
	const int sampleRate) {
	int noteDuration_n = lengthInSeconds * sampleRate;
	int synthDuration = (noteDuration_n < outputBufferSize) ? noteDuration_n : outputBufferSize;
	float A0 = pow((float)velocity / 127.0, 1.0 / 7.0);
	float freq = 440.0 * pow(2.0, ((float)keyNumber - 69.0) / 12.0);

	for (int h = 0; h < outputBufferSize; h++) {
		outputBuffer[h] = 0;
	}

	int last;
	for (int k = 0; k < 7; k++) {
		int i = 0;
		while (i < noteDuration_n && i < outputBufferSize) {
			outputBuffer[i] += envelope[k][i] * A0 * (float)sin(2.0 * M_PI * freq * (float)(k + 1) / (float)sampleRate * (float)i);
			i++;
		}
		last = i;
		while (i < noteDuration_n + releaseLength && i < outputBufferSize) {
			outputBuffer[i + noteDuration_n] += release[i - noteDuration_n] * (float)sin(2.0 * M_PI * freq * (float)(k + 1) / (float)sampleRate * (float)i);
			i++;
		}
		last = i;
	}
	outputBuffer[last - 1] = INFINITY;
	return 0;
}