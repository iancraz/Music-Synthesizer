#pragma once
#include <QtWidgets/QFrame>

#define AVERAGE_SIZE	150


typedef void effectCallback(
	void* soundBuffer,
	const unsigned int maxSoundBufferSize,
	const int sampleRate
);

typedef enum {E_PLAIN, E_ECO, E_LOWPASS}mode_t;

enum class effectType { reverb, flanger, vibrato, wahwah, eq8band, tremolo };

class Effect {
public:
	// Effect parameters here

	Effect();
	~Effect();
	virtual effectCallback callback;
	effectType type;

protected:
	unsigned int getBufferSize(float* buffer); //Da el tamao del buffer hasta el elemento que contenga INFINITY
	unsigned int copyBuffer2in(float* buffer, float* in, unsigned int maxSize); //Copia el array Buffer al array in, y devuelve el tama?o del buffer hasta el elemento INFINITY
	unsigned int setBufferCrap2zero(float* buffer, unsigned int maxBufferSize); //Setea todo la mierda del buffer en 0, y devuelve el tama?o efectivo del buffer
	float getAverage();
	void setArray2zero(float* arr, unsigned int size);
	void pushBackandPop(float element);
	bool isEffectFinished();
	void restartAverage();
	float average[AVERAGE_SIZE];
	bool avgFull;
	unsigned int avgPtr;
};

typedef struct {
	mode_t mode;
	float delay;
	float att;
	unsigned int maxSoundBufferSize;
}reverbParams_t;

class ReverbEffect : public Effect {
public:
	//ReverbEffect(mode_t mode = E_PLAIN, float delay = 0.2, float att = 0.5, unsigned int maxSoundBufferSize = (44e3 * 15));
	ReverbEffect(reverbParams_t* _params);
	//Existen 3 modos de uso:	E_PLAIN   -> REVERBERACION PLANA
	//							E_ECO     -> DELAY SIMPLE
	//							E_LOWPASS -> REVERBERACI?N PLANA CON PASABAJOS SIMPLE
	//Los parametros disponibles al usuario deben ser los siguientes para cada caso: (Se puede jugar, pero se recomienda mantenerse dentro de los intervalos dados)
	//	E_PLAIN:
	//				delay = [0 ; 3]
	//				att = [0 ; 0.99]
	//	E_ECO:
	//				delay [0 ; 3]
	//				att = [0 ; 0.99]
	//	E_LOWPASS:
	//				delay [0 ; 3]
	//				att = [0 ; 0.99]
	~ReverbEffect();
	float getDelay();
	float getAtt();
	int getMode() { return mode; }
	void setDelay(float dly);
	void setAtt(float att);
	effectCallback callback;
protected:
	short int mode;
	float delay;
	float a;
	float* x;
};

typedef struct {
	float fo;
	int sampleRate;
	unsigned int maxSoundBufferSize;
	float Mw;
	float Mo;
	float g_fb;
	float g_ff;
}flangerParams_t;

class FlangerEffect : public Effect {
public:
	//FlangerEffect(float fo = 0.5, const int sampleRate = 44e3, unsigned int maxSoundBufferSize = (44e3 * 15), float Mw = 5, float Mo = 1e-3, float g_fb = 0.3, float g_ff = 0.9);
	FlangerEffect(flangerParams_t* _params);
	//Si bien se pueden configurar muchos parmetros, lo recomendable es solamente cambiar fo
	//El intervalo de fo debe estar dado entre:
	//				fo = [0.1 ; 5]
	~FlangerEffect();
	float getFo();
	float getGFB() { return g_fb; }
	float getM0() { return Mo; }
	float getGFF() { return g_ff; }
	float getMw() { return Mw; }

	void setFo(float fo);
	void setGFB(float GFB) { g_fb = GFB; }
	void setM0(float M0) { Mo = M0; }
	void setGFF(float GFF) { g_ff = GFF; }
	void setMw(float Mw) { this->Mw = Mw; }
	effectCallback callback;
protected:
	float fo;
	float Mo;
	float Mw;
	float g_fb;
	float g_ff;
	float* x;
private:
	float linearInterpolation(float num, float* in);
};

typedef struct {
	float fo;
	int sampleRate;
	unsigned int maxSoundBufferSize;
	float W;
	float M_avg;
}vibratoParams_t;

