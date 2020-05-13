#pragma once
//#include "Channel.h"
#include "Leandro.h"
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"
#include "Instrument.h"
#include "Effect.h"
#include "midiAssets.h"
#include "bufferAssets.h"
#include <list>
#include <queue>

using namespace std;

class Leandro;

typedef struct {
	midiTrack* currentMidiTrack;
	Instrument* instrument;
	vector<Effect*>* effects;
	float* volume;
	queue<midiEvent>* events;
}channelCallbackData;

typedef void channelCallback(	// Take midi file, select events in timeframe, synthesize notes into buffer.
	unsigned long frameCount,
	const __int64* currentSample,
	vector<timedBuffer*>* buffers,
	channelCallbackData* data
);

class Channel : public QObject{
public:
	channelCallbackData callData; // Data pointers to use callback

	Channel(int channelCreationCounter, Leandro* _program);
	~Channel();

	bool operator== (Channel const& channel);

	channelCallback callback;

	void updateCallbackData();

	void addToGUI(Ui_LeandroClass* programUI);
	void removeFromGUI(Ui_LeandroClass* programUI);

	// Setters
	void setChannelTrack(midiTrack* midiTrack); 
	void updateMidiTrack();
	void setChannelInstrument(Instrument* instrument);
	void addEffectToChannel(Effect* effect);
	
	// Functions called by user from GUI
	void setVolume();
	void setKeyboard();
	void setActive();
	void setInstFromGUI();
	
	queue<midiEvent> events; // Queue of events in the midi track the channel's currently playing
	QFrame* frameChannel;
	QVBoxLayout* verticalLayoutFrameChannel;
	QLabel* nameLabelChannel;
	QPushButton* setActiveButtonChannel;
	QPushButton* closeButtonChannel;
	QHBoxLayout* channelTopLayout;
	QSpacerItem* verticalSpacerChannel;
	QHBoxLayout* inputComboBoxLayoutChannel;
	QLabel* InputLabelChannel;
	QComboBox* inputComboBoxChannel;
	QListWidget* midiListChannel;
	QDial* levelDialChannel;
	QLabel* levelLabelChannel;

	QHBoxLayout* effectsLayout;
	QHBoxLayout* instrumentLayout;

	midiTrack* currentMidiTrack;
	Instrument* instrument; // Instance of instrument

	vector<Effect*> effects; // This channel's stack of effects

	Leandro* program;

private:
	int ID;
	float volume; // Volume multiplier between 0 and 1
	bool keyboard; // True if input is directly through keyboard

};