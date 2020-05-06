#pragma once
#include <string>
#include "midifile.h"

using namespace std;
using namespace smf;

typedef struct {
	MidiFile* midifile;
	int trackIndex;
	string trackName;
}midiTrack;

typedef struct {
	__int64 startSample;
	int durSample;
	unsigned int note;
	float durSeconds;
	unsigned int eventID;
	unsigned int velocity;
}midiEvent;