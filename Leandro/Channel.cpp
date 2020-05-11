#include "Channel.h"
#include "Leandro.h"
#include "MidiFile.h"

using namespace std;
using namespace smf;

Channel::Channel(__int64 currentSample) {
	// Variable initialization
	this->creationTime = currentSample;
	this->volume = 1.0;
	this->keyboard = false;

	// Pointers init to nullptr
	this->instrument = nullptr;
	this->currentMidiTrack = new midiTrack;
	this->currentMidiTrack->midifile = nullptr;
	this->currentMidiTrack->trackIndex = NULL;
	this->currentMidiTrack->trackName = "";

	//Clear vectors
	this->effects.clear();
	while (!this->events.empty()) this->events.pop();

	// Callback update
	this->updateCallbackData();
}

void Channel::updateCallbackData() { // Function to be called at the end of every setter
	this->callData.effects = &(this->effects);
	this->callData.instrument = this->instrument;
	this->callData.currentMidiTrack = this->currentMidiTrack;
	this->callData.volume = &(this->volume);
	this->callData.events = &(this->events);
}

Channel::~Channel() {}

bool Channel::operator== (Channel const& channel) {
	if (this->creationTime == channel.creationTime) return true;
	else return false;
}

void Channel::callback(	// Take midi file, select events in timeframe, synthesize notes into buffer.
	unsigned long frameCount,
	const __int64* currentSample,
	vector<timedBuffer*>* buffers,
	channelCallbackData* data) {
	// Void data type casting

	// Local variable declarations
	midiEvent currentEvent;
	bool emptyBufferFound = false;
	float* buffer = nullptr;

	while (true) {
		float* buffer = nullptr;
		if (!(data->events->size() > 0)) break;
		if (data->events->front().startSample < *currentSample + frameCount) { // If the event in front of the midi track event queue is before the end of this timeframe
			currentEvent = data->events->front(); // Set this event as the event to process in this iteration
			data->events->pop(); // Remove the event from the queue

			for (int i = 0; buffer == nullptr && i < buffers->size(); i++) // Run a loop through the current note buffers
				if (buffers->at(i)->buffer[0] == INFINITY) { // If the buffer is free
					buffer = buffers->at(i)->buffer; // Select this buffer to save the result of the event processing
					buffers->at(i)->startingFrame = currentEvent.startSample; // Remember when to play this buffer
					emptyBufferFound = true;
				}
			if (!emptyBufferFound) throw "Could not save note: no free buffers left! MAX_SIMULTANEOUS_NOTES_PER_BUFFER should be higher";

			// First, call the instrument function

			data->instrument->synthFunction(buffer, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, currentEvent.note, currentEvent.durSeconds, currentEvent.velocity, SAMPLE_RATE);
			// Then, iterate through the vector of effects, calling each one of them

			for (int i = 0; i < (data->effects->size()); i++)
				data->effects->at(i)->callback(buffer, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
		}
		else break; // If the next note is out of scope, exit the while loop: no need for processing whole track at this point
	}
}

// Setters

void Channel::setChannelTrack(midiTrack* miditrack) {
	const int track = miditrack->trackIndex;
	const MidiFile* file = (MidiFile*)miditrack->midifile;
	this->currentMidiTrack = miditrack;

	midiEvent tempEvent;

	for (int event = 0; event < (*file)[track].size(); event++) {
		if ((*file)[track][event].isNoteOn()) {
			tempEvent.startSample = ((*file)[track][event].seconds) * SAMPLE_RATE;
			tempEvent.durSample = ((*file)[track][event].getDurationInSeconds()) * SAMPLE_RATE;
			tempEvent.durSeconds = ((*file)[track][event].getDurationInSeconds());
			tempEvent.eventID = event;
			tempEvent.note = (*file)[track][event].getKeyNumber();
			tempEvent.velocity = (*file)[track][event].getVelocity();

			this->events.push(tempEvent);
		}
	}
	this->updateCallbackData();
}

void Channel::setChannelInstrument(Instrument* instrument) {
	this->instrument = instrument;
	this->updateCallbackData();
}

void Channel::addEffectToChannel(Effect* effect) {
	this->effects.push_back(effect);
	this->updateCallbackData();
}

void Channel::setVolume(float vol) {
	if (vol <= 1.0 && vol >= 0)
		this->volume = vol;
	this->updateCallbackData();
}

void Channel::setKeyboard(bool keyboard) {
	this->keyboard = keyboard;
	this->updateCallbackData();
}