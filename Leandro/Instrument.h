#pragma once
#include "portaudio.h"
#include "midifile.h"
#include "Options.h"
#include "bufferAssets.h"
#include "Leandro.h"
#include "Channel.h"
#include "json/json.h"
#include "Sample.h"

using namespace std;
using namespace smf;

typedef int instrumentCallback(
	float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float lengthInMilliseconds,
	const int velocity,
	const int sampleRate
);

enum class synthType { adsr, additive, fm, karplus, sampling };
typedef enum { sine, square, sawtooth }waveform;


class Instrument
{
public:
	synthType type;
	int instrumentID;
	string instrumentName;
	
	virtual instrumentCallback synthFunction; // Instrument callback function: defined by typedef
	
};

typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
	waveform wform1;
	float level1;
	waveform wform2;
	float level2;
	unsigned int buffLength;
	unsigned int sampleRate;
}adsrParams_t;

class ADSRInstrument : public Instrument {
public:
	ADSRInstrument(adsrParams_t* _params);
	~ADSRInstrument() {}

	// Getters
	waveform getWF1() { return wform1; }
	float getWF1Level() { return level1; }
	waveform getWF2() { return wform2; }
	float getWF2Level() { return level2; }
	float getAttack() { return params->tAttack; }
	float getDecay() { return params->tDecay; }
	float getSustainRate() { return params->sustainRate; }
	float getSustainLevel() { return params->sustainLevel; }
	float getRelease() { return params->tRelease; }

	void setParams(adsrParams_t* params);

protected:
	adsrParams_t* params;
	instrumentCallback synthFunction;
	int generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength);

	float* envelope;
	float* release;

	waveform wform1;
	float level1;
	
	waveform wform2;
	float level2;


};

typedef struct {
	std::string name;
	unsigned int octavesCount;
	unsigned int harmonicsCount;
	vector<int> envelopeLengths;
	unsigned int firstKey;
	unsigned int lastKey;
	vector<vector<float*>> octavesEnvelopes;
}additiveParams_t;

class AdditiveInstrument : public Instrument {
public:
	AdditiveInstrument(additiveParams_t * params);
	instrumentCallback synthFunction;

	static additiveParams_t parseAdditiveJson(Json::Value _data);
	static vector<float*> parseEnvelopeFile(std::string path, vector<int>* envelopesLengths);

protected:
	unsigned int firstKey;
	unsigned int lastKey;
	unsigned int harmonicsCount;
	std::vector<int> envelopeLengths;
	std::vector<std::vector<float*>> octavesEnvelopes;
	float*** envelopes;
};

typedef struct {

}karplusParams_t;

class KarplusInstrument : public Instrument {
public:
	// Parameter declarations for Karplus-Strong algorhythm based instruments here

	KarplusInstrument(karplusParams_t* _params);
	~KarplusInstrument();
};


typedef struct {
	vector<Sample*>* samples;
	int minOctave;
	int maxOctave;
	float notePressedTime;
	string name;
	unsigned int buffLength;
}samplingParams_t;

class SamplingInstrument : public Instrument {
public:

	SamplingInstrument(samplingParams_t * params);
	~SamplingInstrument();

	float repeat_time_begin; //Tiempo a partir del cual se empieza a repetir en caso en que se desee un tiempo de presionado de nota mayor al sample
	float repeat_time_end; //Limite del tiempo de repeticion


	int synthFunction(float* outputBuffer, const unsigned int outputBufferSize, const int keyNumber, const float lengthInMilliseconds, const int velocity, const int sampleRate);

	static samplingParams_t * parseSamplingJson(Json::Value data);
	
private:
	vector <Sample*>* samples;

	int min_octave;
	int	max_octave;

	float* temp_buffer;
	float* temp_buffer_2;
	int lenght_temp_buffer;
	float note_pressed_time;
	int get_nearest_peak(Sample* selected_sample, int number);
	void key_modification(int num_octava, float B, float new_note_pressed_time);
	void velocityAdjust(int velocity);
};