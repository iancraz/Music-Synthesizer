#include "Instrument.h"

int Instrument::synthFunction(
	float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float lengthInMilliseconds,
	const int velocity,
	const int sampleRate) {
	//The synth function for karplus instruments here
	return 0;
}

// KARPLUS-STRONG CLASS FUNCTIONS

KarplusInstrument::KarplusInstrument(karplusParams_t* _params) {
	// Constructor class for KarplusInstrument. Should set defaults, load files and allocate memory as needed.
}

KarplusInstrument::~KarplusInstrument() {
	// Destructor class for KarplusInstrument. Should destroy all elements and free all allocated memory on stack.
}

//	SAMPLING CLASS FUNCTIONS

SamplingInstrument::SamplingInstrument(samplingParams_t* _params) {
	// Constructor class for SamplingInstrument. Should set defaults, load files and allocate memory as needed.
}

SamplingInstrument::~SamplingInstrument() {
	// Destructor class for SamplingInstrument. Should destroy all elements and free all allocated memory on stack.
}