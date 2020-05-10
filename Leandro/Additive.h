#include "Instrument.h"

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