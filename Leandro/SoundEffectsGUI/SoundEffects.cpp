#include "SoundEffects.h"
#include "Effect.h"

SoundEffects::SoundEffects(QWidget* parent) : QMainWindow(parent)
{
	resetEffects();
	ui.setupUi(this);
	ui.outputFileName->setText("out.wav");
	ui.InputFileName->setText("tst.wav");
	sampleRate = 44e3;
	input = nullptr;
	audioFile = nullptr;
	connect(this->ui.loadButton, &QPushButton::clicked, this, &SoundEffects::loadFile);
	connect(this->ui.saveButton, &QPushButton::clicked, this, &SoundEffects::saveFile);
}

void SoundEffects::loadFile() {
	audioFile = new AudioFile<double>;
	audioFile->load(ui.InputFileName->text().toLocal8Bit().constData());
	int channel = 0;
	numSamples = audioFile->getNumSamplesPerChannel();
	if (numSamples > 0) {
		input = new float[numSamples + 1];
		wildcard = new float[numSamples + 1];
		for (int i = 0; i < numSamples; i++)
		{
			input[i] = (float)audioFile->samples[channel][i];
			wildcard[i] = input[i];
		}
		input[numSamples] = INFINITY;
		wildcard[numSamples] = input[numSamples];
		maxSoundBufferSize = numSamples;
		ui.UserExp->setText("Archivo cargado con exito");
	}
	else
		ui.UserExp->setText("Hubo un problema al cargar el archivo");
	return;
}

void SoundEffects::saveFile() {
	if (input != nullptr) {
		checkBoxes();
		computeEffects();
		AudioFile<double>::AudioBuffer buffer;
		buffer.resize(1);
		buffer[0].resize(audioFile->getNumSamplesPerChannel());
		for (int i = 0; i < audioFile->getNumSamplesPerChannel()-1; i++)
		{
			buffer[0][i] = input[i];
		}

		bool ok = audioFile->setAudioBuffer(buffer);
		audioFile->save(ui.outputFileName->text().toLocal8Bit().constData());
		//for (unsigned int i = 0; i < maxSoundBufferSize; i++)
		//	input[i] = 0;
		delete[] input;
		input = nullptr;
		input = new float[numSamples + 1];
		for (unsigned int i = 0; i < numSamples; i++) {
			input[i] = wildcard[i];
		}
		input[numSamples] = INFINITY;
		delete audioFile;
		audioFile = nullptr;
		audioFile = new AudioFile<double>;
		audioFile->load(ui.InputFileName->text().toLocal8Bit().constData());
		resetEffects();
		ui.UserExp->setText("Archivo guardado con exito");
	}
	else
		ui.UserExp->setText("No se cargo el archivo");
	return;
}

