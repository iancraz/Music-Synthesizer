#include "Instrument.h"

#define MAX_LOOP_TIME (0.370)
#define MIN_LOOP_TIME (0.)



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
