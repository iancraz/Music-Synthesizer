#pragma once
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"

typedef int effectCallback(
	void* soundBuffer,
	const unsigned int soundBufferSize,
	unsigned int sampleRate
);

class Effect
{
public:
	// Effect parameters here

	Effect();
	~Effect();
	effectCallback callback;
};

class reverbEffect : public Effect
{
};