void SoundEffects::computeEffects() {
	if (eff.reverbPlain) {
 		float delay = ((float)ui.reverbDelay->sliderPosition()) / 100.0 * 3.0;
		float attenuation = (float)(ui.AttSlider->sliderPosition() / 100.0);
		reverbParams_t params;
		params.att = attenuation;
		params.delay = delay;
		params.mode = E_PLAIN;
		params.maxSoundBufferSize = numSamples;
		ReverbEffect effect(&params);
		effect.callback((void *)input, numSamples, sampleRate);
	}
	else if (eff.reverbEco) {
		float delay = ((float)ui.reverbDelay->sliderPosition()) / 100.0 * 3.0;
		float attenuation = (float)(ui.AttSlider->sliderPosition() / 100.0);
		reverbParams_t params;
		params.att = attenuation;
		params.delay = delay;
		params.mode = E_ECO;
		params.maxSoundBufferSize = numSamples;
		ReverbEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}
	else if (eff.reverbLowpass) {
		float delay = ((float)ui.reverbDelay->sliderPosition()) / 100.0 * 3.0;
		float attenuation = (float)(ui.AttSlider->sliderPosition() / 100.0);
		reverbParams_t params;
		params.att = attenuation;
		params.delay = delay;
		params.mode = E_PLAIN;
		params.maxSoundBufferSize = numSamples;
		ReverbEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}
	if (eff.eq) {
		float gainLow, gainMid, gainHigh;
		gainLow = ui.eqBass->sliderPosition() / 100.0;
		gainMid = ui.eqMid->sliderPosition() / 100.0;
		gainHigh = ui.eqHigh->sliderPosition() / 100.0;
		equalizatorParams_t params;
		params.gainLow = gainLow;
		params.gainMid = gainMid;
		params.gainHigh = gainHigh;
		params.maxSoundBufferSize = numSamples;
		params.sampleRate = sampleRate;
		EqualizatorEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}
	if (eff.wahwah) {
		float freqMin = ui.wahFreqMin->sliderPosition() / 100.0 * (1e3 - 200.0) + 200.0;
		float freqLFO = ui.wahFreqLFO->sliderPosition() / 100.0 * (5.0 - 0.2) + 0.2;
		wahwahParams_t params;
		params.f_LFO = freqLFO;
		params.f_min = freqMin;
		params.maxBufferSize = numSamples;
		params.samplingRate = sampleRate;
		WahwahEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}
	if (eff.flanger) {
		float freq = ui.flangerFreq->sliderPosition() / 100.0 * (5.0 - 0.1) + 0.1;
		flangerParams_t params;
		params.fo = freq;
		params.sampleRate = sampleRate;
		params.maxSoundBufferSize = numSamples;
		params.Mw = 5;
		params.Mo = 1e-3;
		params.g_fb = 0.3;
		params.g_ff = 0.9;
		FlangerEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}
	if (eff.vibrato) {
		float freq = ui.vibratoFreq->sliderPosition() / 100.0 * (20.0 - 0.5) + 0.5;
		vibratoParams_t params;
		params.fo = freq;
		params.maxSoundBufferSize = numSamples;
		params.sampleRate = sampleRate;
		params.W = 1e3;
		params.M_avg = 10;
		VibratoEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}
	if (eff.tremolo) {
		tremoloParams_t params;
		params.alpha = this->ui.tremoloAlpha->sliderPosition() /100.0;
		params.f_lfo = this->ui.tremoloFreq->sliderPosition()/100.0 * 20.0 + 0.2;
		params.sampleRate = sampleRate;
		TremoloEffect effect(&params);
		effect.callback(input, numSamples, sampleRate);
	}

	//PRUEBA EQ 8 BANDAS

	/*eq8bandParams_t params;
	params.gains[0] = 1;
	params.gains[1] = 1;
	params.gains[2] = 1;
	params.gains[3] = 0;
	params.gains[4] = 0;
	params.gains[5] = 0;
	params.gains[6] = 0;
	params.gains[7] = 0;
	params.sampleRate = sampleRate;
	params.maxSoundBufferSize = numSamples;
	Eq8BandEffect effect(&params);
	effect.callback(input, numSamples, sampleRate);*/

	// PRUEBA TREMOLO

	return;
}

void SoundEffects::checkBoxes() {
	if (ui.reverbBox->isChecked()) {
		if (ui.plainRadioButton->isChecked())
			eff.reverbPlain = true;
		else if (ui.ecoRadioButton->isChecked())
			eff.reverbEco = true;
		else if (ui.lowpassRadioButton->isChecked())
			eff.reverbLowpass = true;
	}
	if (ui.vibratoBox->isChecked())
		eff.vibrato = true;
	if (ui.flangerBox->isChecked())
		eff.flanger = true;
	if (ui.eqBox->isChecked())
		eff.eq = true;
	if (ui.wahBox->isChecked())
		eff.wahwah = true;
	if (ui.tremoloCheckBox->isChecked())
		eff.tremolo = true;
}

void SoundEffects::resetEffects() {
	eff.eq = false;
	eff.flanger = false;
	eff.reverbEco = false;
	eff.reverbLowpass = false;
	eff.reverbPlain = false;
	eff.vibrato = false;
	eff.wahwah = false;
	eff.tremolo = false;
}