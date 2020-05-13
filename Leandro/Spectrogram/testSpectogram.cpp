#include "Spectrogram.h"
#include "AudioFile.h"

int main(void) {
    AudioFile<double> audioFile;
    audioFile.load("./out.wav");
    int channel = 0;
    int numSamples = audioFile.getNumSamplesPerChannel();
    float* signal = new float[numSamples];


    for (int i = 0; i < numSamples; i++)
    {
        signal[i] = (float)(audioFile.samples[channel][i]);
    }
    unsigned int samplingRate = 44000;
    unsigned int nfft = 1024;
    Spectrogram test(signal, numSamples);
    test.calcSpectrogram(samplingRate, nfft, WINDOW_NONE, true);
    return 0;

}

















/*#include <complex>
#include <iostream>
//#include <valarray>
#include <vector>
#include <fstream>
#include "Spectrogram.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include "AudioFile.h"
//#include "qcustomplot.h"


using namespace std;
//namespace plt = matplotlibcpp;
AudioFile<double> audioFile;


int main()
{
    audioFile.load("./tst.wav");
    int channel = 0;
    int numSamples = audioFile.getNumSamplesPerChannel();
    float* signal = new float[numSamples];


    for (int i = 0; i < numSamples; i++)
    {
        signal[i] = audioFile.samples[channel][i];
    }

    //Spectrogram tst((void*)signal, numSamples,2);
    //std::vector<vector<float>> matrix;
    //matrix = tst.getSpectrogramMatrix();
    ofstream out("data.ian");
    //out << matrix.size() << endl;
    //out << matrix[0].size() << endl;

    for (int i = 0; i < numSamples; i++) {
        out << to_string(signal[i]);
        if (i != numSamples)
            out << ',';
    }
    out << endl;
    //for (int u = 0; u < matrix.size(); u++) {
    //    for (int i = 0; i < matrix[u].size(); i++) {
    //        out << matrix[u][i];
    //        if (i != matrix[u].size() - 1)
    //            out << ',';
    //    }
    //    out << endl;
    //}

    out.close();


    return 0;
}
*/