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

karplusInstrument::karplusInstrument() {
	// Constructor class for karplusInstrument. Should set defaults, load files and allocate memory as needed.
}

karplusInstrument::~karplusInstrument() {
	// Destructor class for karplusInstrument. Should destroy all elements and free all allocated memory on stack.
}




//	SAMPLING CLASS FUNCTIONS

samplingInstrument::samplingInstrument() {
	// Constructor class for samplingInstrument. Should set defaults, load files and allocate memory as needed.
}

samplingInstrument::~samplingInstrument() {
	// Destructor class for samplingInstrument. Should destroy all elements and free all allocated memory on stack.
}


