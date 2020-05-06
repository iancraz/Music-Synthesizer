#pragma once
//#include "Channel.h"
#include "Leandro.h"
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"
#include "Instrument.h"
#include "Effect.h"
#include "midiAssets.h"
#include "bufferAssets.h"
#include <list>
#include <queue>

using namespace std;

typedef struct {
	midiTrack* currentMidiTrack;
	Instrument* instrument;
	vector<Effect>* effects;
	float* volume;
	queue<midiEvent>* events;
}channelCallbackData;

typedef void channelCallback(	// Take midi file, select events in timeframe, synthesize notes into buffer.
	unsigned long frameCount,
	const __int64* currentSample,
	vector<timedBuffer>* buffers,
	//vector<timedBuffer>* buffers,
	channelCallbackData* data
);

class Channel {
public:
	__int64 creationTime;
	//MidiFile* currentMidiFile; // Midi file in which this channel's track lives
	midiTrack* currentMidiTrack;
	//int trackIndex; // Index in the midi file, as in: track=midifile[index]
	float volume; // Volume multiplier between 0 and 1
	Instrument instrument; // Instance of instrument
	vector<Effect> effects; // This channel's stack of effects
	bool keyboard; // True if input is directly through keyboard
	channelCallbackData callData; // Data pointers to use callback
	queue<midiEvent> events; // Queue of events in the midi track the channel's currently playing

	Channel(__int64 currentSample);
	~Channel();

	bool operator== (Channel const& channel);

	channelCallback callback;

	int setChannelTrack(midiTrack* midiTrack);
};