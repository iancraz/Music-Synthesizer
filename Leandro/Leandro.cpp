#include "Leandro.h"
#include <QWidget>
#include "Leandro.h"
#include "Channel.h"
#include "portaudio.h"
#include "instrument.h"
#include "Effect.h"
#include <fstream>
#include <string>
#include "AudioFile.h"
#include <qfiledialog.h>

using namespace std;

Leandro::Leandro(QWidget* parent) : QMainWindow(parent) {
	loadData();
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
	initGUI();
	// GUI function connections

	this->wav = new float[MAX_WAV_SIZE];
	restarWavRecording();
	
}

Leandro::~Leandro() {
	delete[] wav;
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


	//// LO QUE AGREGO IAN ES ESTO/////////////////
	if (data->recordFlag) {
		for (unsigned int i = 0; i < (unsigned int)(frameCount / 2); i++) {
			data->wav[*(data->wavCounter) + i] = out[2 * i];
		}
		*data->wavCounter += frameCount;
	}
	///////////////////////////////////////////////

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
	newChannel->addToGUI(&ui);
	setActiveChannel(newChannel);
	this->channels.push_back(newChannel);
	this->updateCallbackData();
}

void Leandro::destroyChannel(Channel* channel) { // Channel destructor
	// Free used memory and destroy note buffers, up to MAX_SIMULTANEOUS_NOTES_PER_CHANNEL, if there are enough empty ones
	int k = MAX_SIMULTANEOUS_NOTES_PER_CHANNEL;
	for (int i = 0; i < this->noteBuffers.size() && k>0; i++)
		if (this->noteBuffers[i]->buffer[0] == INFINITY) {
			free(this->noteBuffers[i]->buffer);
			this->noteBuffers.erase(noteBuffers.begin() + i);
		}
	// Destroy channel and remove from channel list
	channel->removeFromGUI(&this->ui);
	channel->~Channel();
	this->channels.erase(remove(this->channels.begin(), this->channels.end(), channel), this->channels.end());
}


