#pragma once

typedef void effectCallback(
	void* soundBuffer,
	const unsigned int soundBufferSize,
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
};

class reverbEffect : public Effect
{
public:
	reverbEffect(mode_t mode, float delay, float att);  //Modo tipo plano, Eco, o lowpass. Tiempo de delay en segundos, attenuacion. (Valores sugeridos (E_PLAIN,0.5,0.5))
	//~reverbEffect();
	effectCallback callback;
protected:
	short int mode;
	float delay;
	float a;
};

class flangerEffect : public Effect {
public:
	flangerEffect(float fo, float Mo, float g_fb, float g_ff);	// Frecuencia del LFO fo. (valores sugeridos (0.5,1e-3,0.3,0.9))
	~flangerEffect();
	effectCallback callback;
protected:
	float fo;
	float Mo;
	float g_fb;
	float g_ff;
	float* in;
private:
	float linearInterpolation(float num, float * in);
};

class vibratoEffect : public Effect {
public:
	vibratoEffect(float W, float fo, float M_avg); // W para la cual queremos que esto funcione, frecuencia del LFO fo, Distancia average (Valores sugeridos (1e3,5,0.5))
	~vibratoEffect();
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
