#pragma once
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"
#include "bufferAssets.h"
#include "Leandro.h"
#include "Channel.h"
using namespace std;
using namespace smf;

typedef int instrumentCallback(
	float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float lengthInMilliseconds,
	const int velocity,
	const int sampleRate
);

enum class synthType { adsr, additive, fm, karplus, sampling };
enum waveform { sine, square, sawtooth };


class Instrument
{
public:
	synthType type;
	int instrumentID;
	string instrumentName;
	
	virtual instrumentCallback synthFunction; // Instrument callback function: defined by typedef
	
};


typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
	waveform wform1;
	float level1;
	waveform wform2;
	float level2;
	unsigned int buffLength;
	unsigned int sampleRate;
}adsrParams_t;

class ADSRInstrument : public Instrument {
public:
	ADSRInstrument(adsrParams_t* _params);
	~ADSRInstrument() {}

	// Getters
	waveform getWF1() { return wform1; }
	float getWF1Level() { return level1; }
	waveform getWF2() { return wform2; }
	float getWF2Level() { return level2; }
	float getAttack() { return params->tAttack; }
	float getDecay() { return params->tDecay; }
	float getSustainRate() { return params->sustainRate; }
	float getSustainLevel() { return params->sustainLevel; }
	float getRelease() { return params->tRelease; }

	void setParams(adsrParams_t* params);

protected:
	adsrParams_t* params;
	instrumentCallback synthFunction;
	int generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength);

	float* envelope;
	float* release;

	waveform wform1;
	float level1;
	
	waveform wform2;
	float level2;


};

typedef struct {
	std::string envelope_file;
	std::string _name;
	float*** resourceMatrix;
}additiveParams_t;

class AdditiveInstrument : public Instrument {
public:
	AdditiveInstrument(additiveParams_t* _params);
private:
	instrumentCallback synthFunction;
	float* envelope[7];
	int envelopeLength;
	int releaseLength;
	float* release;
};

typedef struct {

}karplusParams_t;


class KarplusInstrument : public Instrument {
public:
	// Parameter declarations for Karplus-Strong algorhythm based instruments here

	KarplusInstrument(karplusParams_t* _params);
	~KarplusInstrument();
};

typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
}samplingParams_t;

class SamplingInstrument : public Instrument {
public:

	SamplingInstrument(samplingParams_t* _params);
	~SamplingInstrument();
};
