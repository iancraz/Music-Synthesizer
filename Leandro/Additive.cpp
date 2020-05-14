#include "Additive.h"
#include "Leandro.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include "rapidcsv.h"


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

AdditiveInstrument::AdditiveInstrument(additiveParams_t params, unsigned int bufferLength) {
	instrumentName = params.name;
	firstKey = params.firstKey;
	lastKey = params.lastKey;
	harmonicsCount = params.harmonicsCount;
	envelopeLengths = params.envelopeLengths;
	octavesEnvelopes = params.octavesEnvelopes;
}

void AdditiveInstrument::synthNote(float* outputBuffer,
								   const unsigned int outputBufferSize,
								   int keyNumber,
								   const float lengthInMilisecnds,
								   const int velocity,
								   const int sampleRate) {
	int noteDuration_n = lengthInMilisecnds / 1000.0 * sampleRate;
	int synthDuration = (noteDuration_n < outputBufferSize) ? noteDuration_n : outputBufferSize;
	float A0 = (float)velocity / 127.0;

	while (keyNumber < firstKey)
		keyNumber += 12;

	while (keyNumber > lastKey) {
		keyNumber -= 12;
	}

	float freq = 440.0 * pow(2.0, ((float)keyNumber - 69.0) / 12.0);
	float maxValue = 1;
	// determinar la cotava a utilizar 
	int octave = (keyNumber / 12) - 2;
	int last;


	for (int i = 0; i < outputBufferSize; i++) {
		outputBuffer[i] = 0;
	}

	for (int k = 0; k < harmonicsCount; k++) {
		int i = 0;
		while (i < envelopeLengths[octave] && i < outputBufferSize) {
			outputBuffer[i] += octavesEnvelopes[octave][k][i] * A0 * (float)sin(2.0 * M_PI * freq * (float)(k + 1) / (float)sampleRate * (float)i);
			maxValue = abs(outputBuffer[i]) > maxValue && outputBuffer[i] != 0.0 ? abs(outputBuffer[i]) : maxValue;
			i++;
		}
		last = i;
	}
	for (int j = 0; j < last - 1; j++) {
		outputBuffer[j] /= maxValue;
		//file << outputBuffer[j] << std::endl;
	}
	//file.close();
	outputBuffer[last - 1] = INFINITY;
}

additiveParams_t AdditiveInstrument::parseAdditiveJson(Json::Value _data) {
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

vector<float*> AdditiveInstrument::parseEnvelopeFile(std::string path, vector<int>* envelopesLengths) {
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
