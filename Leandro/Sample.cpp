#define _USE_MATH_DEFINES

#include "Sample.h"
#include <conio.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

Sample::Sample(string file_path, int octave_) {

	//CARGA DEL ARCHIVO
	audioFile.load(file_path + ".wav");

	//CONSTANTES
	lenght_sample = audioFile.getNumSamplesPerChannel();
	fs = audioFile.getSampleRate();
	num_octave = octave_;


	float C1 = 32.70320; //Pitch frecuency de C1
	pitch_frecuency = C1 * pow(2, num_octave - 1); //Calculo el pitch dependiendo la muestra C2,C3,C4 ...

	//SAMPLE
	sample = new float[lenght_sample];

	for (int i = 0; i < lenght_sample; i++)
	{
		sample[i] = audioFile.samples[0][i];
	}


	//VENTANA
	int P_0 = (int)(fs / pitch_frecuency);
	T = int(2 * P_0); //Largo de la ventana
	h_s = new float[T]; //Ventana 

	/*
	for (int i = 0; i < T; i++) {
		float value = ((T-1)/2) - abs(i - ((T-1)/2)) ;
		h_s[i] = value; //Armo ventana de hanning
	}
	*/

	hanning(h_s, T, 0);
	/*
	for (int i = 0; i < T; i++) {
		double multiplier = 0.5 * (1 - cos(2 * M_PI * i / T));
		h_s[i] = multiplier; //Armo ventana de hanning
	}
	*/


	//PEAKS 
	fstream file(file_path + ".txt", ios_base::in);
	if (file.is_open())
	{
		cout << ".txt opened" << endl;
		int cnt = 0;
		int peak;

		file >> lenght_peaks;
		peaks = new int[lenght_peaks];

		while (file >> peak)
			peaks[cnt++] = peak;

		file.close();
		/*
		//Claculo tiempo de nota presionada
		float max_value;
		float percentage = 0.3; //porcentaje que se define para obtener el tiempo de presionado de la nota 
		max_value = *std::max_element(sample, sample + lenght_sample);
		int count = 0;

		for (count = 5; count < lenght_peaks; count++) { //el 5 no es magic, es porque la señal empieza muy baja y se deben descartar los primeros picos
			if (sample[peaks[count]] < max_value * percentage)
				break;
		}

		note_pressed_time = ((float)peaks[count] / (float)fs);
		//note_pressed_time = 0.348;

		*/
		//DESCOMPOSICION DEL SAMPLE
		float* sample_x = nullptr;

		for (int i = 0; i < lenght_peaks; i++) {
			sample_x = new float[lenght_sample];
			sample_s.push_back(sample_x);
		}

		for (int i = 0; i < lenght_peaks; i++) {
			for (int j = 0; j < lenght_sample; j++) {
				sample_s[i][j] = 0;
			}
		}

		int idx_peaks = 0;


		for (int idx_peaks = 0; idx_peaks < lenght_peaks; idx_peaks++) {

			for (int right_i = 0; right_i < (int)(T / 2); right_i++) {

				if ((((int)peaks[idx_peaks] + right_i) > lenght_sample) || ((((int)peaks[idx_peaks] + right_i)) > lenght_sample)) {

					break;
				}
				else {
					sample_s[idx_peaks][(int)peaks[idx_peaks] + right_i] = sample[(int)peaks[idx_peaks] + right_i] * h_s[(int)(T / 2) + right_i];
				}
			}

			for (int left_i = 0; left_i < (int)(T / 2); left_i++) {

				if (((peaks[idx_peaks] - (int)(T / 2) + left_i) < 0) || ((((int)peaks[idx_peaks] - (int)(T / 2) + left_i)) > lenght_sample)) {
					break;
				}
				else {
					sample_s[idx_peaks][peaks[idx_peaks] - (int)(T / 2) + left_i] = sample[(int)peaks[idx_peaks] - (int)(T / 2) + left_i] * h_s[left_i];
				}
			}
		}

		delete h_s;


		/*
		cout << "Tamaño de sample = " << lenght_sample << endl;
		cout << "Tamaño de peaks = " << lenght_peaks << endl;
		cout << "Octave = " << num_octave << endl;
		cout << "Pitch frec = " << pitch_frecuency << endl;
		*/

	}

	else cout << "Unable to open file" << endl;

}

Sample::~Sample() {

	delete sample;
	delete peaks;


}


void Sample::hanning(float* w, int N, short itype)
{
	int half, i, idx, n;

	if (itype == 1)	//periodic function
		n = N - 1;
	else
		n = N;

	if (n % 2 == 0)
	{
		half = n / 2;
		for (i = 0; i < half; i++) //CALC_HANNING   Calculates Hanning window samples.
			w[i] = 0.5 * (1 - cos(2 * M_PI * (i + 1) / (n + 1)));

		idx = half - 1;
		for (i = half; i < n; i++) {
			w[i] = w[idx];
			idx--;
		}
	}
	else
	{
		half = (n + 1) / 2;
		for (i = 0; i < half; i++) //CALC_HANNING   Calculates Hanning window samples.
			w[i] = 0.5 * (1 - cos(2 * M_PI * (i + 1) / (n + 1)));

		idx = half - 2;
		for (i = half; i < n; i++) {
			w[i] = w[idx];
			idx--;
		}
	}

	if (itype == 1)	//periodic function
	{
		for (i = N - 1; i >= 1; i--)
			w[i] = w[i - 1];
		w[0] = 0.0;
	}

}
