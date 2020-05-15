#pragma once

#include <QtWidgets/QMainWindow>
#include <qiconengineplugin.h>
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
#define MAX_SIMULTANEOUS_NOTES_PER_CHANNEL 40
#define MAX_NOTE_LENGTH_SECONDS 15
#define	ACTIVE_BUFFER_FRAME_SIZE 44100
#define MAX_WAV_SIZE (SAMPLE_RATE * 60 * 6)

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

	//ESTO AGREGO IANNNN
	float* wav;
	unsigned int * wavCounter;
	bool recordFlag;
	bool specgramFlag;
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
	vector<QFrame*> channelFrames;
	vector<QListWidget*>midiLists;
	float* activeBuffer;
	Channel* activeChannel;

	~Leandro();

	static PaStreamCallback callback;
	void updateCallbackData();

	void addChannel(Channel* newChannel);
	void destroyChannel(Channel* channel);
	void addMidiFile(string filename, bool autoSet = true);
	
	void loadMidiFile();

	//void addMidiFile(string directory, string filename, bool autoSet);
	int getFirstFreeChannelFrame();

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
	void startStreaming();
	void pauseStreaming();
	void stopStreaming();

	void instrumentValueChanged();
	void reverbValueChanged();
	void flangerValueChanged();
	void vibratoValueChanged();
	void eq8BandValueChanged();
	void wahwahValueChanged();


	void removeReverbEffect();
	void removeFlangerEffect();
	void removeVibratoEffect();
	void removeEq8BandEffect();
	void removeWahwahEffect();

	void loadData();

	void loadEffectsData(Json::Value effectsRoot);

	void loadSynthData(Json::Value synthRoot);
	void loadTestMidi();

	void channel1Closed();
	void channel1setActive();
	void channel1InputChanged();
	void channel1VolChanged();
	void channel1TrackChanged();

	void channel2Closed();
	void channel2setActive();
	void channel2InputChanged();
	void channel2VolChanged();
	void channel2TrackChanged();

	void channel3Closed();
	void channel3setActive();
	void channel3InputChanged();
	void channel3VolChanged();
	void channel3TrackChanged();

	void channel4Closed();
	void channel4setActive();
	void channel4InputChanged();
	void channel4VolChanged();
	void channel4TrackChanged();

	void channel5Closed();
	void channel5setActive();
	void channel5InputChanged();
	void channel5VolChanged();
	void channel5TrackChanged();

	void channel6Closed();
	void channel6setActive();
	void channel6InputChanged();
	void channel6VolChanged();
	void channel6TrackChanged();

	void channel7Closed();
	void channel7setActive();
	void channel7InputChanged();
	void channel7VolChanged();
	void channel7TrackChanged();

	void channel8Closed();
	void channel8setActive();
	void channel8InputChanged();
	void channel8VolChanged();
	void channel8TrackChanged();

	void channel9Closed();
	void channel9setActive();
	void channel9InputChanged();
	void channel9VolChanged();
	void channel9TrackChanged();

	void channel10Closed();
	void channel10setActive();
	void channel10InputChanged();
	void channel10VolChanged();
	void channel10TrackChanged();



	void calcSpecgram();

private:
	Ui::LeandroClass ui;
	bool recordFlag;
	bool specgramFlag;
	void record2Wav();
	void restarWavRecording();
	float* wav;
	unsigned int wavCounter;


};
