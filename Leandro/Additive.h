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
	additiveInstrument(adsrParams_t _params);
	~additiveInstrument() {}

protected:
	adsrParams_t params;
	instrumentCallback synthFunction;
};