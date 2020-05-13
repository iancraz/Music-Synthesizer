#include "Instrument.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>


AdditiveInstrument::AdditiveInstrument(additiveParams_t* _params) {
	std::ifstream file(_params->envelope_file);
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
	file.open(_params->envelope_file);
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
	releaseLength = 0.2 * 44100;
	release = new float[releaseLength];
	int i = 0;
	while (i < releaseLength) {
		release[i] = (float)exp((float)i * log(0.001) / (float)releaseLength);
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


	//TODO: for debug
	//ofstream file("note.txt");

	for (int h = 0; h < outputBufferSize; h++) {
		outputBuffer[h] = 0;
	}
	float maxValue = 0;
	int last;
	for (int k = 0; k < 7; k++) {
		int i = 0;
		while (i < noteDuration_n && i < outputBufferSize) {
			outputBuffer[i] += envelope[k][i] * A0 * (float)sin(2.0 * M_PI * freq * (float)(k + 1) / (float)sampleRate * (float)i);
			maxValue = abs(outputBuffer[i]) > maxValue ? abs(outputBuffer[i]) : maxValue;
			i++;
		}
		last = i;
		while (i < noteDuration_n + releaseLength && i < outputBufferSize) {
			outputBuffer[i] += envelope[k][last-1] * release[i - noteDuration_n] * (float)sin(2.0 * M_PI * freq * (float)(k + 1) / (float)sampleRate * (float)i);
			maxValue = abs(outputBuffer[i]) > maxValue ? abs(outputBuffer[i]) : maxValue;
			i++;
		}
		last = i;
	}
	//for (int j = 0; j < last - 1; j++) {
	//	outputBuffer[j] /= maxValue;
	//	file << outputBuffer[j] << std::endl;
	//}
	//file.close();
	outputBuffer[last - 1] = INFINITY;
	return 0;
}