#pragma once

#define AVERAGE_SIZE	150

typedef void effectCallback(
	void* soundBuffer,
	const unsigned int maxSoundBufferSize,
	const int sampleRate
);

typedef enum {E_PLAIN, E_ECO, E_LOWPASS}mode_t;

class Effect
{
public:
	// Effect parameters here

	Effect();
	~Effect();
	virtual effectCallback callback;
protected:
	unsigned int getBufferSize(float* buffer); //Da el tamaño del buffer hasta el elemento que contenga INFINITY
	unsigned int copyBuffer2in(float* buffer, float* in, unsigned int maxSize); //Copia el array Buffer al array in, y devuelve el tamaño del buffer hasta el elemento INFINITY
	unsigned int setBufferCrap2zero(float* buffer, unsigned int maxBufferSize); //Setea todo la mierda del buffer en 0, y devuelve el tamaño efectivo del buffer
	float getAverage();
	void setArray2zero(float* arr, unsigned int size);
	void pushBackandPop(float element);
	bool isEffectFinished();
	void restartAverage();
	float average[AVERAGE_SIZE];
	bool avgFull;
	unsigned int avgPtr;
};

class ReverbEffect : public Effect
{
public:
	ReverbEffect(mode_t mode = E_PLAIN, float delay = 0.2, float att = 0.5, unsigned int maxSoundBufferSize = (44e3 * 15));  //Modo tipo plano, Eco, o lowpass. Tiempo de delay en segundos, attenuacion. (Valores sugeridos (E_PLAIN,0.5,0.5))
	~ReverbEffect();
	effectCallback callback;
protected:
	short int mode;
	float delay;
	float a;
	float* x;
};

class FlangerEffect : public Effect {
public:
	FlangerEffect(float fo = 0.5, float Mw = 5, float Mo = 1e-3, float g_fb = 0.3, float g_ff = 0.9, const int sampleRate = 44e3, unsigned int maxSoundBufferSize = (44e3 * 15));	// Frecuencia del LFO fo. (valores sugeridos (0.5,1e-3,5,0.3,0.9,sampleRate))
	~FlangerEffect();
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

class VibratoEffect : public Effect {
public:
	VibratoEffect(float W = 1e3, float fo = 10, float M_avg = 10, const int sampleRate = 44e3, unsigned int maxSoundBufferSize = (44e3 * 15)); // W para la cual queremos que esto funcione, frecuencia del LFO fo, Distancia average (Valores sugeridos (1e3,5,0.5))
	~VibratoEffect();
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
	float A, B, C, D;
}filter1_t;

typedef struct {
	float A, B, C, D,E;
}filter2_t;

class EqualizatorEffect : public Effect {
	//Habria que corregirle algunos parametros para que suene mejor
public:
	EqualizatorEffect(float gainLow = 0.5, float gainMid = 0.5, float gainHigh = 0.5, unsigned int maxSoundBufferSize = 44e3*15); //Las ganancias en porcentajes de 0 a 1, en 0 atenua 12dB y en 1 amplifica 12dB
	~EqualizatorEffect();
	effectCallback callback;
	void changeGains(float gainLow, float gainMid, float gainHigh);
protected:
	void compFilterParameters();
	float gainLow, gainMid, gainHigh;
	filter1_t lowFilter;
	filter1_t highFilter;
	filter2_t midFilter;
	float* x;
};

typedef struct {
	float b0, b1, b2, a0, a1, a2;
}wahFilter_t;

class WahwahEffect : public Effect {
public:
	WahwahEffect(float f_min = 400, float f_LFO = 3, unsigned int samplingRate = 44e3, unsigned int maxBufferSize = (44e3*15));
	~WahwahEffect();
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
