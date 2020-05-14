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
	if (activeChannel) activeChannel->setActiveButtonChannel->setEnabled(true);
	activeChannel = channel;
	activeChannel->setActiveButtonChannel->setDisabled(true);

	updateActiveAssetsBay();
} 

void Leandro::updateActiveAssetsBay() {
	ui.adsrInstrumentFrame->setHidden(true);
	ui.additiveInstrumentFrame->setHidden(true);
	ui.samplingInstrumentFrame->setHidden(true);
	ui.karplusInstrumentFrame->setHidden(true);
	ui.flangerEffectFrame->setHidden(true);
	ui.reverbEffectFrame->setHidden(true);
	ui.vibratoEffectFrame->setHidden(true);
	ui.wahwahEffectFrame->setHidden(true);
	ui.eq8Frame->setHidden(true);
	
	if (activeChannel->instrument) showInstrument(activeChannel->instrument);
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++)
	{
		showEffect(activeChannel->effects.at(effIndex)); // TODO PRIORITY add effect order: IDEA: implement function that reorganizes effects using replaceWidget function
	}

}

void Leandro::showInstrument(Instrument* instrument) {
	

	ADSRInstrument* adsrinst = (ADSRInstrument*)instrument;
	AdditiveInstrument* additiveinst = (AdditiveInstrument*)instrument;
	SamplingInstrument* samplinginst = (SamplingInstrument*)instrument;
	KarplusInstrument* karplusinst = (KarplusInstrument*)instrument;



	switch (instrument->type) {
		case synthType::adsr:
			
			ui.adsrInstrumentFrame->setHidden(false);
			ui.waveform1ComboBoxADSR->setCurrentIndex(adsrinst->getWF1());
			ui.waveform2ComboBoxADSR->setCurrentIndex(adsrinst->getWF2());
			ui.levelWF1DialADSR->setValue((int)(adsrinst->getWF1Level() * 100));
			ui.levelWF2DialADSR->setValue((int)(adsrinst->getWF2Level() * 100));
			ui.attackDialADSR->setValue((int)(adsrinst->getAttack() * 1000));
			ui.decayDialADSR->setValue((int)(adsrinst->getDecay() * 1000));
			ui.sustainRateDialADSR->setValue((int)(adsrinst->getSustainRate()*1000));
			ui.sustainLevelDialADSR->setValue((int)(adsrinst->getSustainLevel() * 100));
			ui.releaseDialADSR->setValue((int)(adsrinst->getRelease() * 1000));
			ui.attackDialADSR->setValue((int)(adsrinst->getAttack() * 1000));
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

void Leandro::showEffect(Effect* effect) {
	FlangerEffect* flanger = (FlangerEffect*)effect;
	ReverbEffect* reverb = (ReverbEffect*)effect;
	VibratoEffect* vibrato = (VibratoEffect*)effect;
	WahwahEffect* wahwah = (WahwahEffect*)effect;
	Eq8BandEffect* eq8band= (Eq8BandEffect*)effect;



	switch (effect->type) {
	case effectType::flanger:
		ui.flangerEffectFrame->setHidden(false);
		ui.flangerF0Slider->setValue((int)(flanger->getFo() * 100));
		ui.flangerGFBDial->setValue((int)(flanger->getGFB() * 100));
		ui.flangerGFFDial->setValue((int)(flanger->getGFF() * 100));
		ui.flangerMwDial->setValue((int)(flanger->getMw() * 100));
		ui.flangerM0Dial->setValue((int)(flanger->getM0() * 100));
		break; // TODO SET MAX MIN FLANGER AND NAMES
	case effectType::reverb:
		ui.reverbEffectFrame->setHidden(false);
		ui.reverbTypeComboBox->setCurrentIndex(reverb->getMode());
		ui.reverbDelayDial->setValue((int)(reverb->getDelay() * 100));
		ui.reverbAttnDial->setValue((int)(reverb->getAtt() * 100));
		break;
	case effectType::vibrato:
		ui.vibratoEffectFrame->setHidden(false);
		ui.vibratoF0Slider->setValue((int)(vibrato->getFo() * 100));
		ui.vibratoMAvgDial->setValue((int)(vibrato->getMavg() * 100));
		ui.vibratoWidthDial->setValue((int)(vibrato->getWidth() * 100));
		break;
	case effectType::wahwah:
		ui.wahwahEffectFrame->setHidden(false);
		ui.wahwahFMinSlider->setValue((int)(wahwah->getFmin() * 100));
		ui.wahwahLFOSlider->setValue((int)(wahwah->getFLFO() * 100));
		break;

	case effectType::eq8band:
		ui.eq8Frame->setHidden(false);
		ui.eqSlider100->setValue((int)(eq8band->getGains().gains[0] * 100));
		ui.eqSlider200->setValue((int)(eq8band->getGains().gains[1] * 100));
		ui.eqSlider400->setValue((int)(eq8band->getGains().gains[2] * 100));
		ui.eqSlider800->setValue((int)(eq8band->getGains().gains[3] * 100));
		ui.eqSlider1k4->setValue((int)(eq8band->getGains().gains[4] * 100));
		ui.eqSlider2k7->setValue((int)(eq8band->getGains().gains[5] * 100));
		ui.eqSlider5k->setValue((int)(eq8band->getGains().gains[6] * 100));
		ui.eqSlider10k->setValue((int)(eq8band->getGains().gains[7] * 100));

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


void Leandro::removeEffectFromActiveChannel() {
	
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++)
	{
		switch (activeChannel->effects.at(effIndex)->type) {
		case effectType::flanger:
			if (ui.flangerEffectFrame->isHidden()) {
				activeChannel->effects.at(effIndex)->~Effect();
				activeChannel->effects.erase(activeChannel->effects.begin() + effIndex);
			}
			break;
		case effectType::reverb:
			if (ui.reverbEffectFrame->isHidden()) {
				activeChannel->effects.at(effIndex)->~Effect();
				activeChannel->effects.erase(activeChannel->effects.begin() + effIndex);
			}
			break;
		case effectType::vibrato:
			if (ui.vibratoEffectFrame->isHidden()) {
				activeChannel->effects.at(effIndex)->~Effect();
				activeChannel->effects.erase(activeChannel->effects.begin() + effIndex);
			}
			break;
		case effectType::wahwah:
			if (ui.wahwahEffectFrame->isHidden()) {
				activeChannel->effects.at(effIndex)->~Effect();
				activeChannel->effects.erase(activeChannel->effects.begin() + effIndex);
			}
			break;
		case effectType::eq8band:
			if (ui.eq8Frame->isHidden()) {
				activeChannel->effects.at(effIndex)->~Effect();
				activeChannel->effects.erase(activeChannel->effects.begin() + effIndex);
			}
			break;
		}
	}
	updateActiveAssetsBay();
}

void Leandro::removeInstrumentFromActiveChannel() {
	activeChannel->removeChannelInstrument();
	updateActiveAssetsBay();

}
void Leandro::removeReverbEffect() {
	ui.reverbEffectFrame->setHidden(true);
	removeEffectFromActiveChannel();
}

void Leandro::removeFlangerEffect() {
	ui.flangerEffectFrame->setHidden(true);
	removeEffectFromActiveChannel();
}

void Leandro::removeVibratoEffect() {
	ui.vibratoEffectFrame->setHidden(true);
	removeEffectFromActiveChannel();
}

void Leandro::removeEq8BandEffect() {
	ui.eq8Frame->setHidden(true);
	removeEffectFromActiveChannel();
}

void Leandro::removeWahwahEffect() {
	ui.wahwahEffectFrame->setHidden(true);
	removeEffectFromActiveChannel();
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
				effect = new WahwahEffect((wahwahParams_t*)effectModels.at(i)->params);
				break;
			}
			break;
		}
	activeChannel->addEffectToChannel(effect);
}

// GUI triggered setters

