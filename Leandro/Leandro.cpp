#include "Leandro.h"
#include <QWidget>
#include "Leandro.h"
#include "Channel.h"
#include "portaudio.h"
#include "instrument.h"
#include <fstream>
#include <string>

using namespace std;

Leandro::Leandro(QWidget* parent) : QMainWindow(parent)
{
	PaError err = Pa_Initialize();
	if (err != paNoError) throw "Error: PortAudio failed to initialize! %s", Pa_GetErrorText(err);
	this->channelCreationCounter = 0;
	this->currentSample = 0;
	this->activeBuffer = (float*)malloc(ACTIVE_BUFFER_FRAME_SIZE);
	this->debugStream.open("debug.txt");

	/* Open an audio I/O stream. */
	err = Pa_OpenDefaultStream(&(this->stream),
		0,          /* no input channels */
		2,          /* stereo output */
		paFloat32,  /* 32 bit floating point output */
		SAMPLE_RATE,
		paFramesPerBufferUnspecified,
		//5000,
		  /* frames per buffer, i.e. the number
						   of sample frames that PortAudio will
						   request from the callback. Many apps
						   may want to use
						   paFramesPerBufferUnspecified, which
						   tells PortAudio to pick the best,
						   possibly changing, buffer size.*/
		this->callback, /* this is your callback function */
		&(this->callData)); /*This is a pointer that will be passed to
							your callback*/
	if (err != paNoError) throw "Error: PortAudio failed to open stream! %s", Pa_GetErrorText(err);

	this->updateCallbackData();

	// GUI function connections

	QObject::connect(ui.setInstrumentButton, &QPushButton::clicked, this, &Leandro::setInstrumentForActiveChannel);
	

}

Leandro::~Leandro() {
	for (int i = 0; i < this->noteBuffers.size(); i++) free(this->noteBuffers[i]->buffer);
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
	vector<timedBuffer*>* buffers = data->buffers;

	// Local variable declarations
	vector<timedBuffer*> activeBuffers;
	float debugVAR = 0.0;

	for (int channel = 0; channel < data->channels->size(); channel++)
		data->channels->at(channel)->callback(frameCount, data->currentSample, data->buffers, &(data->channels->at(channel)->callData));

	// First, get active note buffers
	for (int i = 0; i < buffers->size(); i++)
		if (buffers->at(i)->buffer[0] != INFINITY)
			activeBuffers.push_back(buffers->at(i));

	for (int frame = 0; frame < frameCount; frame++) // Run through output frames
	{
		data->activeBuffer[frame] = 0;
		float addedFrames = 0.0;
		for (int bufIndex = 0; bufIndex < activeBuffers.size(); bufIndex++) // Run through buffers to check whether there's something there for this frame
		{
			if ((activeBuffers.at(bufIndex)->startingFrame) - (*(data->currentSample) + frame) <= 0) { // If we've reached or surpassed the note's beginning... (note-starting-time agnostic)
				if (activeBuffers.at(bufIndex)->buffer[*(data->currentSample) + frame - (activeBuffers.at(bufIndex)->startingFrame)] != INFINITY) { // If the buffer does not end at this position
					data->activeBuffer[frame] += activeBuffers.at(bufIndex)->buffer[*(data->currentSample) + frame - (activeBuffers.at(bufIndex)->startingFrame)]; // Sum this buffer's position corresponding to analyzed frame to final output buffer
					addedFrames++;
				}
				else { // If the buffer ends, reset it so that it can be re-used
					activeBuffers.at(bufIndex)->buffer[0] = INFINITY;
					activeBuffers.at(bufIndex)->startingFrame = -1;
					activeBuffers.erase(activeBuffers.begin() + bufIndex);
					bufIndex--;
				}
			}
		}
		if (!addedFrames) addedFrames = 1.0;
		*out++ = (1.0 / addedFrames) * data->activeBuffer[frame];  // Left channel
		*out++ = (1.0 / addedFrames) * data->activeBuffer[frame];  // Right channel
		*data->debugStream << (1.0 / addedFrames) * data->activeBuffer[frame] << endl;
	}
	*(data->currentSample) += frameCount;
	return paContinue;
}

