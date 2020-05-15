#include "Spectrogram.h"
#include <fstream>

#define DEBUG

Spectrogram::Spectrogram(float* signal, unsigned int signalSize) {
    this->sig = new float[signalSize];
    for (unsigned int i = 0; i < signalSize; i++)
        sig[i] = signal[i];
    this->sigSize = signalSize;
    return;
}

Spectrogram::~Spectrogram() {
    delete[] this->sig;
    return;
}

void Spectrogram::calcSpectrogram(unsigned int samplingRate, unsigned int nfft, window_t window, unsigned int overlap, bool showTime , bool save, string name) {
    ofstream out("./Spectrogram/data.ian");
    out << name << endl;
    out << to_string(samplingRate) << ',' << to_string(nfft) << ',' << to_string(window) << ',' << to_string(overlap) << ',';
    if (save)
        out << to_string(1) << ',';
    else
        out << to_string(0) << ',';
    if (showTime)
        out << to_string(1);
    else
        out << to_string(0);
    out << endl;
    // Samplingrate, nfft,window,save
#ifdef DEBUG
    cout << "Calculando el Espectrograma.." << endl;
#endif
    for (unsigned int i = 0; i < this->sigSize; i++) {
        out << to_string(sig[i]);
        if (i != this->sigSize)
            out << ',';
    }
    out << endl;
    out.close();
    system("py Spectrogram\\plot.py");
#ifdef DEBUG
    cout << "Finalizado el calculo." << endl;
#endif
}

/*
void Spectrogram::fft(std::complex<float>* in, std::complex<float>* out, size_t n) {
    vector<complex<double>> temp;

    for (size_t i = 0; i < n; i++)
        temp.push_back(in[i]);
    temp = Cooley_Tukey(temp);
    for (size_t i = 0; i < temp.size(); i++)
        out[i] = temp[i];
    return;
}

std::vector<complex<double>> Spectrogram::Cooley_Tukey(std::vector<complex<double>>& samples) {
    unsigned int numSamples = samples.size();

    if (numSamples <= 1)
        return samples;
    unsigned int newSampleSize = numSamples / 2;
    std::vector<complex<double>> Xeven(newSampleSize, 0);
    std::vector<complex<double>> Xodd(newSampleSize, 0);

    for (unsigned int i = 0; i < newSampleSize; i++) {
        Xeven[i] = samples[2 * i];
        Xodd[i] = samples[2 * i + 1];
    }
    std::vector<complex<double>> Feven(newSampleSize, 0);
    std::vector<complex<double>> Fodd(newSampleSize, 0);

    Feven = fft(Xeven);
    Fodd = fft(Xodd);

    std::vector<complex<double>> freqBins(numSamples, 0);

    for (int i = 0; i < (numSamples / 2); i++) {
        complex<double> cmplxExponential = polar(1.0, (-2 * 3.14159 * i / numSamples)) * Fodd[i];
        freqBins[i] = Feven[i] + cmplxExponential;
        freqBins[i + numSamples / 2] = Feven[i] - cmplxExponential;
    }

    return freqBins;
}
*/




/*
Spectrogram::Spectrogram(void* signal, unsigned int numSamples, unsigned int res) {
	float *sig = (float *)signal;
	for (unsigned int i = 0; i < numSamples; i++) {
        complex<double> temp(sig[i], 0);
		samples.push_back(temp);
	}
    this->res = res;
	return;
}

Spectrogram::~Spectrogram() {
	samples.clear();
	return;
}

void Spectrogram::getFFT() {
    FFT = fft(samples);
    return;
}

std::vector<complex<double>> Spectrogram::fft(std::vector<complex<double>>& samples) {
    unsigned int numSamples = samples.size();

    if (numSamples <= 1)
        return samples;
    unsigned int newSampleSize = numSamples / 2;
    std::vector<complex<double>> Xeven(newSampleSize, 0);
    std::vector<complex<double>> Xodd(newSampleSize, 0);

    for (unsigned int i = 0; i < newSampleSize; i++) {
        Xeven[i] = samples[2 * i];
        Xodd[i] = samples[2 * i + 1];
    }
    std::vector<complex<double>> Feven(newSampleSize, 0);
    std::vector<complex<double>> Fodd(newSampleSize, 0);

    Feven = fft(Xeven);
    Fodd = fft(Xodd);

    std::vector<complex<double>> freqBins(numSamples, 0);

    for (int i = 0; i < (numSamples / 2); i++) {
        complex<double> cmplxExponential = polar(1.0, (-2 * 3.14159 * i / numSamples)) * Fodd[i];
        freqBins[i] = Feven[i] + cmplxExponential;
        freqBins[i + numSamples / 2] = Feven[i] - cmplxExponential;
    }

    return freqBins;
}

std::vector<float> Spectrogram::calcFFTMag(std::vector<complex<double>> temp) {
    std::vector<float> mag;
    if (temp.size() > 0) {
        for (int i = 0; i < temp.size(); i++) {
            mag.push_back(abs(temp[i]));
        }
    }
    return mag;
}

std::vector<vector<float>> Spectrogram::getSpectrogramMatrix() {
    //getFFT();
    int numSpaces = samples.size() / res;
    std::vector<vector<float>> mat;
    for (int u = 0; u < numSpaces; u++) {
        std::vector<complex<double>> temp;
        temp.clear();
        for (unsigned int i = 0; i < res; i++) {
            temp.push_back(samples[i + u]);
        }
        temp = fft(temp);
        std::vector<float> temp2;
        temp2 = calcFFTMag(temp);
        mat.push_back(temp2);
    }
    //for (int u = 0; u < mat.size(); u++) {
    //    for (int i = 0; i < mat[u].size(); i++) {
    //        matrix[u][i] = mat[u][i];
    //    }
    }
    return mat;
}
*/