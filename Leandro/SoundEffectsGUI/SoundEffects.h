#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_SoundEffects.h"
#include "AudioFile.h"
#include "Effect.h"

typedef struct {
	bool reverbPlain, reverbEco, reverbLowpass, vibrato, flanger, wahwah, eq, tremolo;
}effects_s;

class SoundEffects : public QMainWindow
{
	Q_OBJECT

public:
	SoundEffects(QWidget* parent = Q_NULLPTR);


private:
	void computeEffects();
	void checkBoxes();
	void resetEffects();
	Ui::MainWindow ui;
	void loadFile();
	void saveFile();
	float* input;
	float* wildcard;
	std::string inpFileText;
	unsigned int numSamples;
	float delay, attenuation;
	float vibratoFreq;
	float flangerFreq;
	float wFreqMin, wFreqLFO;
	float eqBass, eqMid, eqHigh;
	unsigned int maxSoundBufferSize;
	unsigned int sampleRate;
	effects_s eff;
	AudioFile<double> * audioFile;
};
