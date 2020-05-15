#include "Instrument.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <random>

using namespace std;

karplusInstrument::karplusInstrument(karPlusParams_t* _params) {
	this->type = synthType::karplus;
    params.BFactor = _params->BFactor;
    params.Grl = _params->Grl;
    params.SFactor = _params->SFactor;
    params.bodyFilter = _params->bodyFilter;
}

karplusInstrument::karplusInstrument(alg_t type) {
    if (type == PLUNKED_CORD)
        plunkedCordSet();
    else if (type == DRUM)
        drumSet();
}

int karplusInstrument::synthFunction(float* outputBuffer,const unsigned int outputBufferSize,
		const int keyNumber, const float lengthInSeconds, const int velocity, const int sampleRate) {
    unsigned int p;
    // Parameter definition
    float freq = 440.0 * pow(2, (keyNumber - 69) / 12);
    float A0 = (float)velocity / 127.0;
    float pf = (sampleRate/freq)-0.5;
    // Table definition
    unsigned int lenght = (unsigned int) (lengthInSeconds * sampleRate);
    if ((pf-ceilf(pf)) > (floorf(pf)-pf))
        p = (unsigned int) (floorf(pf));
    else
        p = (unsigned int) (ceilf(pf));
    float * table = nullptr;
    table = new float[p];
    // Random generator for initial noise
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1);
    for(int i=0; i < p; i++) {
        if (distribution(generator) == 0)
            *(table + i) = A0;
        else
            *(table + i) = (-1.0)*A0;
    }
    // Algorithm execution
    int len = lenght < outputBufferSize ? lenght : outputBufferSize;
    algResponse(table,outputBuffer,p,len);
    // Body filter
    if (params.bodyFilter == true) {
        bodyFilter(outputBuffer,outputBuffer,44100,freq,sampleRate,1);
        for (int j = 0; j < outputBufferSize; j++) {
            if (abs(outputBuffer[j]) > (float)(1.0))
                outputBuffer[j] = (float)(outputBuffer[j]/abs(outputBuffer[j]));
        }
    }
    // Termination element
    outputBuffer[lenght] = INFINITY;
    delete[] table;
    return 0;        
}

int karplusInstrument::algResponse(float * table, float * buffer, const unsigned int p,const unsigned int n_samples) {
    unsigned int current_sample = 0;
    unsigned int samples = 0;
    float previous_value = 0;
    // Random noise generation
    std::random_device rd;
    std::mt19937 engine(rd()); // Mersenne twister MT19937
    // Probability boundaries
    unsigned int P_1 = params.BFactor*(1-1/params.SFactor)*100;
    unsigned int P_2 = (1-params.BFactor)*(1-1/params.SFactor)*100;
    unsigned int P_3 = (params.BFactor*1/params.SFactor)*100;
    unsigned int P_4 = (1-params.BFactor)*(1/params.SFactor)*100;
    //Algorithm implementation
    while (samples < n_samples) {
        unsigned int pb;
        if (params.noiseType == UNIFORM_RANDOM) {
            std::uniform_int_distribution<int> distribution(1, 100); // Uniform distribution
            pb = (unsigned int) (distribution(engine)); // Random number
        } else {
            std::normal_distribution<double> distribution(50,20); // Normal distribution
            pb = (unsigned int) (distribution(engine)); // Random number
        }
        if ((pb > P_1) && (pb <= P_1+P_2))
            *(table+current_sample) *= (float)(-1);
        else if ((pb > P_1+P_2) && (pb <= P_1+P_2+P_3))
            *(table+current_sample) = (float)(params.Grl*(*(table+current_sample)*0.5 + previous_value*0.5));
        else if ((pb > P_1+P_2+P_3) && (pb <= P_1+P_2+P_3+P_4))
            *(table+current_sample) = (float)(params.Grl*(*(table+current_sample)*(-0.5) + previous_value*(-0.5)));
        *(buffer+samples) = *(table+current_sample);
        previous_value = *(buffer+samples);
        samples++;
        current_sample += 1;
        current_sample = current_sample % p;
    }
    return (0);
}
int karplusInstrument::plunkedCordSet() {	
    params.noiseType = NORMAL_RANDOM;
	params.BFactor = 1;
	params.Grl = 1;
	params.SFactor = 1;
    params.bodyFilter = false;
	return 0;
}

int karplusInstrument::drumSet() {
    params.noiseType = NORMAL_RANDOM;
	params.BFactor = 0.5;
	params.Grl = 1;
	params.SFactor = 1.05;
    params.bodyFilter = false;
	return 0;
}

int karplusInstrument::bodyFilter(float * bufferIn, float * bufferOut, const unsigned int size, float fc, int fs, float deltaf)
{
    int n = 0;
    float xn_1,xn_2,yn_1,yn_2,b1,b2,r;
    b1 = (-2) * cos(2 * M_PI * fc / fs);
    r = 1-(M_PI*deltaf/fs);
    while (n < size) {
        if ((n-1) < 0) {
            xn_1 = 0;
            yn_1 = 0;
            xn_2 = 0;
            yn_2 = 0;
        } else if ((n-2) < 0) {
            xn_1 = bufferIn[0];
            yn_1 = bufferOut[0];
            xn_2 = 0;
            yn_2 = 0;
        } else {
            xn_1 = bufferIn[n-1];
            yn_1 = bufferOut[n-1];
            xn_2 = bufferIn[n-2];
            yn_2 = bufferOut[n-2];
        }
        bufferOut[n] = bufferIn[n]-b1*(xn_1-r*yn_1)+(xn_2-r*r*yn_2); 
        n++;
    }
    return 0;
}
//Getters parameters
float karplusInstrument::getSFactor() {
    return(params.SFactor);
}
float karplusInstrument::getBFactor() {
    return(params.BFactor);
}
float karplusInstrument::getRlFactor() {
    return(params.Grl);
}

//Setter parameters
int karplusInstrument::setSFactor(float number) {
    if (number > 1) {
        params.SFactor = number;
        return (0);
    }
    return(-1);
}
int karplusInstrument::setBFactor(float number) {
    if ((number <= 1) && (number >= 0)) {
        params.BFactor = number;
        return (0);
    }
    return(-1);
}
int karplusInstrument::setRlFactor(float number) {
    if ((number <= 1) && (number >= 0)) {
        params.Grl = number;
        return (0);
    }
    return(-1);
}
// Body filter
void karplusInstrument::activeFilter() {
    params.bodyFilter = true;
}
void karplusInstrument::deactiveFilter() {
    params.bodyFilter = false;
}

