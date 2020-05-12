#pragma once
#include <iostream>
#include <vector>
#include <complex>

void fft(std::complex<float>* in, std::complex<float>* out, size_t n);

static std::vector<std::complex<double>> Cooley_Tukey(std::vector<std::complex<double>>& samples);