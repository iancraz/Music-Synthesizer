#include "Leandro.h"
#include <QWidget>
#include "Leandro.h"
#include "Channel.h"
#include "portaudio.h"
#include "instrument.h"
#include "Effect.h"
#include <fstream>
#include <string>
#include <thread>
#include "AudioFile.h"
#include <qfiledialog.h>
#include <QSplashScreen>
#include "Spectrogram/Spectrogram.h"

using namespace std;

typedef struct {
	Json::Value instrumentModelData;
	synthType type;
	string name;
	Leandro* program;
}loadingCBData;

void dataLoadCallback(loadingCBData data);

Leandro::Leandro(QWidget* parent) : QMainWindow(parent) {
	recordFlag = false;
	specgramFlag = false;
	wavCounter = 0;
	QPixmap pixmap("images/splash.png");
	QSplashScreen* splash = new QSplashScreen(pixmap);
	splash->show();
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
	this->wav = new float[MAX_WAV_SIZE];
	this->wav[0] = INFINITY;
	this->updateCallbackData();
	
	
	
	initGUI();
	// GUI function connections
	splash->close();
	
	
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
		//*data->debugStream << (1.0 / addedFrames) * data->activeBuffer[frame] << endl;
		if (*data->recordFlag) {
			data->wav[(*data->wavCounter)++] = (1.0 / addedFrames) * data->activeBuffer[frame];
			data->wav[(*data->wavCounter) + 1] = INFINITY;
		}
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
	
	newChannel->channelFrame = channelFrames.at(getFirstFreeChannelFrame());
	newChannel->channelFrame->setHidden(false);
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
	channel->channelFrame->setHidden(true);
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
		bool isMusical = false;
		int evs = 0;
		MidiEvent event;
		while (evs < midifile->getEventCount(track) && !isMusical) {
			event = midifile->getEvent(track, evs);
			if (event.isNote())
				isMusical = true;
			evs++;
		}
		if (autoSet && isMusical) {
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
	this->callData.recordFlag = &recordFlag;
	this->callData.wav = this->wav;
	this->callData.wavCounter = &wavCounter;

};

int Leandro::getFirstFreeChannelFrame() {
	int i;
	bool foundIt = false;
	for (i = 0; i < channelFrames.size(); i++) {
		if (channelFrames.at(i)->isHidden())
		{
			foundIt = true;
			break;
		}
	}
	if (!foundIt) return -1;
	else return i;
}

// Data loading related methods

void Leandro::addToAvailableAssets(instrumentModel* model) {
	instrumentModels.push_back(model);
	updateAvailableAssetsInGUI();
}

void Leandro::addToAvailableAssets(effectModel* model) {
	effectModels.push_back(model);
	updateAvailableAssetsInGUI();
}

void Leandro::addModel(instrumentModel* model) {
	instrumentModels.push_back(model);
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
		params->maxSoundBufferSize = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		string mode = *it;
		if (mode == "Plain Reverb")
			params->mode = E_PLAIN;
		else if (mode == "Echo Reverb")
			params->mode = E_ECO;
		else if (mode == "Low-Pass Reverb")
			params->mode = E_LOWPASS;
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

void dataLoadCallback(loadingCBData data) {
	additiveParams_t* instrumentParams=nullptr;
	samplingParams_t* params = nullptr;
	instrumentModel model;
	
	switch (data.type) {
	case synthType::additive:
		instrumentParams = new additiveParams_t(AdditiveInstrument::parseAdditiveJson(data.instrumentModelData));
		model.type = synthType::additive;
		model.params = (void*)instrumentParams;
		model.instrumentName = data.name;
		data.program->addModel(new instrumentModel(model));
		break;
	case synthType::sampling:
		samplingParams_t* params = SamplingInstrument::parseSamplingJson(data.instrumentModelData);
		params->buffLength = MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE;
		model.instrumentName = data.name;
		model.params = (void*)params;
		model.type = synthType::sampling;
		data.program->addModel(new instrumentModel(model));
	}
	return;
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
		loadingCBData* data = new loadingCBData;
		data->instrumentModelData = instrumentModelData;
		data->type = synthType::additive;
		data->program = this;
		data->name = *it;

		std::thread dataThread(dataLoadCallback, *data);
		dataThread.detach();
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
		loadingCBData* data = new loadingCBData;
		data->instrumentModelData = instrumentModelData;
		data->type = synthType::sampling;
		data->program = this;
		data->name = *it;

		std::thread dataThread(dataLoadCallback, *data);
		dataThread.detach();
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
		___qlistwidgetitem->setText(QCoreApplication::translate("LeandroClass", effectModels.at(i)->effectName.c_str(), nullptr));
		ui.effectsList->addItem(___qlistwidgetitem);
	}
}

void Leandro::updateGUIMidiLists() {
	for (int i = 0; i < midiLists.size(); i++) {
		midiLists.at(i)->clear();
		for (int j = 0; j < midiTracks.size(); j++) {
			char* trackName = new char[(midiTracks.at(j)->trackName.size()) + 1];
			strcpy(trackName, midiTracks.at(j)->trackName.c_str());
			QListWidgetItem* ___qlistwidgetitem = new QListWidgetItem;
			___qlistwidgetitem->setText(QCoreApplication::translate("LeandroClass", trackName, nullptr));
			midiLists.at(i)->addItem(___qlistwidgetitem);
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
	//if (activeChannel) activeChannel->setActiveButtonChannel->setEnabled(true);
	activeChannel = channel;
	//activeChannel->setActiveButtonChannel->setDisabled(true);

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
	updateActiveAssetsBay();
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
		adsrinst->setWF2Level(((float)ui.levelWF2DialADSR->value()) / 100.0);
		
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

		AudioFile<double> audioFile;
		AudioFile<double>::AudioBuffer buffer;
		buffer.resize(1);
		buffer[0].resize(wavCounter);
		for (int i = 0; wav[i]!=INFINITY; i++) {
			buffer[0][i] = wav[i];
		}
		bool ok = audioFile.setAudioBuffer(buffer);
		audioFile.save("out.wav");

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

	updateAvailableAssetsInGUI();

	ui.exportToWavButton_2->setDisabled(true);
	ui.spectoFrame->setHidden(true);
	ui.recLabel->setHidden(true);

	ui.newChannelButton->setHidden(true);
	ui.newChannelButton->setDisabled(true);

	channelFrames.push_back(ui.frameChannel1);
	channelFrames.push_back(ui.frameChannel2);
	channelFrames.push_back(ui.frameChannel3);
	channelFrames.push_back(ui.frameChannel4);
	channelFrames.push_back(ui.frameChannel5);
	channelFrames.push_back(ui.frameChannel6);
	channelFrames.push_back(ui.frameChannel7);
	channelFrames.push_back(ui.frameChannel8);
	channelFrames.push_back(ui.frameChannel9);
	channelFrames.push_back(ui.frameChannel10);



	midiLists.push_back(ui.midiListChannel1);
	midiLists.push_back(ui.midiListChannel2);
	midiLists.push_back(ui.midiListChannel3);
	midiLists.push_back(ui.midiListChannel4);
	midiLists.push_back(ui.midiListChannel5);
	midiLists.push_back(ui.midiListChannel6);
	midiLists.push_back(ui.midiListChannel7);
	midiLists.push_back(ui.midiListChannel8);
	midiLists.push_back(ui.midiListChannel9);
	midiLists.push_back(ui.midiListChannel10);

	ui.midiListChannel1->setHidden(true);
	ui.midiListChannel2->setHidden(true);
	ui.midiListChannel3->setHidden(true);
	ui.midiListChannel4->setHidden(true);
	ui.midiListChannel5->setHidden(true);
	ui.midiListChannel6->setHidden(true);
	ui.midiListChannel7->setHidden(true);
	ui.midiListChannel8->setHidden(true);
	ui.midiListChannel9->setHidden(true);
	ui.midiListChannel10->setHidden(true);

	ui.closeButtonChannel1->setHidden(true);
	ui.closeButtonChannel2->setHidden(true);
	ui.closeButtonChannel3->setHidden(true);
	ui.closeButtonChannel4->setHidden(true);
	ui.closeButtonChannel5->setHidden(true);
	ui.closeButtonChannel6->setHidden(true);
	ui.closeButtonChannel7->setHidden(true);
	ui.closeButtonChannel8->setHidden(true);
	ui.closeButtonChannel9->setHidden(true);
	ui.closeButtonChannel10->setHidden(true);

	ui.inputComboBoxChannel1->setHidden(true);
	ui.inputComboBoxChannel2->setHidden(true);
	ui.inputComboBoxChannel3->setHidden(true);
	ui.inputComboBoxChannel4->setHidden(true);
	ui.inputComboBoxChannel5->setHidden(true);
	ui.inputComboBoxChannel6->setHidden(true);
	ui.inputComboBoxChannel7->setHidden(true);
	ui.inputComboBoxChannel8->setHidden(true);
	ui.inputComboBoxChannel9->setHidden(true);
	ui.inputComboBoxChannel10->setHidden(true);

	ui.frameChannel1->setHidden(true);
	ui.frameChannel2->setHidden(true);
	ui.frameChannel3->setHidden(true);
	ui.frameChannel4->setHidden(true);
	ui.frameChannel5->setHidden(true);
	ui.frameChannel6->setHidden(true);
	ui.frameChannel7->setHidden(true);
	ui.frameChannel8->setHidden(true);
	ui.frameChannel9->setHidden(true);
	ui.frameChannel10->setHidden(true);

	ui.adsrInstrumentFrame->setHidden(true);
	ui.additiveInstrumentFrame->setHidden(true);
	ui.samplingInstrumentFrame->setHidden(true);
	ui.karplusInstrumentFrame->setHidden(true);
	ui.reverbEffectFrame->setHidden(true);
	ui.flangerEffectFrame->setHidden(true);
	ui.vibratoEffectFrame->setHidden(true);
	ui.wahwahEffectFrame->setHidden(true);
	ui.eq8Frame->setHidden(true);
	
	// Button connections
	QObject::connect(ui.newChannelButton, &QPushButton::clicked, this, &Leandro::addNewChannel);
	QObject::connect(ui.importMidiButton, &QPushButton::clicked, this, &Leandro::loadMidiFile);
	//QObject::connect(ui.spectrogramButton, &QPushButton::clicked, this, &Leandro::showSpectrogram);

	//QObject::connect(ui.importMidiButton, &QPushButton::clicked, this, &Leandro::loadTestMidi); //DEBUG

	QObject::connect(ui.playButton, &QPushButton::clicked, this, &Leandro::startStreaming);
	QObject::connect(ui.pauseButton, &QPushButton::clicked, this, &Leandro::pauseStreaming);
	QObject::connect(ui.stopButton, &QPushButton::clicked, this, &Leandro::stopStreaming);
	QObject::connect(ui.recordButton, &QPushButton::clicked, this, &Leandro::toggleRecord);
	QObject::connect(ui.exportToWavButton_2, &QPushButton::clicked, this, &Leandro::record2Wav);

	

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

	// Channels
	QObject::connect(ui.closeButtonChannel1, &QPushButton::clicked, this, &Leandro::channel1Closed);
	QObject::connect(ui.setActiveButtonChannel1, &QPushButton::clicked, this, &Leandro::channel1setActive);
	QObject::connect(ui.inputComboBoxChannel1, &QComboBox::currentTextChanged, this, &Leandro::channel1InputChanged);
	QObject::connect(ui.levelDialChannel1, &QDial::valueChanged, this, &Leandro::channel1VolChanged);
	QObject::connect(ui.midiListChannel1, &QListWidget::itemSelectionChanged, this, &Leandro::channel1TrackChanged);

	QObject::connect(ui.closeButtonChannel2, &QPushButton::clicked, this, &Leandro::channel2Closed);
	QObject::connect(ui.setActiveButtonChannel2, &QPushButton::clicked, this, &Leandro::channel2setActive);
	QObject::connect(ui.inputComboBoxChannel2, &QComboBox::currentTextChanged, this, &Leandro::channel2InputChanged);
	QObject::connect(ui.levelDialChannel2, &QDial::valueChanged, this, &Leandro::channel2VolChanged);
	QObject::connect(ui.midiListChannel2, &QListWidget::itemSelectionChanged, this, &Leandro::channel2TrackChanged);

	QObject::connect(ui.closeButtonChannel3, &QPushButton::clicked, this, &Leandro::channel3Closed);
	QObject::connect(ui.setActiveButtonChannel3, &QPushButton::clicked, this, &Leandro::channel3setActive);
	QObject::connect(ui.inputComboBoxChannel3, &QComboBox::currentTextChanged, this, &Leandro::channel3InputChanged);
	QObject::connect(ui.levelDialChannel3, &QDial::valueChanged, this, &Leandro::channel3VolChanged);
	QObject::connect(ui.midiListChannel3, &QListWidget::itemSelectionChanged, this, &Leandro::channel3TrackChanged);

	QObject::connect(ui.closeButtonChannel4, &QPushButton::clicked, this, &Leandro::channel4Closed);
	QObject::connect(ui.setActiveButtonChannel4, &QPushButton::clicked, this, &Leandro::channel4setActive);
	QObject::connect(ui.inputComboBoxChannel4, &QComboBox::currentTextChanged, this, &Leandro::channel4InputChanged);
	QObject::connect(ui.levelDialChannel4, &QDial::valueChanged, this, &Leandro::channel4VolChanged);
	QObject::connect(ui.midiListChannel4, &QListWidget::itemSelectionChanged, this, &Leandro::channel4TrackChanged);

	QObject::connect(ui.closeButtonChannel5, &QPushButton::clicked, this, &Leandro::channel5Closed);
	QObject::connect(ui.setActiveButtonChannel5, &QPushButton::clicked, this, &Leandro::channel5setActive);
	QObject::connect(ui.inputComboBoxChannel5, &QComboBox::currentTextChanged, this, &Leandro::channel5InputChanged);
	QObject::connect(ui.levelDialChannel5, &QDial::valueChanged, this, &Leandro::channel5VolChanged);
	QObject::connect(ui.midiListChannel5, &QListWidget::itemSelectionChanged, this, &Leandro::channel5TrackChanged);

	QObject::connect(ui.closeButtonChannel6, &QPushButton::clicked, this, &Leandro::channel6Closed);
	QObject::connect(ui.setActiveButtonChannel6, &QPushButton::clicked, this, &Leandro::channel6setActive);
	QObject::connect(ui.inputComboBoxChannel6, &QComboBox::currentTextChanged, this, &Leandro::channel6InputChanged);
	QObject::connect(ui.levelDialChannel6, &QDial::valueChanged, this, &Leandro::channel6VolChanged);
	QObject::connect(ui.midiListChannel6, &QListWidget::itemSelectionChanged, this, &Leandro::channel6TrackChanged);

	QObject::connect(ui.closeButtonChannel7, &QPushButton::clicked, this, &Leandro::channel7Closed);
	QObject::connect(ui.setActiveButtonChannel7, &QPushButton::clicked, this, &Leandro::channel7setActive);
	QObject::connect(ui.inputComboBoxChannel7, &QComboBox::currentTextChanged, this, &Leandro::channel7InputChanged);
	QObject::connect(ui.levelDialChannel7, &QDial::valueChanged, this, &Leandro::channel7VolChanged);
	QObject::connect(ui.midiListChannel7, &QListWidget::itemSelectionChanged, this, &Leandro::channel7TrackChanged);

	QObject::connect(ui.closeButtonChannel8, &QPushButton::clicked, this, &Leandro::channel8Closed);
	QObject::connect(ui.setActiveButtonChannel8, &QPushButton::clicked, this, &Leandro::channel8setActive);
	QObject::connect(ui.inputComboBoxChannel8, &QComboBox::currentTextChanged, this, &Leandro::channel8InputChanged);
	QObject::connect(ui.levelDialChannel8, &QDial::valueChanged, this, &Leandro::channel8VolChanged);
	QObject::connect(ui.midiListChannel8, &QListWidget::itemSelectionChanged, this, &Leandro::channel8TrackChanged);

	QObject::connect(ui.closeButtonChannel9, &QPushButton::clicked, this, &Leandro::channel9Closed);
	QObject::connect(ui.setActiveButtonChannel9, &QPushButton::clicked, this, &Leandro::channel9setActive);
	QObject::connect(ui.inputComboBoxChannel9, &QComboBox::currentTextChanged, this, &Leandro::channel9InputChanged);
	QObject::connect(ui.levelDialChannel9, &QDial::valueChanged, this, &Leandro::channel9VolChanged);
	QObject::connect(ui.midiListChannel9, &QListWidget::itemSelectionChanged, this, &Leandro::channel9TrackChanged);

	QObject::connect(ui.closeButtonChannel10, &QPushButton::clicked, this, &Leandro::channel10Closed);
	QObject::connect(ui.setActiveButtonChannel10, &QPushButton::clicked, this, &Leandro::channel10setActive);
	QObject::connect(ui.inputComboBoxChannel10, &QComboBox::currentTextChanged, this, &Leandro::channel10InputChanged);
	QObject::connect(ui.levelDialChannel10, &QDial::valueChanged, this, &Leandro::channel10VolChanged);
	QObject::connect(ui.midiListChannel10, &QListWidget::itemSelectionChanged, this, &Leandro::channel10TrackChanged);


	

	
}

void Leandro::startStreaming() {

	ui.spectoFrame->setHidden(true);
	ui.exportToWavButton_2->setEnabled(false);
	wavCounter = 0;
	
	PaError err = Pa_StartStream(stream);
	
	

}

void Leandro::pauseStreaming() {
	PaError err = Pa_StopStream(stream);

}
void Leandro::stopStreaming() {
	if (recordFlag) toggleRecord();
	PaError err = Pa_StopStream(stream);
	activeBuffer[0] = INFINITY;
	for (int i = 0; i < noteBuffers.size(); i++) {
		noteBuffers.at(i)->buffer[0] = INFINITY;
		noteBuffers.at(i)->startingFrame = -1;
	}
	calcSpecgram();

	QPixmap image("spectogram.png");

	ui.imageLabel->setPixmap(image);

	ui.spectoFrame->setHidden(false);
	if(wavCounter) ui.exportToWavButton_2->setEnabled(true);
	currentSample = 0;
}

void Leandro::toggleRecord() {
	if (recordFlag) {
		recordFlag = false;
		ui.recLabel->setHidden(true);
	}
	else {
		recordFlag = true;
		ui.recLabel->setHidden(false);
	}
	}

void Leandro::channel1Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel1)
			channel = channels.at(i);
	}
}
void Leandro::channel1setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel1)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel1InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel1)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel1->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel1VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel1)
			channel = channels.at(i);
	}
	channel->volume = (1.0 / 100.0) * (float)ui.levelDialChannel1->value();
	channel->updateCallbackData();
}
void Leandro::channel1TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel1)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel1->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel2Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel2)
			channel = channels.at(i);
	}

}
void Leandro::channel2setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel2)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel2InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel2)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel2->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel2VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel2)
			channel = channels.at(i);
	}
	channel->volume = (2.0 / 200.0) * (float)ui.levelDialChannel2->value();
	channel->updateCallbackData();
}
void Leandro::channel2TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel2)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel2->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel3Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel3)
			channel = channels.at(i);
	}

}
void Leandro::channel3setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel3)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel3InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel3)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel3->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel3VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel3)
			channel = channels.at(i);
	}
	channel->volume = (3.0 / 300.0) * (float)ui.levelDialChannel3->value();
	channel->updateCallbackData();
}
void Leandro::channel3TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel3)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel3->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel4Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel4)
			channel = channels.at(i);
	}

}
void Leandro::channel4setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel4)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel4InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel4)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel4->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel4VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel4)
			channel = channels.at(i);
	}
	channel->volume = (4.0 / 400.0) * (float)ui.levelDialChannel4->value();
	channel->updateCallbackData();
}
void Leandro::channel4TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel4)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel4->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel5Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel5)
			channel = channels.at(i);
	}

}
void Leandro::channel5setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel5)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel5InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel5)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel5->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel5VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel5)
			channel = channels.at(i);
	}
	channel->volume = (5.0 / 500.0) * (float)ui.levelDialChannel5->value();
	channel->updateCallbackData();
}
void Leandro::channel5TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel5)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel5->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel6Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel6)
			channel = channels.at(i);
	}

}
void Leandro::channel6setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel6)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel6InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel6)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel6->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel6VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel6)
			channel = channels.at(i);
	}
	channel->volume = (6.0 / 600.0) * (float)ui.levelDialChannel6->value();
	channel->updateCallbackData();
}
void Leandro::channel6TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel6)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel6->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel7Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel7)
			channel = channels.at(i);
	}

}
void Leandro::channel7setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel7)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel7InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel7)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel7->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel7VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel7)
			channel = channels.at(i);
	}
	channel->volume = (7.0 / 700.0) * (float)ui.levelDialChannel7->value();
	channel->updateCallbackData();
}
void Leandro::channel7TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel7)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel7->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel8Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel8)
			channel = channels.at(i);
	}

}
void Leandro::channel8setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel8)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel8InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel8)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel8->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel8VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel8)
			channel = channels.at(i);
	}
	channel->volume = (8.0 / 800.0) * (float)ui.levelDialChannel8->value();
	channel->updateCallbackData();
}
void Leandro::channel8TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel8)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel8->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel9Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel9)
			channel = channels.at(i);
	}

}
void Leandro::channel9setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel9)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel9InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel9)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel9->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel9VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel9)
			channel = channels.at(i);
	}
	channel->volume = (9.0 / 900.0) * (float)ui.levelDialChannel9->value();
	channel->updateCallbackData();
}
void Leandro::channel9TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel9)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel9->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::channel10Closed() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel10)
			channel = channels.at(i);
	}

}
void Leandro::channel10setActive() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel10)
			channel = channels.at(i);
	}
	setActiveChannel(channel);

}
void Leandro::channel10InputChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel10)
			channel = channels.at(i);
	}
	channel->keyboard = false;
	if ((ui.inputComboBoxChannel10->currentText().toStdString() == "PC Keyboard")) channel->keyboard = true;
	channel->updateCallbackData();

}
void Leandro::channel10VolChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel10)
			channel = channels.at(i);
	}
	channel->volume = (10.0 / 1000.0) * (float)ui.levelDialChannel10->value();
	channel->updateCallbackData();
}
void Leandro::channel10TrackChanged() {
	Channel* channel = nullptr;
	int i;
	for (i = 0; i < channels.size(); i++)
	{
		if (channels.at(i)->channelFrame == ui.frameChannel10)
			channel = channels.at(i);
	}
	for (int i = 0; i < midiTracks.size(); i++)
		if ((ui.midiListChannel10->currentItem()->text().toStdString() == midiTracks.at(i)->trackName)) {
			channel->setChannelTrack(midiTracks.at(i));
			break;
		}
}

void Leandro::showSpectrogram() {
	
	QDialog popup(this);
	popup.show();
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


void Leandro::calcSpecgram() {
	if (wav[0] != INFINITY) {
		int i = 0;
		while (wav[i] != INFINITY) {
			i++;
		}

		Spectrogram temp(wav, i);
		unsigned int nfft = 1024;
		unsigned int overlap = 128;
		bool show = false;
		temp.calcSpectrogram(SAMPLE_RATE, nfft, WINDOW_NONE, overlap, show, true, "spectogram.png");
	}
	return;
}