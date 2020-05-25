#pragma once

#include <cstring>
#include "AudioFile.h" 
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class Sample {
public:
	Sample(string file_path, int octave);
	~Sample();

	AudioFile<double> audioFile;
	float* sample;
	int* peaks;
	int T;
	float* h_s;

	vector <float*> sample_s;
	float pitch_frecuency;
	int fs;
	int lenght_peaks;
	int lenght_sample;
	string file_path;
	int num_octave;

	float note_pressed_time;


	int lenght_sample_s;
	void hanning(float* w, int N, short itype);


};

