#include "Instrument.h"

typedef struct {
	float tAttack;
	float tDecay;
	float sustainRate;
	float tRelease;
	float k;
}adsrParams_t;

class additiveInstrument : public Instrument {
public:
	additiveInstrument(adsrParams_t _params, const unsigned int buffLength);
	~additiveInstrument() {}

protected:
	adsrParams_t params;
	instrumentCallback synthFunction;
	int generateEnvelope(float lengthInMilisecods,
						 float A0,
						 int sampleRate);
	float* envelope;
};