#pragma once
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"
#include "bufferAssets.h"
#include <QtWidgets/QFrame>
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



class Instrument
{
public:
	synthType type;
	int instrumentID;
	string instrumentName;
	virtual instrumentCallback synthFunction; // Instrument callback function: defined by typedef
	QFrame * instrumentFrame;
};


typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
	unsigned int buffLength;
	unsigned int sampleRate;
}adsrParams_t;

class ADSRInstrument : public Instrument {
public:
	ADSRInstrument(adsrParams_t* _params);
	~ADSRInstrument() {}
	void setParams(adsrParams_t* params);

protected:
	adsrParams_t* params;
	instrumentCallback synthFunction;
	int generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength);

	float* envelope;
	float* release;
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
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
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
