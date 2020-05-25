#include "Channel.h"
#include "Leandro.h"
#include "MidiFile.h"
#include "ui_Leandro.h"
#include <string>
using namespace std;
using namespace smf;

Channel::Channel(int channelCreationCounter, Leandro* _program) {
	this->program = _program;

	// Variable initialization
	this->ID = channelCreationCounter;
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

Channel::~Channel() {
	
}

bool Channel::operator== (Channel const& channel) {
	if (this->ID == channel.ID) return true;
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

	while (true) {
		float* buffer = nullptr;
		bool emptyBufferFound = false;
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
			if (!emptyBufferFound)
			{ // If there were no empty buffers, replace the oldest one with the new data
				__int64 minStartFrame = 9999999999999;
				int bufferToReplace = 0;
				for (int j = 0; buffer == nullptr && j < buffers->size(); j++) // Run a loop through the current note buffers
					if (buffers->at(j)->startingFrame < minStartFrame) // Look for the oldest buffer
					{
						minStartFrame = buffers->at(j)->startingFrame;
						bufferToReplace = j;
					}
				buffers->at(bufferToReplace)->buffer[0] = INFINITY;
				buffer = buffers->at(bufferToReplace)->buffer; // Select this buffer to save the result of the event processing
				buffers->at(bufferToReplace)->startingFrame = currentEvent.startSample; // Remember when to play this buffer
			}

			// First, call the instrument function

			if (data->instrument) {
				data->instrument->synthFunction(buffer, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, currentEvent.note, currentEvent.durSeconds, currentEvent.velocity, SAMPLE_RATE);
				for (int i = 0; i < (data->effects->size()); i++)
					data->effects->at(i)->callback(buffer, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
				
				for (unsigned int i = 0; buffer[i] != INFINITY; i++) {
					buffer[i] = this->volume * buffer[i];
				}
			}
			
			/*
			int s = 0;
			int c = 0;
			bool noteStarted = false;
			while (buffer[s] != INFINITY) {
				if (buffer[s] > 0.5) noteStarted=true;
				if (buffer[s] < 0.005&& buffer[s] > -0.005) c++;
				if (buffer[s] > 0.005 || buffer[s] < -0.005) c=0;
				if (c > 1000 && noteStarted == true) {
					buffer[s] = INFINITY;
					break;
				}
				s++;
			}
			*/
			// Then, iterate through the vector of effects, calling each one of them

			
		}
		else break; // If the next note is out of scope, exit the while loop: no need for processing whole track at this point
	}
}


void Channel::destroyThisChannelFromProgram() {
	program->destroyChannel(this);
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
			this->originalEvents.push(tempEvent);
		}
	}
	this->updateCallbackData();
}

void Channel::setChannelInstrument(Instrument* instrument) {
	this->instrument = instrument;	
	this->updateCallbackData();
}

void Channel::removeChannelInstrument() {
	this->instrument->~Instrument();
	delete(this->instrument);
	this->instrument = nullptr;
}

void Channel::addEffectToChannel(Effect* effect) {
	for (int i = 0; i < effects.size(); i++) {
		if (effects.at(i)->type == effect->type)
			effects.erase(effects.begin() + i);
	}
	
	this->effects.push_back(effect);
	this->updateCallbackData();
}
