#include "Leandro.h"
#include <QWidget>
#include "Leandro.h"
#include "Channel.h"
#include "portaudio.h"

using namespace std;


Leandro::Leandro(QWidget* parent) : QMainWindow(parent)
{
	this->currentSample = 0;
	this->activeBuffer = (float*)malloc(ACTIVE_BUFFER_FRAME_SIZE);
	this->callData.activeBuffer = this->activeBuffer;
	this->callData.buffers = &(this->noteBuffers);
	this->callData.currentSample = &(this->currentSample);
	for (int channel = 0; channel < this->channels.size(); channel++)
		this->callData.channels->push_back(this->channels.at(channel));

	PaError err;
	/* Open an audio I/O stream. */
	err = Pa_OpenDefaultStream(&(this->stream),
		0,          /* no input channels */
		2,          /* stereo output */
		paFloat32,  /* 32 bit floating point output */
		SAMPLE_RATE,
		256,        /* frames per buffer, i.e. the number
							of sample frames that PortAudio will
							request from the callback. Many apps
							may want to use
							paFramesPerBufferUnspecified, which
							tells PortAudio to pick the best,
							possibly changing, buffer size.*/
		this->callback, /* this is your callback function */
		&(this->callData)); /*This is a pointer that will be passed to
							your callback*/
	if (err != paNoError) throw "Error: PortAudio failed to open stream!";
}



Leandro::~Leandro() {
	for (int i = 0; i < this->noteBuffers.size(); i++) free(this->noteBuffers[i].buffer);
}

int Leandro::callback( // Call all channel callbacks, sum all dynamic buffers and output results to stream
	const void* input,
	void* output,
	unsigned long frameCount,
	const PaStreamCallbackTimeInfo* timeInfo,
	PaStreamCallbackFlags statusFlags,
	void* userData) {

	// Void pointer casts
	float* out = (float*)output;
	callbackData* data = (callbackData*)userData;
	vector<timedBuffer>* buffers = (data->buffers);

	// Local variable declarations
	vector<timedBuffer*> activeBuffers;

	for (int channel = 0; channel < data->channels->size(); channel++)
		data->channels->at(channel).callback(frameCount, data->currentSample, data->buffers, &(data->channels->at(channel).callData));


	// First, get active note buffers
	for (int i = 0; i < buffers->size(); i++)
		if (buffers->at(i).buffer[0] != INFINITY)
			activeBuffers.push_back(&buffers->at(i));

	for (unsigned int frame = 0; frame < frameCount; frame++) // Run through output frames
	{
		for (int bufIndex = 0; bufIndex < activeBuffers.size(); bufIndex++) // Run through buffers to check whether there's something there for this frame
		{
			if (activeBuffers.at(bufIndex)->startingFrame > 0) { // Check validity of starting frame
				if ((activeBuffers.at(bufIndex)->startingFrame) - (*(data->currentSample) + frame) <= 0) // If we've reached or surpassed the note's beginning... (note-starting-time agnostic)
					if (activeBuffers.at(bufIndex)->buffer[*(data->currentSample) + frame - (activeBuffers.at(bufIndex)->startingFrame)] != INFINITY) // If the buffer does not end at this position
						data->activeBuffer[frame] += activeBuffers.at(bufIndex)->buffer[*(data->currentSample) + frame - (activeBuffers.at(bufIndex)->startingFrame)]; // Sum this buffer's position corresponding to analyzed frame to final output buffer
					else { // If the buffer ends, reset it so that it can be re-used
						activeBuffers.at(bufIndex)->buffer[0] = INFINITY;
						activeBuffers.at(bufIndex)->startingFrame = -1;
					}
			}
		}
		*out++ = data->activeBuffer[frame];  // Left channel
		*out++ = data->activeBuffer[frame];  // Right channel
	}
	data->currentSample += frameCount;
	return paContinue;
}

void Leandro::addChannel(Channel newChannel) {
	// Add amount of note buffers to keep channel-buffer proportion
	timedBuffer tempBuffer;
	for (int i = 0; i < MAX_SIMULTANEOUS_NOTES_PER_CHANNEL; i++) {
		tempBuffer.buffer = (float*)malloc(MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE * sizeof(float));
		tempBuffer.buffer[0] = INFINITY;
		tempBuffer.startingFrame = -1;
		this->noteBuffers.push_back(tempBuffer);
	}
	// Append new channel to channel list
	this->channels.push_back(newChannel);
	this->callData.channels->push_back(this->channels.back());
}

void Leandro::destroyChannel(Channel channel) { // Channel destructor
	// Free used memory and destroy note buffers, up to MAX_SIMULTANEOUS_NOTES_PER_CHANNEL, if there are enough empty ones
	int k = MAX_SIMULTANEOUS_NOTES_PER_CHANNEL;
	for (int i = 0; i < this->noteBuffers.size() && k>0; i++)
		if (this->noteBuffers[i].buffer[0] == INFINITY)
		{
			free(this->noteBuffers[i].buffer);
			this->noteBuffers.erase(noteBuffers.begin() + i);
		}
	// Destroy channel and remove from channel list

	this->channels.erase(remove(this->channels.begin(), this->channels.end(), channel), this->channels.end());
	channel.~Channel();
}

void Leandro::addMidiFile(string directory, string filename) {
	MidiFile midifile;
	midifile.read(directory + filename);
	midifile.doTimeAnalysis();
	midifile.linkNotePairs();
	midiTrack temp;
	this->midiFiles.push_back(midifile);
	temp.midifile = &(this->midiFiles.back());
	int tracks = midifile.getTrackCount();
	for (int track = 0; track < tracks; track++) {
		temp.trackIndex = track;
		temp.trackName = "Track " + to_string(track) + " - " + filename;
	}
	this->midiTracks.push_back(temp);
}


