#pragma once
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"
#include "bufferAssets.h"

using namespace std;
using namespace smf;

typedef int instrumentCallback(
	float* outputBuffer,
	const unsigned int outputBufferSize,
	int keyNumber,
	float lengthInMilliseconds,
	int velocity,
	unsigned int sampleRate);

enum class synthType { additive, fm, karplus, sampling };

class Instrument
{
public:
	synthType type;
	int instrumentID;
	string instrumentName;
	virtual instrumentCallback synthFunction; // Instrument callback function: defined by typedef
};


class karplusInstrument : public Instrument {
public:
	// Parameter declarations for Karplus-Strong algorhythm based instruments here

	karplusInstrument();
	~karplusInstrument();
};

class samplingInstrument : public Instrument {
public:

	samplingInstrument();
	~samplingInstrument();
};