class VibratoEffect : public Effect {
public:
	//VibratoEffect( float fo = 10, const int sampleRate = 44e3, unsigned int maxSoundBufferSize = (44e3 * 15), float W = 1e3, float M_avg = 10);
	VibratoEffect(vibratoParams_t* _params);
	//Si bien se pueden configurar muchos parmetros, lo recomendable es solamente cambiar fo
	//El intervalo de fo debe estar dado entre:
	//				fo = [0.5 ; 20]
	~VibratoEffect();
	float getFo();
	float getMavg() { return M_avg; }
	float getWidth() { return W; }
	void setFo(float fo);
	void setWidth(float width) { W = width; }
	void setMavg(float mavg) { M_avg = mavg; }
	effectCallback callback;
protected:
	float W;
	float fo;
	float* x;
	float* comodin;
	float M_avg;
private:
	float linearInterpolation(float num);
};

typedef struct {
	float f_min;
	float f_LFO;
	unsigned int samplingRate;
	unsigned int maxBufferSize;
}wahwahParams_t;

typedef struct {
	float b0, b1, b2, a0, a1, a2;
}wahFilter_t;

class WahwahEffect : public Effect {
public:
	//WahwahEffect(float f_min = 400, float f_LFO = 3, unsigned int samplingRate = 44e3, unsigned int maxBufferSize = (44e3*15));
	WahwahEffect(wahwahParams_t* _params);
	//Para el wah-wah el usuario debe poder modificar f_min y f_LFO, los intervalos son:
	//			f_min = [200 ; 1000]
	//			f_LFO = [0.2 ; 5]
	~WahwahEffect();
	float getFmin();
	float getFLFO();
	void setFmin(float f);
	void setFLFO(float f);
	effectCallback callback;
protected:
	float getFrecuency(unsigned int n);
	wahFilter_t getFilterParameters(float K);
	float width;
	float f_min;
	float f_LFO;
	float G_c;
	float Q;
	unsigned int samplingRate;
	float* x;
};

typedef struct {
	float gains[8]; //gains[0] = ganancia de la banda mas baja, gains[7]= ganancia de la banda mas aguda
	float sampleRate;
	float maxSoundBufferSize;
}eq8bandParams_t;

typedef struct {
	float gains[8];
}gains_t;

typedef struct {
	float A, B, C, D;
}filter1_t;

typedef struct {
	float A, B, C, D, E;
}filter2_t;

class Eq8BandEffect : public Effect {
public:
	Eq8BandEffect(eq8bandParams_t* _params);
	~Eq8BandEffect();
	gains_t getGains();
	void setGains(gains_t g);
	effectCallback callback;
protected:
	void changeGains(eq8bandParams_t* _params);
	void compFilterParameters();
	void defineFrequencies(eq8bandParams_t* _params);
	void defineBandwidth();
	float g[8];
	float f[8];
	float B[8];
	float* x;
	filter2_t tf[8];
	unsigned int numberOfBands = 8;
	float freqMin = 100;
	float freqMax = 20e3;
};

typedef struct {
	float gainLow;
	float gainMid;
	float gainHigh;
	unsigned int maxSoundBufferSize;
	unsigned int sampleRate;
}equalizatorParams_t;

class EqualizatorEffect : public Effect {
	//Habria que corregirle algunos parametros para que suene mejor
public:
	//EqualizatorEffect(float gainLow = 0.5, float gainMid = 0.5, float gainHigh = 0.5, unsigned int maxSoundBufferSize = 44e3*15); //Las ganancias en porcentajes de 0 a 1, en 0 atenua 12dB y en 1 amplifica 12dB
	EqualizatorEffect(equalizatorParams_t* _params);
	// En el ecualizador se puede dar la ganancia deseada a discrecion, los valores mximos y minimos para cada una sern:
	//			gainLow = [0 ; 1]
	//			gainMid = [0 ; 1]
	//			gainHig = [0 ; 1]
	~EqualizatorEffect();
	float getGainMid();
	float getGainLow();
	float getGainHigh();
	void setGainLow(float g);
	void setGainMid(float g);
	void setGainHigh(float g);
	effectCallback callback;
	void changeGains(float gainLow, float gainMid, float gainHigh);
protected:
	void compFilterParameters();
	float gainLow, gainMid, gainHigh;
	float highFreq, lowFreq, midFreq, midB;
	filter1_t lowFilter;
	filter1_t highFilter;
	filter2_t midFilter;
	float* x;
};

typedef struct {
	float alpha, f_lfo;
	unsigned int sampleRate;
}tremoloParams_t;

class TremoloEffect : public Effect {
public:
	TremoloEffect(tremoloParams_t* _params);
	~TremoloEffect();
	effectCallback callback;
protected:
	float alpha;
	float f_lfo;
};