void Leandro::addChannel(Channel* newChannel) {
	// Add amount of note buffers to keep channel-buffer proportion
	timedBuffer* tempBuffer;
	for (int i = 0; i < MAX_SIMULTANEOUS_NOTES_PER_CHANNEL; i++) {
		tempBuffer = new timedBuffer;
		tempBuffer->buffer = new float[MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE];
		tempBuffer->buffer[0] = INFINITY;
		tempBuffer->startingFrame = -1;
		this->noteBuffers.push_back(tempBuffer);
	}
	// Append new channel to channel list
	this->activeChannel = newChannel;
	this->channels.push_back(newChannel);
	this->updateCallbackData();
}

void Leandro::destroyChannel(Channel* channel) { // Channel destructor
	// Free used memory and destroy note buffers, up to MAX_SIMULTANEOUS_NOTES_PER_CHANNEL, if there are enough empty ones
	int k = MAX_SIMULTANEOUS_NOTES_PER_CHANNEL;
	for (int i = 0; i < this->noteBuffers.size() && k>0; i++)
		if (this->noteBuffers[i]->buffer[0] == INFINITY)
		{
			free(this->noteBuffers[i]->buffer);
			this->noteBuffers.erase(noteBuffers.begin() + i);
		}
	// Destroy channel and remove from channel list

	this->channels.erase(remove(this->channels.begin(), this->channels.end(), channel), this->channels.end());
	channel->~Channel();
}

void Leandro::addMidiFile(string directory, string filename, bool autoSet) {
	MidiFile* midifile = new MidiFile;
	midifile->read(directory + filename);
	midifile->doTimeAnalysis();
	midifile->linkNotePairs();
	midiTrack* tempTrack;
	Channel* tempChannel;
	int tracks = midifile->getTrackCount();
	for (int track = 0; track < tracks; track++) {
		tempTrack = new midiTrack;
		tempTrack->midifile = midifile;
		tempTrack->trackIndex = track;
		tempTrack->trackName = "Track " + to_string(track) + " - " + filename;
		if (autoSet) {
			tempChannel = new Channel(this->channelCreationCounter,this);
			this->channelCreationCounter++;
			tempChannel->setChannelTrack(tempTrack);
			if (tempChannel->events.size() != 0) this->addChannel(tempChannel);
			else delete tempChannel;
		}
		this->midiTracks.push_back(tempTrack);
	}
	this->midiFiles.push_back(midifile);
	this->updateCallbackData();
	this->updateGUIMidiLists();
}

void Leandro::updateCallbackData() {
	this->callData.activeBuffer = this->activeBuffer;
	this->callData.buffers = &(this->noteBuffers);
	this->callData.currentSample = &(this->currentSample);
	this->callData.channels = &(this->channels);
	this->callData.debugStream = &this->debugStream;
};

void Leandro::addToAvailableAssets(instrumentModel* model) {
	instrumentModels.push_back(model);
	updateAvailableAssetsInGUI();
}

void Leandro::addToAvailableAssets(effectModel* model) {
	effectModels.push_back(model);
	updateAvailableAssetsInGUI();
}


// GUI-related, system-triggered functions

void Leandro::updateAvailableAssetsInGUI() {
	QListWidgetItem* ___qlistwidgetitem;
	ui.instrumentsList->clear();
	for (int i = 0; i < instrumentModels.size(); i++) {
		___qlistwidgetitem = new QListWidgetItem;
		___qlistwidgetitem->setText(QCoreApplication::translate("LeandroClass", instrumentModels.at(i)->instrumentName.c_str(), nullptr));
		ui.instrumentsList->addItem(___qlistwidgetitem);
	}
	ui.effectsList->clear();
	for (int i = 0; i < effectModels.size(); i++) {
		___qlistwidgetitem = new QListWidgetItem;
		___qlistwidgetitem->setText(QCoreApplication::translate("LeandroClass", instrumentModels.at(i)->instrumentName.c_str(), nullptr));
		ui.instrumentsList->addItem(___qlistwidgetitem);
	}
}

