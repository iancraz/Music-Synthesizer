#include "fft.h"
#include <iostream>
#include <complex>
using namespace std;

int main(void) {
	float input[10] = { 1,1,1,1,1,1,1,2 };
	complex<float> samples[8];
	complex<float> out[8];
	for (unsigned int i = 0; i < 8; i++) {
		complex<double> temp(input[i], 0);
		samples[i] = temp;
	}
	fft(samples, out, 8);
	bool hola = true;
	return 0;
}