#include "Instrument.h"
#include <string>

typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float sustainLevel;
	float tRelease;
	float k;
}adsrParams_t;

class additiveInstrument : public Instrument {
public:
	additiveInstrument(adsrParams_t* _params, const unsigned int buffLength, const unsigned int sampleRate);
	~additiveInstrument() {}
	void setParams(adsrParams_t* params);

protected:
	adsrParams_t params;
	instrumentCallback synthFunction;
	int generateEnvelope(const unsigned int sampleRate, const unsigned int buffLength);

	float* envelope;
	float* release;
};

class AdditiveInstrument : public Instrument {
public:
	AdditiveInstrument(std::string envelope_file, std::string _name);
private:
	instrumentCallback synthFunction;
	float* envelope[7];
	int envelopeLength;
	int releaseLength;
	float* release;
};