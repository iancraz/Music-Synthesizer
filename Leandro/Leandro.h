#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Leandro.h"
#include "midifile.h"
#include "Channel.h"
#include "portaudio.h"
#include "midiAssets.h"
#include "bufferAssets.h"
#include "Options.h"
#include "Instrument.h"
#include "Effect.h"
#include <list>
#include <vector>
#include <fstream>
#include "json/json.h"

#define SAMPLE_RATE (44100)
#define MAX_SIMULTANEOUS_NOTES_PER_CHANNEL 15
#define MAX_NOTE_LENGTH_SECONDS 10
#define	ACTIVE_BUFFER_FRAME_SIZE 44100

using namespace std;

enum class synthType;

typedef struct {
	string instrumentName;
	synthType type;
	void* params;
}instrumentModel;

typedef struct {
	string effectName;
	effectType type;
	void* params;
}effectModel;


class Channel;

typedef struct {
	vector<timedBuffer*>* buffers;
	float* activeBuffer;
	__int64* currentSample;
	vector<Channel*>* channels;
	ofstream* debugStream;
}callbackData;

class Leandro : public QMainWindow
{
	Q_OBJECT

public:
	Leandro(QWidget* parent = Q_NULLPTR);
	int channelCreationCounter;
	__int64 currentSample;
	vector<Channel*> channels;

	callbackData callData;
	PaStream* stream;
	ofstream debugStream;

	vector<MidiFile*> midiFiles;
	vector<midiTrack*> midiTracks;
	vector<timedBuffer*> noteBuffers;
	vector<instrumentModel*> instrumentModels;
	vector<effectModel*> effectModels;
	float* activeBuffer;
	Channel* activeChannel;

	~Leandro();

	static PaStreamCallback callback;
	void updateCallbackData();

	void addChannel(Channel* newChannel);
	void destroyChannel(Channel* channel);
	void addMidiFile(string directory, string filename, bool autoSet);
	

	// GUI-related, system-triggered functions
	void initGUI();
	void updateAvailableAssetsInGUI();
	void addToAvailableAssets(instrumentModel* model);
	void addToAvailableAssets(effectModel* model);
	void updateGUIMidiLists();
	void setActiveChannel(Channel* channel);
	void showInstrument(Instrument* instrument);
	void showEffect(Effect* effect);
	void updateActiveAssetsBay();
	void removeEffectFromActiveChannel();
	// GUI-triggered functions

	void setInstrumentForActiveChannel();
	void addEffectToActiveChannel();
	void removeInstrumentFromActiveChannel();

	void addNewChannel();

	void removeReverbEffect();
	void removeFlangerEffect();
	void removeVibratoEffect();
	void removeEq8BandEffect();
	void removeWahwahEffect();

	void loadData();

	void loadEffectsData(Json::Value effectsRoot);

	void loadSynthData(Json::Value synthRoot);


private:
	Ui::LeandroClass ui;
};
