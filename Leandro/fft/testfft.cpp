#include "fft.h"
#include <iostream>
#include <complex>
#include <fstream>
#include <string>
#define NUM_SAMPLES	4096
#define pi  3.14159265359

using namespace std;

int main(void) {
	float input[(unsigned int)NUM_SAMPLES];
	float T = 1.0 / 800.0;
	for (unsigned int i = 0; i < NUM_SAMPLES; i++) {
		input[i] = 10 * sin(100 * 2 * pi * i * T) + 5 * sin(200 * 2 * pi * i * T) + 2.5 * sin(300 * 2 * pi * i * T);
	}
	complex<float> samples[(unsigned int)NUM_SAMPLES];
	complex<float> out[(unsigned int)NUM_SAMPLES];
	for (unsigned int i = 0; i < NUM_SAMPLES; i++) {
		complex<double> temp(input[i], 0);
		samples[i] = temp;
	}
	fft(samples, out, NUM_SAMPLES);


	ofstream o("fft.ian");
	for (unsigned int i = 0; i < NUM_SAMPLES; i++)
		o << to_string(abs(samples[i])) << ',';
	o << endl;
	for (unsigned int i = 0; i < NUM_SAMPLES; i++)
		o << to_string(abs(out[i])) << ',';
	o.close();
	return 0;
}