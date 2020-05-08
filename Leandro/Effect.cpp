#include "Effect.h"


Effect::Effect() {
	// Effect constructor here. Should set defaults, load data and allocate memory as needed.
}

Effect::~Effect() {
	// Effect destructor here. Should destruct all items and free all allocated memory on stack.
}

int Effect::callback(
	void* soundBuffer,
	const unsigned int soundBufferSize,
	const int sampleRate
) {
	// Data-processing callback here. Recieves input buffer and puts modified data into output buffer.
	return 0;
}