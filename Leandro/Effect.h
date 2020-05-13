#pragma once
#include <QtWidgets/QFrame>
#define AVERAGE_SIZE	100

typedef void effectCallback(
	void* soundBuffer,
	const unsigned int maxSoundBufferSize,
	const int sampleRate
);

typedef enum { E_PLAIN, E_ECO, E_LOWPASS }mode_t;

enum class effectType{ reverb, flanger, vibrato, wahwah };

class Effect
{
public:
	// Effect parameters here

	Effect();
	~Effect();
	virtual effectCallback callback;
	QFrame* effectFrame;

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

typedef struct {
	mode_t mode;
	float delay;
	float att;
	unsigned int maxSoundBufferSize;
}reverbParams_t;

class ReverbEffect : public Effect
{
public:
	ReverbEffect(reverbParams_t* _params);//mode_t mode = E_PLAIN, float delay = 0.2, float att = 0.5, unsigned int maxSoundBufferSize = (44e3 * 15));  //Modo tipo plano, Eco, o lowpass. Tiempo de delay en segundos, attenuacion. (Valores sugeridos (E_PLAIN,0.5,0.5))
	~ReverbEffect();
	effectCallback callback;
protected:
	short int mode;
	float delay;
	float a;
	float* in;
};

typedef struct {
	float fo;
	float Mw;
	float Mo;
	float g_fb;
	float g_ff;
	const int sampleRate;
	unsigned int maxSoundBufferSize;
}flangerParams_t;

class FlangerEffect : public Effect {
public:
	FlangerEffect(flangerParams_t* _params);	// Frecuencia del LFO fo. (valores sugeridos (0.5,1e-3,5,0.3,0.9,sampleRate))
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

typedef struct {
	float W;
	float fo;
	float M_avg;
	const int sampleRate;
	unsigned int maxSoundBufferSize;
}vibratoParams_t;

class VibratoEffect : public Effect {
public:
	VibratoEffect(vibratoParams_t* _params); // W para la cual queremos que esto funcione, frecuencia del LFO fo, Distancia average (Valores sugeridos (1e3,5,0.5))
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


typedef struct {
	float damping;
	float width;
	float min_cutoff;
	float max_cutoff;
}wahwahParams_t;
/*
class wahwahEffect : public Effect {
public:
	wahwahEffect(wahwahParams_t* _params);
	effectCallback callback;
protected:
	float damping;
	float width;
	float min_cutoff;
	float max_cutoff;
};*/
