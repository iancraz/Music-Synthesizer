#include "Instrument.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "rapidcsv.h"

AdditiveInstrument::AdditiveInstrument(additiveParams_t * params) {
	instrumentName = params->name;
	firstKey = params->firstKey;
	lastKey = params->lastKey;
	harmonicsCount = params->harmonicsCount;
	envelopeLengths = params->envelopeLengths;
	octavesEnvelopes = params->octavesEnvelopes;
	int octavesCount = params->octavesEnvelopes.size();


	envelopes = new float** [octavesCount];
	for (int i = 0; i < octavesCount; i++) {
		envelopes[i] = new float* [harmonicsCount];
		for (int j = 0; j < harmonicsCount; j++) {
			envelopes[i][j] = new float[envelopeLengths[i]];
			for (int k = 0; k < envelopeLengths[i]; k++) {
				envelopes[i][j][k] = (float)octavesEnvelopes[i][j][k];
			}
		}
	}
}

int
AdditiveInstrument::synthFunction(float* outputBuffer,
								  const unsigned int outputBufferSize,
								  int keyNumber,
								  const float lengthInSeconds,
								  const int velocity,
								  const int sampleRate) {
	int noteDuration_n = lengthInSeconds * sampleRate;
	int synthDuration = (noteDuration_n < outputBufferSize) ? noteDuration_n : outputBufferSize;
	float A0 = (float)velocity / 127.0;

	int firstOctave = (int)(firstKey / 12) - 1;

	while (keyNumber < firstKey)
		keyNumber += 12;

	while (keyNumber > lastKey) {
		keyNumber -= 12;
	}

	float freq = 440.0 * pow(2.0, ((float)keyNumber - 69.0) / 12.0);
	float maxValue = 1;
	// determinar la cotava a utilizar 

	int last;
	int octave = (int)(keyNumber / 12) - 1 - firstOctave;

	for (int i = 0; i < outputBufferSize; i++) {
		outputBuffer[i] = 0;
	}

	for (int k = 0; k < harmonicsCount; k++) {
		int i = 0;
		while (i < noteDuration_n && i < outputBufferSize && i < envelopeLengths[octave]) {
			outputBuffer[i] += envelopes[octave][k][i] * (float)sin(2.0 * M_PI * freq * (float)(k + 1) / (float)sampleRate * (float)i);
			maxValue = abs(outputBuffer[i]) > maxValue && outputBuffer[i] != 0.0 ? abs(outputBuffer[i]) : maxValue;
			i++;
		}
		last = i;
	}
	for (int j = 0; j < last - 1; j++) {
		outputBuffer[j] = outputBuffer[j] * A0 / maxValue;
		//file << outputBuffer[j] << std::endl;
	}
	//file.close();
	outputBuffer[last - 1] = INFINITY;
	return 0;
}

additiveParams_t AdditiveInstrument::parseAdditiveJson(Json::Value data) {
	unsigned int minKey = data["min-key"].asUInt();
	unsigned int maxKey = data["max-key"].asUInt();
	unsigned int firstOctave = data["first-octave"].asUInt();
	unsigned int octavesCount = data["octaves-count"].asUInt();
	unsigned int harmonicsCount = data["n-harmonics"].asUInt();


	std::vector<std::string> listOfFiles;
	Json::Value files = data["files"];
	int size = files.size();
	for (int i = 0; i < files.size(); i++) {
		listOfFiles.push_back(files[to_string(i)].asCString());
	}

	vector<int> envelopesLengths;

	vector<vector<float*>> octavesVectors;
	for (int i = 0; i < octavesCount; i++) {
		vector<float*> temp;
		octavesVectors.push_back(parseEnvelopeFile(listOfFiles[i], &envelopesLengths));
	}

	additiveParams_t ret;
	ret.firstKey = minKey;
	ret.lastKey = maxKey;
	ret.envelopeLengths = envelopesLengths;
	ret.harmonicsCount = harmonicsCount;
	ret.octavesCount = octavesCount;
	ret.octavesEnvelopes = octavesVectors;
	return ret;
}

vector<float*>
AdditiveInstrument::parseEnvelopeFile(std::string path, vector<int>* envelopesLengths) {
	rapidcsv::Document doc(path, rapidcsv::LabelParams(-1, -1), rapidcsv::SeparatorParams(';'));
	unsigned int colCount = doc.GetColumnCount();
	unsigned int rowLength = doc.GetRowCount();
	envelopesLengths->push_back(rowLength);
	vector<float*> ret;
	for (int i = 0; i < colCount; i++) {
		float* tempbuff = new float[rowLength];
		for (int j = 0; j < rowLength; j++) {
			float val = (float)doc.GetCell<float>(i, j);
			tempbuff[j] = val;
		}
		ret.push_back(tempbuff);
	}
	return ret;
}

void AdditiveInstrument::setHarmonicFactor(int index, float value) {
	if (index < harmonicsCount) {
		harmonicFactors[index] = value;
	}
}

