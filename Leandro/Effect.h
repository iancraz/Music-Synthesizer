#pragma once

#define AVERAGE_SIZE	100

typedef void effectCallback(
	void* soundBuffer,
	const unsigned int maxSoundBufferSize,
	const int sampleRate
);

typedef enum { E_PLAIN, E_ECO, E_LOWPASS }mode_t;

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
	float* in;
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
	float* in;
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
	float* in;
	float* comodin;
	float M_avg;
private:
	float linearInterpolation(float num);
};

/*
class wahwahEffect : public Effect {
public:
	wahwahEffect(float damping, float width, float min_cutoff, float max_cutoff);
	effectCallback callback;
protected:
	float damping;
	float width;
	float min_cutoff;
	float max_cutoff;
};*/
