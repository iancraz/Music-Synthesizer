#include "Instrument.h"
#include "json/json.h"
#include <string>


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
	void synthNote(float* outputBuffer,
				   const unsigned int outputBufferSize,
				   const int keyNumber,
				   const float lengthInMilisecnds,
				   const int velocity,
				   const int sampleRate);

	static additiveParams_t parseAdditiveJson(Json::Value _data);
	static vector<float*> parseEnvelopeFile(std::string path, vector<int>* envelopesLengths);
	
protected:
	unsigned int firstKey;
	unsigned int lastKey;
	unsigned int harmonicsCount;
	std::vector<int> envelopeLengths;
	std::vector<std::vector<float*>> octavesEnvelopes;
};