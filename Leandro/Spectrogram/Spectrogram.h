#pragma once
#include <iostream>
#include <string>
#include <complex>
#include <vector>

typedef enum{WINDOW_NONE, WINDOW_BLACKMAN, WINDOW_HAMMING, WINDOW_BARTLETT}window_t;

using namespace std;


class Spectrogram {
public:
	Spectrogram(float * signal, unsigned int signalSize);
	~Spectrogram();
	void calcSpectrogram(unsigned int samplingRate = 44000, unsigned int nfft = 1024, window_t window = WINDOW_NONE,bool showTime = true , bool save = true, string name = "sepcgram.png");
	//void fft(std::complex<float>* in, std::complex<float>* out, size_t n);
protected:
	//std::vector<complex<double>> Cooley_Tukey(std::vector<complex<double>>& samples);
	float* sig;
	unsigned int sigSize;
	std::string hola;
};


























//#include <vector>
//#include <complex>
//#include <iostream>

//using namespace std;

/*class Spectrogram {
public:
	Spectrogram(void* signal, unsigned int numSamples, unsigned int res);
	~Spectrogram();
	std::vector<vector<float>> getSpectrogramMatrix();
protected:
	std::vector<float> calcFFTMag(std::vector<complex<double>> temp);
	//std::vector<float> getFFTArg();
	void getFFT();
	std::vector<complex<double>> fft(std::vector<complex<double>>& samples);
	std::vector<complex<double>> FFT;
	std::vector<float> mag;
	std::vector<complex<double>> samples;
	unsigned int res;
};*/