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
#include<list>
#include<vector>
#include <fstream>

#define SAMPLE_RATE (44100)
#define MAX_SIMULTANEOUS_NOTES_PER_CHANNEL 15
#define MAX_NOTE_LENGTH_SECONDS 10
#define	ACTIVE_BUFFER_FRAME_SIZE 44100

using namespace std;

class Channel;

typedef struct {
	vector<timedBuffer*>* buffers;
	float* activeBuffer;
	__int64* currentSample;
	vector<Channel*>* channels;
	ofstream* debugStream;
}callbackData;

typedef struct {
	string instrumentName;
	synthType type;
	void* params;
}instrumentModel;


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

	float* activeBuffer;

	~Leandro();

	static PaStreamCallback callback;

	void addChannel(Channel* newChannel);
	void destroyChannel(Channel* channel);

	void addMidiFile(string directory, string filename, bool autoSet);
	void updateCallbackData();

	void loadData();
	vector<instrumentModel*> instrumentModels;
private:
	Ui::LeandroClass ui;


};