void Leandro::addMidiFile(string filename, bool autoSet) {
	MidiFile* midifile = new MidiFile;
	midifile->read(filename);
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
			tempChannel = new Channel(this->channelCreationCounter++, this);
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

// Data loading related methods

void Leandro::addToAvailableAssets(instrumentModel* model) {
	instrumentModels.push_back(model);
	updateAvailableAssetsInGUI();
}

void Leandro::addToAvailableAssets(effectModel* model) {
	effectModels.push_back(model);
	updateAvailableAssetsInGUI();
}


void Leandro::loadData() {
	// parseo el json
	Json::Value root;
	Json::CharReaderBuilder builder;
	ifstream configFile("config.json");
	JSONCPP_STRING errs;
	Json::parseFromStream(builder, configFile, &root, &errs);

	loadSynthData(root["synth"]);
	loadEffectsData(root["effects"]);
}

void Leandro::loadEffectsData(Json::Value effectsData) {
	// reverb
	Json::Value reverbData = effectsData["reverb"];
	list<string> typesList;

	for (int i = 0; i < reverbData["types"].size(); i++) {
		typesList.push_back(reverbData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value effectModelData = reverbData[*it];
		reverbParams_t* params = new reverbParams_t;
		params->att = effectModelData["att"].asFloat();
		params->delay = effectModelData["delay"].asFloat();
		effectModel* model = new effectModel;
		model->effectName = *it;
		model->type = effectType::reverb;
		model->params = (void*)params;
		effectModels.push_back(model);
	}


	// Vibrato
	Json::Value vibratoData = effectsData["vibrato"];
	typesList.clear();
	for (int i = 0; i < vibratoData["types"].size(); i++) {
		typesList.push_back(vibratoData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value effectModelData = vibratoData[*it];
		vibratoParams_t* params = new vibratoParams_t;
		params->fo = vibratoData["f0"].asFloat();
		params->W = vibratoData["width"].asFloat();
		params->M_avg = vibratoData["m-avg"].asFloat();
		params->sampleRate = SAMPLE_RATE;
		params->maxSoundBufferSize = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;

		effectModel* model = new effectModel;
		model->effectName = *it;
		model->type = effectType::vibrato;
		model->params = (void*)params;
		effectModels.push_back(model);
	}

	// Flanger
	Json::Value flangerData = effectsData["flanger"];
	typesList.clear();
	for (int i = 0; i < flangerData["types"].size(); i++) {
		typesList.push_back(flangerData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value effectModelData = flangerData[*it];
		flangerParams_t* params = new flangerParams_t;
		params->sampleRate = SAMPLE_RATE;
		params->maxSoundBufferSize = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		params->fo = effectModelData["f0"].asFloat();
		params->Mo = effectModelData["m0"].asFloat();
		params->Mw = effectModelData["mw"].asFloat();
		params->g_fb = effectModelData["g-fb"].asFloat();
		params->g_ff = effectModelData["g-ff"].asFloat();

		effectModel* model = new effectModel;
		model->effectName = *it;
		model->type = effectType::vibrato;
		model->params = (void*)params;
		effectModels.push_back(model);
	}

	// Wah-wah
	Json::Value wahData = effectsData["wah-wah"];
	typesList.clear();
	for (int i = 0; i < wahData["types"].size(); i++) {
		typesList.push_back(wahData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value effectModelData = wahData[*it];
		wahwahParams_t* params = new wahwahParams_t;
		params->f_LFO = effectModelData["f-lfo"].asFloat();
		params->f_min = effectModelData["f-min"].asFloat();
		params->samplingRate = SAMPLE_RATE;
		params->maxBufferSize = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		effectModel* model = new effectModel;
		model->effectName = *it;
		model->type = effectType::wahwah;
		model->params = (void*)params;
		effectModels.push_back(model);
	}

	// Equalizer
	Json::Value equalizerData = effectsData["equalizer"];
	typesList.clear();
	for (int i = 0; i < equalizerData["types"].size(); i++) {
		typesList.push_back(equalizerData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value effectModelData = equalizerData[*it];
		eq8bandParams_t* params = new eq8bandParams_t;
		for (int i = 0; i < effectModelData.size(); i++) {
			params->gains[i] = effectModelData[i].asFloat();
		}
		params->sampleRate = SAMPLE_RATE;
		params->maxSoundBufferSize = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		effectModel* model = new effectModel;
		model->effectName = *it;
		model->type = effectType::eq8band;
		model->params = (void*)params;
		effectModels.push_back(model);
	}
}

void Leandro::loadSynthData(Json::Value synthData) {
	//agarro los instrumentos aditivos
	Json::Value additiveData = synthData["additive"];

	list<string> typesList;
	for (int i = 0; i < additiveData["types"].size(); i++) {
		typesList.push_back(additiveData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value instrumentModelData = additiveData[*it];
		additiveParams_t* instrumentParams = new additiveParams_t(AdditiveInstrument::parseAdditiveJson(instrumentModelData));
		instrumentModel model;
		model.type = synthType::additive;
		model.params = (void*)instrumentParams;
		model.instrumentName = *it;
		instrumentModels.push_back(new instrumentModel(model));
	}

	// adsr
	Json::Value adsrData = synthData["adsr"];

	typesList.clear();
	for (int i = 0; i < adsrData["types"].size(); i++) {
		typesList.push_back(adsrData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value instrumentModelData = adsrData[*it];
		adsrParams_t params;
		params.buffLength = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		params.sampleRate = SAMPLE_RATE;
		params.tAttack = instrumentModelData["t-attack"].asFloat();
		params.tDecay = instrumentModelData["t-decay"].asFloat();
		params.sustainRate = instrumentModelData["sustain-rate"].asFloat();
		params.sustainLevel = instrumentModelData["sustain-level"].asFloat();
		params.tRelease = instrumentModelData["t-release"].asFloat();
		params.k = instrumentModelData["k"].asFloat();
		string wf1 = instrumentModelData["waveform"][0].asCString();
		string wf2 = instrumentModelData["waveform"][1].asCString();

		if (wf1 == "sine")
			params.wform1 = sine;
		else if (wf1 == "square")
			params.wform1 = square;
		params.level1 = instrumentModelData["levels"][0].asFloat();

		if (wf2 == "sine")
			params.wform2 = sine;
		else if (wf2 == "square")
			params.wform2 = square;
		params.level2 = instrumentModelData["levels"][1].asFloat();

		instrumentModel model;
		model.instrumentName = *it;
		model.params = (void*)(new adsrParams_t(params));
		model.type = synthType::adsr;
		instrumentModels.push_back(new instrumentModel(model));
	}

	// Sampling
	Json::Value samplingData = synthData["sampling"];

	typesList.clear();
	for (int i = 0; i < samplingData["types"].size(); i++) {
		typesList.push_back(samplingData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value instrumentModelData = samplingData[*it];
		samplingParams_t* params = SamplingInstrument::parseSamplingJson(instrumentModelData);
		params->buffLength = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		instrumentModel model;
		model.instrumentName = *it;
		model.params = (void*)params;
		model.type = synthType::sampling;
		instrumentModels.push_back(new instrumentModel(model));
	}

	// Karplus
	Json::Value karplusData = synthData["karplus"];
	typesList.clear();
	for (int i = 0; i < karplusData["types"].size(); i++) {
		typesList.push_back(karplusData["types"][i].asCString());
	}

	for (list<string>::iterator it = typesList.begin(); it != typesList.end(); it++) {
		Json::Value instrumentModelData = karplusData[*it];
		karPlusParams_t* params = new karPlusParams_t;
		params->BFactor = instrumentModelData["b-factor"].asFloat();
		params->SFactor = instrumentModelData["s-factor"].asFloat();
		params->Grl = instrumentModelData["grl"].asFloat();
		params->bodyFilter = instrumentModelData["body-filter"].asBool();
		string noiseType = instrumentModelData["noise-type"].asCString();
		if (noiseType == "normal")
			params->noiseType = NORMAL_RANDOM;
		else if (noiseType == "uniform")
			params->noiseType = UNIFORM_RANDOM;
		instrumentModel model;
		model.params = (void*)params;
		model.instrumentName = *it;
		model.type = synthType::karplus;
		instrumentModels.push_back(new instrumentModel(model));
	}
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
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++) {
		showEffect(activeChannel->effects.at(effIndex)); // TODO PRIORITY add effect order: IDEA: implement function that reorganizes effects using replaceWidget function
	}

}

void Leandro::setActiveChannel(Channel* channel) {
	if (activeChannel) activeChannel->setActiveButtonChannel->setEnabled(true);
	activeChannel = channel;
	activeChannel->setActiveButtonChannel->setDisabled(true);

	updateActiveAssetsBay();
} 

void Leandro::showInstrument(Instrument* instrument) {


	ADSRInstrument* adsrinst = (ADSRInstrument*)instrument;
	AdditiveInstrument* additiveinst = (AdditiveInstrument*)instrument;
	SamplingInstrument* samplinginst = (SamplingInstrument*)instrument;
	karplusInstrument* karplusinst = (karplusInstrument*)instrument;



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
			ui.sliderH0->setValue((int)(additiveinst->getHarmonicFactor(0) * 100));
			ui.sliderH1->setValue((int)(additiveinst->getHarmonicFactor(1) * 100));
			ui.sliderH2->setValue((int)(additiveinst->getHarmonicFactor(2) * 100));
			ui.sliderH3->setValue((int)(additiveinst->getHarmonicFactor(3) * 100));
			ui.sliderH4->setValue((int)(additiveinst->getHarmonicFactor(4) * 100));
			ui.sliderH5->setValue((int)(additiveinst->getHarmonicFactor(5) * 100));
			ui.sliderH6->setValue((int)(additiveinst->getHarmonicFactor(5) * 100));
			ui.sliderH7->setValue((int)(additiveinst->getHarmonicFactor(6) * 100));
			ui.sliderH8->setValue((int)(additiveinst->getHarmonicFactor(7) * 100));
			ui.sliderH9->setValue((int)(additiveinst->getHarmonicFactor(8) * 100));
			ui.sliderH10->setValue((int)(additiveinst->getHarmonicFactor(9) * 100));
			ui.sliderH11->setValue((int)(additiveinst->getHarmonicFactor(10) * 100));


			break;
		case synthType::karplus:
			ui.karplusInstrumentFrame->setHidden(false);
			ui.karplusBlendSlider->setValue((int)(karplusinst->getBFactor() * 1000));
			ui.karplusStretchSlider->setValue((int)(karplusinst->getSFactor() * 100));
			ui.karplusDecaySlider->setValue((int)(karplusinst->getRlFactor() * 1000));
			ui.karplusResFilterCheckBox->setChecked(karplusinst->filterStatus());
			break;
		case synthType::sampling:
			ui.samplingInstrumentFrame->setHidden(false);
			ui.samplingLoopStartDial->setValue(samplinginst->getLoopBegin());
			ui.samplingLoopStartDial->setValue(samplinginst->getLoopEnd());
			break;
		}

}

void Leandro::showEffect(Effect* effect) {
	FlangerEffect* flanger = (FlangerEffect*)effect;
	ReverbEffect* reverb = (ReverbEffect*)effect;
	VibratoEffect* vibrato = (VibratoEffect*)effect;
	WahwahEffect* wahwah = (WahwahEffect*)effect;
	Eq8BandEffect* eq8band = (Eq8BandEffect*)effect;



	switch (effect->type) {
	case effectType::flanger:
		ui.flangerEffectFrame->setHidden(false);
		ui.flangerF0Slider->setValue((int)(flanger->getFo() * 100));
		ui.flangerGFBDial->setValue((int)(flanger->getGFB() * 100));
		ui.flangerGFFDial->setValue((int)(flanger->getGFF() * 100));
		ui.flangerMwDial->setValue((int)(flanger->getMw() * 100));
		ui.flangerM0Dial->setValue((int)(flanger->getM0() * 100));
		break; 
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

void Leandro::addNewChannel() {
	Channel* newChannel = new Channel(this->channelCreationCounter++, this);
	addChannel(newChannel);

};

void Leandro::setInstrumentForActiveChannel() {
	Instrument* instrument = nullptr;
	for (int i = 0; i < instrumentModels.size(); i++)
		if (ui.instrumentsList->currentItem()->text().toStdString() == instrumentModels.at(i)->instrumentName) {
			switch (instrumentModels.at(i)->type) {
			case synthType::adsr:
				instrument = new ADSRInstrument((adsrParams_t*)instrumentModels.at(i)->params);
				break;
			case synthType::additive:
				instrument = new AdditiveInstrument((additiveParams_t*)instrumentModels.at(i)->params);
				break;
			case synthType::karplus:
				instrument = new karplusInstrument((karPlusParams_t*)instrumentModels.at(i)->params);
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
				effect = new WahwahEffect((wahwahParams_t*)effectModels.at(i)->params);
				break;
			case effectType::eq8band:
				effect = new Eq8BandEffect((eq8bandParams_t*)effectModels.at(i)->params);
				break;
			}
			break;
		}
	activeChannel->addEffectToChannel(effect);
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


// GUI triggered setters

void Leandro::instrumentValueChanged() {
	ADSRInstrument* adsrinst = (ADSRInstrument*)activeChannel->instrument;
	AdditiveInstrument* additiveinst = (AdditiveInstrument*)activeChannel->instrument;
	SamplingInstrument* samplinginst = (SamplingInstrument*)activeChannel->instrument;
	karplusInstrument* karplusinst = (karplusInstrument*)activeChannel->instrument;

	switch (activeChannel->instrument->type) {
	case synthType::adsr:
		adsrinst->setAttack(((float)ui.attackDialADSR->value()) / 1000.0);
		adsrinst->setDecay(((float)ui.decayDialADSR->value()) / 1000.0);
		adsrinst->setSustainRate(((float)ui.sustainRateDialADSR->value()) / 1000.0);
		adsrinst->setSustainLevel(((float)ui.sustainLevelDialADSR->value()) / 100.0);
		adsrinst->setRelease(((float)ui.releaseDialADSR->value()) / 1000.0);
		adsrinst->setWF1(ui.waveform1ComboBoxADSR->currentIndex());
		adsrinst->setWF2(ui.waveform2ComboBoxADSR->currentIndex());
		adsrinst->setWF1Level(((float)ui.levelWF1DialADSR->value()) / 100.0);
		adsrinst->setWF1Level(((float)ui.levelWF2DialADSR->value()) / 100.0);
		break;

	case synthType::additive:
		additiveinst->setHarmonicFactor(0, (float)ui.sliderH0->value() / 100.0);
		additiveinst->setHarmonicFactor(1, (float)ui.sliderH1->value() / 100.0);
		additiveinst->setHarmonicFactor(2, (float)ui.sliderH2->value() / 100.0);
		additiveinst->setHarmonicFactor(3, (float)ui.sliderH3->value() / 100.0);
		additiveinst->setHarmonicFactor(4, (float)ui.sliderH4->value() / 100.0);
		additiveinst->setHarmonicFactor(5, (float)ui.sliderH5->value() / 100.0);
		additiveinst->setHarmonicFactor(6, (float)ui.sliderH6->value() / 100.0);
		additiveinst->setHarmonicFactor(7, (float)ui.sliderH7->value() / 100.0);
		additiveinst->setHarmonicFactor(8, (float)ui.sliderH8->value() / 100.0);
		additiveinst->setHarmonicFactor(9, (float)ui.sliderH9->value() / 100.0);
		additiveinst->setHarmonicFactor(10, (float)ui.sliderH10->value() / 100.0);
		additiveinst->setHarmonicFactor(11, (float)ui.sliderH11->value() / 100.0);
		break;

	case synthType::karplus:
		karplusinst->setBFactor((float)ui.karplusBlendSlider->value() / 1000.0);
		karplusinst->setSFactor((float)ui.karplusStretchSlider->value() / 100.0);
		karplusinst->setRlFactor((float)ui.karplusDecaySlider->value() / 1000.0);
		if (ui.karplusResFilterCheckBox->isChecked()) karplusinst->activeFilter();
		else karplusinst->deactiveFilter();

		break;

	case synthType::sampling:
		
		if (ui.samplingLoopStartDial->value() < ui.samplingLoopEndDial->value()) {
			samplinginst->setLoopBegin(ui.samplingLoopStartDial->value());
			samplinginst->setLoopEnd(ui.samplingLoopEndDial->value());
		}
		else {
			if (samplinginst->getLoopBegin() != ui.samplingLoopStartDial->value())
			{
				samplinginst->setLoopBegin(ui.samplingLoopEndDial->value() - 1);
				ui.samplingLoopStartDial->setValue(samplinginst->getLoopBegin());
			}
			else
			{
				samplinginst->setLoopEnd(ui.samplingLoopStartDial->value() + 1);
				ui.samplingLoopEndDial->setValue(samplinginst->getLoopEnd());
			}
		}
		break;
	}
}

void Leandro::reverbValueChanged() {
	ReverbEffect* reverbEffect;
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++) 
		if (activeChannel->effects.at(effIndex)->type == effectType::reverb)
			reverbEffect = (ReverbEffect*)activeChannel->effects.at(effIndex);
	
	reverbEffect->setAtt((float)ui.reverbAttnDial->value() / 100.0);
	reverbEffect->setDelay((float)ui.reverbDelayDial->value() / 100.0);	
}

void Leandro::flangerValueChanged() {
	FlangerEffect* flangerEffect;
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++)
		if (activeChannel->effects.at(effIndex)->type == effectType::flanger)
			flangerEffect = (FlangerEffect*)activeChannel->effects.at(effIndex);

	flangerEffect->setFo((float)ui.flangerF0Slider->value() / 100.0);
	flangerEffect->setGFB((float)ui.flangerGFBDial->value() / 100.0);
	flangerEffect->setGFF((float)ui.flangerGFFDial->value() / 100.0);
	flangerEffect->setM0((float)ui.flangerM0Dial->value() / 10000.0);
	flangerEffect->setMw((float)ui.flangerMwDial->value() / 10.0);
}

void Leandro::vibratoValueChanged() {
	VibratoEffect* vibratoEffect;
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++)
		if (activeChannel->effects.at(effIndex)->type == effectType::vibrato)
			vibratoEffect = (VibratoEffect*)activeChannel->effects.at(effIndex);

	vibratoEffect->setFo((float)ui.vibratoF0Slider->value() / 100.0);
	vibratoEffect->setWidth((float)ui.vibratoWidthDial->value() / 100.0);
	vibratoEffect->setMavg((float)ui.vibratoMAvgDial->value());
}

void Leandro::eq8BandValueChanged() {
	Eq8BandEffect* eq8bandEffect;
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++)
		if (activeChannel->effects.at(effIndex)->type == effectType::eq8band)
			eq8bandEffect = (Eq8BandEffect*)activeChannel->effects.at(effIndex);

	gains_t* gains = new gains_t;
	gains->gains[0] = (float)ui.eqSlider100->value() / 100;
	gains->gains[1] = (float)ui.eqSlider200->value() / 100;
	gains->gains[2] = (float)ui.eqSlider400->value() / 100;
	gains->gains[3] = (float)ui.eqSlider800->value() / 100;
	gains->gains[4] = (float)ui.eqSlider1k4->value() / 100;
	gains->gains[5] = (float)ui.eqSlider2k7->value() / 100;
	gains->gains[6] = (float)ui.eqSlider5k->value() / 100;
	gains->gains[7] = (float)ui.eqSlider10k->value() / 100;
	eq8bandEffect->setGains(*gains);

}

void Leandro::wahwahValueChanged() {
	WahwahEffect* wahwahEffect;
	for (int effIndex = 0; effIndex < activeChannel->effects.size(); effIndex++)
		if (activeChannel->effects.at(effIndex)->type == effectType::wahwah)
			wahwahEffect = (WahwahEffect*)activeChannel->effects.at(effIndex);

	wahwahEffect->setFmin((float)ui.wahwahFMinSlider->value());
	wahwahEffect->setFLFO((float)ui.wahwahLFOSlider->value() / 100.0);
}


// GUI triggered setters




//	Record to WAV

void Leandro::record2Wav() {
	if (recordFlag) {
		AudioFile<double> audioFile;
		AudioFile<double>::AudioBuffer buffer;
		buffer.resize(1);
		buffer[0].resize(wavCounter);
		for (int i = 0; i < wavCounter - 1; i++) {
			buffer[0][i] = wav[i];
		}
		bool ok = audioFile.setAudioBuffer(buffer);
		audioFile.save("out.wav");
	}
	return;
}

void Leandro::restarWavRecording(){
	this->wavCounter = 0;
	return;
}





// GUI init

void Leandro::initGUI() {
	ui.setupUi(this);
	ui.retranslateUi(this);
	
	// Button connections
	QObject::connect(ui.newChannelButton, &QPushButton::clicked, this, &Leandro::addNewChannel);
	QObject::connect(ui.importMidiButton, &QPushButton::clicked, this, &Leandro::loadMidiFile);

	QObject::connect(ui.setInstrumentButton, &QPushButton::clicked, this, &Leandro::setInstrumentForActiveChannel);
	QObject::connect(ui.addEffectButton, &QPushButton::clicked, this, &Leandro::addEffectToActiveChannel);

	QObject::connect(ui.deleteADSRButton, &QPushButton::clicked, this, &Leandro::removeInstrumentFromActiveChannel);
	QObject::connect(ui.deleteAdditiveButton, &QPushButton::clicked, this, &Leandro::removeInstrumentFromActiveChannel);
	QObject::connect(ui.deleteKarplusButton, &QPushButton::clicked, this, &Leandro::removeInstrumentFromActiveChannel);
	QObject::connect(ui.deleteSamplingButton, &QPushButton::clicked, this, &Leandro::removeInstrumentFromActiveChannel);
	QObject::connect(ui.delete8EqButton, &QPushButton::clicked, this, &Leandro::removeEq8BandEffect);
	QObject::connect(ui.deleteReverbButton, &QPushButton::clicked, this, &Leandro::removeReverbEffect);
	QObject::connect(ui.deleteVibratoButton, &QPushButton::clicked, this, &Leandro::removeVibratoEffect);
	QObject::connect(ui.deleteFlangerButton, &QPushButton::clicked, this, &Leandro::removeFlangerEffect);
	QObject::connect(ui.deleteWahwahButton, &QPushButton::clicked, this, &Leandro::removeWahwahEffect);

	// Instrument parameters change connections

	// ADSR
	QObject::connect(ui.waveform1ComboBoxADSR, &QComboBox::currentTextChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.waveform2ComboBoxADSR, &QComboBox::currentTextChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.levelWF1DialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.levelWF2DialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.attackDialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.decayDialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sustainRateDialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sustainLevelDialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.releaseDialADSR, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);

	// Additive
	QObject::connect(ui.sliderH0, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH1, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH2, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH3, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH4, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH5, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH6, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH7, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH8, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH9, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH10, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.sliderH11, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	
	// Sampling
	QObject::connect(ui.samplingLoopEndDial, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.samplingLoopStartDial, &QDial::valueChanged, this, &Leandro::instrumentValueChanged);
	
	// Karplus
	QObject::connect(ui.karplusBlendSlider, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.karplusDecaySlider, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.karplusStretchSlider, &QSlider::valueChanged, this, &Leandro::instrumentValueChanged);
	QObject::connect(ui.karplusResFilterCheckBox, &QCheckBox::clicked , this, &Leandro::instrumentValueChanged);
	

	// Effects
	
	// Reverb
	QObject::connect(ui.reverbTypeComboBox, &QComboBox::currentTextChanged, this, &Leandro::reverbValueChanged);
	QObject::connect(ui.reverbDelayDial, &QDial::valueChanged, this, &Leandro::reverbValueChanged);
	QObject::connect(ui.reverbAttnDial, &QDial::valueChanged, this, &Leandro::reverbValueChanged);
	
	// Flanger
	QObject::connect(ui.flangerF0Slider, &QSlider::valueChanged, this, &Leandro::flangerValueChanged);
	QObject::connect(ui.flangerGFBDial, &QDial::valueChanged, this, &Leandro::flangerValueChanged);
	QObject::connect(ui.flangerGFFDial, &QDial::valueChanged, this, &Leandro::flangerValueChanged);
	QObject::connect(ui.flangerMwDial, &QDial::valueChanged, this, &Leandro::flangerValueChanged);
	QObject::connect(ui.flangerM0Dial, &QDial::valueChanged, this, &Leandro::flangerValueChanged);

	// Vibrato
	QObject::connect(ui.vibratoF0Slider, &QSlider::valueChanged, this, &Leandro::vibratoValueChanged);
	QObject::connect(ui.vibratoWidthDial, &QDial::valueChanged, this, &Leandro::vibratoValueChanged);
	QObject::connect(ui.vibratoMAvgDial, &QDial::valueChanged, this, &Leandro::vibratoValueChanged);
	
	// Wahwah
	QObject::connect(ui.wahwahFMinSlider, &QDial::valueChanged, this, &Leandro::wahwahValueChanged);
	QObject::connect(ui.wahwahLFOSlider, &QDial::valueChanged, this, &Leandro::wahwahValueChanged);
	
	// 8 Band Equalizer
	QObject::connect(ui.eqSlider100, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider200, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider400, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider800, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider1k4, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider2k7, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider5k, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);
	QObject::connect(ui.eqSlider10k, &QSlider::valueChanged, this, &Leandro::eq8BandValueChanged);

}

// TEST FUNCTIONS

void Leandro::loadTestMidi() {
	addMidiFile("sm64.mid");
}

void Leandro::loadMidiFile() {
	QString fileName = QFileDialog::getOpenFileName(this,
													tr("Load Midi File"), "",
													tr("Midi Files (*.mid);;All Files (*)"));
	addMidiFile(fileName.toStdString());
}
