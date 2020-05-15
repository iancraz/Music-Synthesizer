#pragma once
#include "bufferAssets.h"
#include "Leandro.h"
#include "Channel.h"
#include "json/json.h"
#include "Sample.h"

#define MAX_LOOP_TIME (0.370)
#define MIN_LOOP_TIME (0.)


using namespace std;

typedef int instrumentCallback(
	float* outputBuffer,
	const unsigned int outputBufferSize,
	const int keyNumber,
	const float lengthInMilliseconds,
	const int velocity,
	const int sampleRate
);

enum class synthType { adsr, additive, fm, karplus, sampling };
enum waveform{ sine, square, sawtooth };

class Instrument {
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
	short int getWF1() { return wform1; }
	float getWF1Level() { return level1; }
	short int getWF2() { return wform2; }
	float getWF2Level() { return level2; }
	float getAttack() { return params->tAttack; }
	float getDecay() { return params->tDecay; }
	float getSustainRate() { return params->sustainRate; }
	float getSustainLevel() { return params->sustainLevel; }
	float getRelease() { return params->tRelease; }

	// Setters
	void setWF1(int _waveform) { wform1=_waveform; }
	void setWF1Level(float _level) { level1=_level; }
	void setWF2(int _waveform) { wform2 = _waveform; }
	void setWF2Level(float _level) { level2 = _level; }
	void setAttack(float _seconds) { params->tAttack = _seconds; }
	void setDecay(float _seconds) { params->tDecay = _seconds; }
	void setSustainRate(float _rate) { params->sustainRate = _rate; }
	void setSustainLevel(float _level) { params->sustainLevel = _level; }
	void setRelease(float _seconds) { params->tRelease = _seconds; }

	void setParams(adsrParams_t* params);

protected:
	adsrParams_t* params;
	instrumentCallback synthFunction;
	int generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength);
	void scheduleEnvelopeUpdate();
	float* envelope;
	float* release;

	float* envBuffer;
	float* relBuffer;


	short int wform1;
	float level1;
	
	short int wform2;
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
	float getHarmonicFactor(int index) { return harmonicFactors[index]; }
	void setHarmonicFactor(int index, float value);

protected:
	vector<float> harmonicFactors;
	unsigned int firstKey;
	unsigned int lastKey;
	unsigned int harmonicsCount;
	std::vector<int> envelopeLengths;
	std::vector<std::vector<float*>> octavesEnvelopes;
	float*** envelopes;
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


	int getLoopBegin() {
		return (int)(100. * repeat_time_begin / MAX_LOOP_TIME);
	}

	int getLoopEnd() {
		return (int)(100. * repeat_time_end / MAX_LOOP_TIME);
	}

	void setLoopBegin(int new_repeat_time_begin) {
		repeat_time_begin = (float)(new_repeat_time_begin)*MAX_LOOP_TIME / 100.;
	}
	void setLoopEnd(int new_repeat_time_end) {
		repeat_time_end = (float)(new_repeat_time_end)*MAX_LOOP_TIME / 100.;
	}


	int synthFunction(float* outputBuffer, const unsigned int outputBufferSize, const int keyNumber, const float lengthInMilliseconds, const int velocity, const int sampleRate);

	static samplingParams_t* parseSamplingJson(Json::Value data);

private:
	vector <Sample*>* samples;

	int min_octave;
	int	max_octave;

	float repeat_time_begin; //Tiempo a partir del cual se empieza a repetir en caso en que se desee un tiempo de presionado de nota mayor al sample
	float repeat_time_end; //Limite del tiempo de repeticion

	float* temp_buffer;
	float* temp_buffer_2;
	int lenght_temp_buffer;
	//float note_pressed_time;
	int get_nearest_peak(Sample* selected_sample, int number);
	void key_modification(int num_octava, float B, float new_note_pressed_time);
	
};


// Macro enumeration for default instruments
typedef enum { PLUNKED_CORD, DRUM } alg_t;
// Enumeration for random generation  noise type
typedef enum { UNIFORM_RANDOM, NORMAL_RANDOM } noise_t;

//Karplus parameters structure
typedef struct {
	// Random generation distribution for noise
	noise_t noiseType;
	// Decay loss factor with value between 0 and 1. Default value 1.
	float Grl;
	// Blend factor with values between 0 and 1. Plunked cord for 1. Drums with 0.5.
	float BFactor;
	// Stretch factor multiply the decay time. Values between 1 and infinity. Not stretched algorithm (default) with 1.
	float SFactor;
	// Digital filter for guitar body reaction.
	bool bodyFilter = false;
}karPlusParams_t;

class karplusInstrument : public Instrument {
public:
	// Parameter declarations for Karplus-Strong algorhythm based instruments here
	// Default constructor for regular parameters.
	karplusInstrument(karPlusParams_t* _params);
	// Default constructor for predefined parameters with macro enumerations.
	karplusInstrument(alg_t type);
	// syntFunction for note synthesis defined at parent class
	instrumentCallback synthFunction;
	// Getters functions
	float getSFactor();
	float getBFactor();
	float getRlFactor();
	// Setters function which return is 0 for valid value and -1 for error values.
	int setSFactor(float number);
	int setBFactor(float number);
	int setRlFactor(float number);
	// Body filter mode
	void activeFilter();
	void deactiveFilter();
	bool filterStatus() { return params.bodyFilter; }
protected:
	// Instruments parameters defined by macros.
	int plunkedCordSet();
	int drumSet();

	// Karplus synthesis parametters.
	karPlusParams_t params;

	// Function algResponse: general algorithm for stretched drums which can be plunked cord adapted.
	// Input:	Float pointer (table) to row table with relative frecuency value (p) size.
	//			Input buffer float pointer (table). Relative frecuency value (p). 
	//			Output number of samples (n_samples).
	int algResponse(float* table, float* buffer, const unsigned int p, const unsigned int n_samples);

	// Function bodyFilter: Digital filter which emulate the body shape effect on the generate sound.
	// Input:	Float pointer for input buffer (bufferIn) and output buffer (bufferOut). Buffer size (size).
	//			Float type filter parameters a1, a2 and t.
	int karplusInstrument::bodyFilter(float* bufferIn, float* bufferOut, const unsigned int size, float fc, int fs, float deltaf);
};