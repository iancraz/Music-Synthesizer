#pragma once
#include "bufferAssets.h"
#include "Sample.h"
#include "json/json.h"
#include <string>

using namespace std;

typedef int instrumentCallback(
	float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float lengthInMilliseconds,
	const int velocity,
	const int sampleRate
);

enum class synthType { additive, fm, karplus, sampling };

class Instrument {
public:
	synthType type;
	int instrumentID;
	string instrumentName;
	virtual instrumentCallback synthFunction; // Instrument callback function: defined by typedef
};

class KarplusInstrument : public Instrument {
public:
	// Parameter declarations for Karplus-Strong algorhythm based instruments here

	KarplusInstrument();
	~KarplusInstrument();
};

class SamplingInstrument : public Instrument {
public:

	SamplingInstrument(int num_instrument, const unsigned int buffLength);
	~SamplingInstrument();

	float repeat_time_begin; //Tiempo a partir del cual se empieza a repetir en caso en que se desee un tiempo de presionado de nota mayor al sample
	float repeat_time_end; //Limite del tiempo de repeticion


	int synthFunction(float* outputBuffer, const unsigned int outputBufferSize, const int keyNumber, const float lengthInMilliseconds, const int velocity, const int sampleRate);

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

typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
}adsrParams_t;

class ADSRInstrument : public Instrument {
public:
	ADSRInstrument(adsrParams_t* _params, const unsigned int buffLength, const unsigned int sampleRate);
	~ADSRInstrument() {}
	void setParams(adsrParams_t* params);

protected:
	adsrParams_t params;
	instrumentCallback synthFunction;
	int generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength);

	float* envelope;
	float* release;
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
	AdditiveInstrument(additiveParams_t params, unsigned int bufferLength);
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