void Leandro::updateGUIMidiLists() {
	for (int i = 0; i < channels.size(); i++) {
		channels.at(i)->midiListChannel->clear();
		for (int j = 0; j < midiTracks.size(); j++) {
			char* trackName = new char[(midiTracks.at(j)->trackName.size()) + 1];
			strcpy(trackName, midiTracks.at(j)->trackName.c_str());
			QListWidgetItem* ___qlistwidgetitem = new QListWidgetItem;
			___qlistwidgetitem->setText(QCoreApplication::translate("LeandroClass", trackName, nullptr));
			channels.at(i)->midiListChannel->addItem(___qlistwidgetitem);
		}
	}
}


void Leandro::setActiveChannel(Channel* channel) {
	activeChannel->setActiveButtonChannel->setEnabled(true);
	activeChannel = channel;
	activeChannel->setActiveButtonChannel->setDisabled(true);

	ui.instrumentLayout->removeItem(ui.instrumentLayout->takeAt(0));
	ui.instrumentLayout->addItem(channel->instrumentLayout);

	ui.effectsScrollAreaLayout->removeItem(ui.effectsScrollAreaLayout->takeAt(0));
	ui.effectsScrollAreaLayout->addItem(channel->effectsLayout);
} 

void Leandro::showInstrument(Instrument* instrument) {
	ui.adsrInstrumentFrame->setHidden(true);
	ui.additiveInstrumentFrame->setHidden(true);
	ui.samplingInstrumentFrame->setHidden(true);
	ui.karplusInstrumentFrame->setHidden(true);
	switch (instrument->type) {
		case synthType::adsr:
			ui.adsrInstrumentFrame->setHidden(false);
			ui.waveform1ComboBox->setCurrentIndex(instrument->wa);
			break;
		case synthType::additive:
			ui.additiveInstrumentFrame->setHidden(false);
			
			break;
		case synthType::karplus:
			ui.karplusInstrumentFrame->setHidden(false);
			
			break;
		case synthType::sampling:
			ui.samplingInstrumentFrame->setHidden(false);
			
			break;
		}
}

// GUI-triggered functions

void Leandro::setInstrumentForActiveChannel() {
	Instrument* instrument = nullptr;
	for(int i=0;i<instrumentModels.size();i++)
		if (ui.instrumentsList->currentItem()->text().toStdString() == instrumentModels.at(i)->instrumentName) {
			switch (instrumentModels.at(i)->type) {
			case synthType::adsr:
				instrument = new ADSRInstrument((adsrParams_t*)instrumentModels.at(i)->params);
				break;
			case synthType::additive:
				instrument = new AdditiveInstrument((additiveParams_t*)instrumentModels.at(i)->params);
				break;
			case synthType::karplus:
				instrument = new KarplusInstrument((karplusParams_t*)instrumentModels.at(i)->params);
				break;
			case synthType::sampling:
				instrument = new SamplingInstrument((samplingParams_t*)instrumentModels.at(i)->params);
				break;
			}
			break;
		}
	activeChannel->setChannelInstrument(instrument);
}

void Leandro::addEffectToActiveChannel() {
	Effect* effect = nullptr;
	for (int i = 0; i < effectModels.size(); i++)
		if (ui.effectsList->currentItem()->text().toStdString() == effectModels.at(i)->effectName) {
			switch (effectModels.at(i)->type) {
			case effectType::flanger:
				effect = new FlangerEffect((flangerParams_t*)effectModels.at(i)->params);
				break;
			case effectType::reverb:
				effect = new ReverbEffect((reverbParams_t*)effectModels.at(i)->params);
				break;
			case effectType::vibrato:
				effect = new VibratoEffect((vibratoParams_t*)effectModels.at(i)->params);
				break;
			case effectType::wahwah:
	//			effect = new WahwahEffect((wahwahParams_t*)effectModels.at(i)->params);
				break;
			}
			break;
		}
	activeChannel->addEffectToChannel(effect);
}