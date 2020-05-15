#include "Instrument.h"
#include "json/json.h"

#define MAX_LOOP_TIME (0.370)
#define MIN_LOOP_TIME (0.)


SamplingInstrument::SamplingInstrument(samplingParams_t * params) {
	this->type = synthType::sampling;
	repeat_time_begin = MIN_LOOP_TIME;
	repeat_time_end = MAX_LOOP_TIME;

	lenght_temp_buffer = params->buffLength;
	min_octave = params->minOctave;
	max_octave = params->maxOctave;
	
	samples = new vector<Sample*>(*params->samples);

	Sample* sample = nullptr;
	temp_buffer = new float[lenght_temp_buffer];
	temp_buffer_2 = new float[lenght_temp_buffer];

	//Limpieza buffers
	for (int i = 0; i < lenght_temp_buffer; i++) {
		temp_buffer[i] = 0;
		temp_buffer_2[i] = 0;
	}
	// QUEDARIA HASTA ACA

	//switch (num_instrument) {
	//case 1: //Numero del instrumento
	//	cout << "Piano clasico electronico seleccionado" << endl;
	//	min_octave = 2;
	//	max_octave = 6;
	//	for (int i = min_octave; i <= max_octave; i++) {
	//		cout << "Cargando C" + to_string(i) << endl;
	//		sample = new Sample("./Samples/Piano Electronico Clasico/C" + to_string(i), i);
	//		samples->push_back(sample);
	//	}
	//	selected_sample->note_pressed_time = 0.375;
	//	break;
	//case 2:
	//	cout << "Grand Piano seleccionado" << endl;
	//	min_octave = 2;
	//	max_octave = 6;
	//	for (int i = min_octave; i <= max_octave; i++) {
	//		cout << "Cargando C" + to_string(i) << endl;
	//		sample = new Sample("./Samples/Grand Piano/C" + to_string(i), i);
	//		samples->push_back(sample);

	//	}
	//	selected_sample->note_pressed_time = 1;
	//	break;

	//default:

	//	break;
	//}
}

SamplingInstrument::~SamplingInstrument() {
	delete temp_buffer;
	delete temp_buffer_2;
	delete samples;
}

void SamplingInstrument::key_modification(int num_octave, float B, float new_note_pressed_time) {

	//LIMPIEZA DEL BUFFER
	for (int i = 0; i < lenght_temp_buffer; i++)
		temp_buffer[i] = 0;

	//SELECCION DE SAMPLE
	//Segun el num_octave, se selecciona el sample sobre el cual se va a trabajar (C1, C2, C3, C4 ...)

	Sample* selected_sample = nullptr;
	for (int i = 0; i < samples->size(); i++)
	{
		if (samples->at(i)->num_octave == num_octave) {
			selected_sample = samples->at(i);
			break;
		}
	}

	//DEFINICION DE CONSTANTES

	//Constantes del Sample

	int fs = selected_sample->fs; //Se guarda la frecuencia de muestreo en que se tiene guardado al sample
	int P_0 = (int)(fs / selected_sample->pitch_frecuency); //Se guarda el pitch period de la muestra, segun su pitch frecuency
	int N_0 = selected_sample->lenght_sample; //Se guarda el largo del sample
	int lenght_peaks = selected_sample->lenght_peaks; //se guarda el largo del arreglo de peaks
	int T = selected_sample->T; //Se guarda el ancho de la ventana que se usa para descomponer al Sample



	//Constantes de la nueva nota sintetizada
	int P_1 = (int)((1 / B) * P_0); //Nuevo Pitch period
	int N_1 = N_0;
	int extra_N = 0;


	//Constantes que se requieren para la operacion de modficacion temporal de la nota
	int peaks_idx_end_pressed = 0; //Indice de peak donde termina note pressed
	int peaks_idx_begin_repeat = 0;  // Indice de peak donde empiza la region de repeticion
	int peaks_idx_end_repeat = 0;  //Indice de peak donde termina la region de repeticion


	for (int i = 0; i < lenght_peaks; i++)
	{
		if (selected_sample->peaks[i] > (int)(selected_sample->note_pressed_time * fs)) {
			peaks_idx_end_pressed = i - 1;
			break;
		}
	}

	for (int i = 0; i < lenght_peaks; i++)
	{
		if (selected_sample->peaks[i] > (int)(repeat_time_begin * fs)) {
			peaks_idx_begin_repeat = i - 1;
			break;
		}
	}

	for (int i = 0; i < lenght_peaks; i++)
	{
		if (selected_sample->peaks[i] > (int)(repeat_time_end * fs)) {
			peaks_idx_end_repeat = i - 1;
			break;
		}
	}



	int idx = 0;
	int new_peaks_begin = 0;
	int new_peaks_end = 0;
	int correction = 0;

	//CASO 1 - SE DESEA OBTENER UNA NOTA CON MENOR TIEMPO DE PRESIONADO QUE EL SAMPLE
	//El tiempo de presionado del sample es mas largo de lo que se quiere. Se trunca el sample hasta el valor de nota presionada que se desee y luego que agrega el decay del sample
	if (new_note_pressed_time <= selected_sample->note_pressed_time) {

		/*
		extra_N = (new_note_pressed_time - selected_sample->note_pressed_time) * fs; //Largo extra que
		N_1 = int(N_0 + extra_N); // Largo de la nueva señal
		idx = 0;
		new_peaks_begin = cpeaks[0];
		new_peaks_end = N_1 - (int)(0.10 * N_1);
		correction = ((selected_sample->note_pressed_time - new_note_pressed_time) * fs);
		for (int new_peaks = new_peaks_begin; new_peaks < new_peaks_end; new_peaks = new_peaks + int(P_1)) {
			idx = get_nearest_peak(selected_sample, new_peaks + correction);
			for (int right_i = 0; right_i < (int)(T / 2); right_i++) {
				if ((new_peaks + right_i > lenght_temp_buffer) || idx > lenght_peaks || idx < 0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] + right_i) < 0) || (((int)selected_sample->peaks[idx] + right_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks + right_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] + right_i];
			}
			for (int left_i = 0; left_i < (int)(T / 2); left_i++) {
				if (((new_peaks - (int)(T / 2) + left_i) > lenght_temp_buffer) || ((new_peaks - (int)(T / 2) + left_i) < 0) || idx <0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) < 0) || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks - (int)(T / 2) + left_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] - (int)(T / 2) + left_i];
			}
		}
		*/

		//ALTERNATIVA

		extra_N = (new_note_pressed_time - selected_sample->note_pressed_time) * fs; //Largo extra que 	
		N_1 = int(N_0 + extra_N); // Largo de la nueva señal

		idx = 0;
		new_peaks_begin = selected_sample->peaks[1];
		new_peaks_end = N_0 - (int)(0.2 * N_0);
		correction = 0;


		for (int new_peaks = new_peaks_begin; new_peaks < new_peaks_end; new_peaks = new_peaks + int(P_1)) {

			idx = get_nearest_peak(selected_sample, new_peaks + correction);

			for (int right_i = 0; right_i < (int)(T / 2); right_i++) {
				if ((new_peaks + right_i > lenght_temp_buffer) || idx > lenght_peaks || idx < 0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] + right_i) < 0) || (((int)selected_sample->peaks[idx] + right_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks + right_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] + right_i];
			}

			for (int left_i = 0; left_i < (int)(T / 2); left_i++) {
				if (((new_peaks - (int)(T / 2) + left_i) > lenght_temp_buffer) || ((new_peaks - (int)(T / 2) + left_i) < 0) || idx <0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) < 0) || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks - (int)(T / 2) + left_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] - (int)(T / 2) + left_i];
			}
		}

		/*
		float delta = -1. / (2 * N_0);
		for ( int i = 0 ; i < lenght_temp_buffer; i++)
		{
			temp_buffer_2[i] = temp_buffer[(int)((new_note_pressed_time * (float)fs))] * exp(float(i * delta));
		}
		int count_2 = 0;
	*/

		for (int i = 0; i < lenght_temp_buffer; i++)
			temp_buffer_2[i] = 0;


		int T_2 = (int)(N_1 / 8);
		//int T_2 = ((int)((new_note_pressed_time * (float)fs))) * 2;
		selected_sample->hanning(temp_buffer_2, T_2, 0);
		int count_2 = (int)(T_2 / 2);


		for (int new_peaks = (int)((new_note_pressed_time * (float)fs)); new_peaks < N_0; new_peaks++)
		{
			temp_buffer[new_peaks] = temp_buffer[new_peaks] * temp_buffer_2[count_2];
			count_2++;

		}

		for (int i = 0; i < lenght_temp_buffer; i++)
			temp_buffer_2[i] = 0;

		temp_buffer[N_1] = INFINITY;
	}

	//CASO 2 - SE DESEA OBTENER UNA NOTA CON MAYOR TIEMPO DE PRESIONADO QUE EL SAMPLE
	if (new_note_pressed_time > selected_sample->note_pressed_time) {  //Para el caso en que se desee obtener una nota con mayor tiempo de presionado que el sample

		//ALTERNATIVA I

		extra_N = (new_note_pressed_time - selected_sample->note_pressed_time) * fs; //Largo extra que 	
		N_1 = int(N_0 + extra_N); // Largo de la nueva señal

		//PARTE 1 -> DESDE 0 HASTA QUE SE SUELTA LA NOTA
		idx = 0;
		new_peaks_begin = selected_sample->peaks[1];
		new_peaks_end = selected_sample->peaks[peaks_idx_begin_repeat];
		correction = 0;

		for (int new_peaks = new_peaks_begin; new_peaks < new_peaks_end; new_peaks = new_peaks + int(P_1)) {

			idx = get_nearest_peak(selected_sample, new_peaks);

			for (int right_i = 0; right_i < (int)(T / 2); right_i++) {
				if ((new_peaks + right_i > lenght_temp_buffer) || idx > lenght_peaks || idx < 0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] + right_i) < 0) || (((int)selected_sample->peaks[idx] + right_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks + right_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] + right_i];
			}

			for (int left_i = 0; left_i < (int)(T / 2); left_i++) {
				if (((new_peaks - (int)(T / 2) + left_i) > lenght_temp_buffer) || ((new_peaks - (int)(T / 2) + left_i) < 0) || idx <0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) < 0) || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks - (int)(T / 2) + left_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] - (int)(T / 2) + left_i];
			}
		}

		int count = 0;
		idx = 0;
		new_peaks_begin = (int)((repeat_time_begin * (float)fs));
		new_peaks_end = (int)(((new_note_pressed_time - abs(selected_sample->note_pressed_time - repeat_time_end)) * (float)fs));
		correction = 0;

		for (int value = (int)((repeat_time_begin * (float)fs)); value < (int)((repeat_time_end * (float)fs)); value = value + (int)P_1)
		{
			temp_buffer_2[count] = value;
			count++;
		}

		count = 0;
		for (int new_peaks = new_peaks_begin; new_peaks < new_peaks_end; new_peaks = new_peaks + int(P_1)) {

			idx = get_nearest_peak(selected_sample, temp_buffer_2[count]);

			for (int right_i = 0; right_i < (int)(T / 2); right_i++) {
				if (idx > lenght_peaks || idx < 0 || (new_peaks + right_i) > lenght_temp_buffer || (new_peaks + right_i) < 0 || ((int)selected_sample->peaks[idx] + right_i) > selected_sample->lenght_sample || ((int)selected_sample->peaks[idx] + right_i) < 0)
					continue;
				else
					temp_buffer[new_peaks + right_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] + right_i];
			}

			for (int left_i = 0; left_i < (int)(T / 2); left_i++) {

				if (idx > lenght_peaks || idx < 0 || (new_peaks - (int)(T / 2) + left_i) > lenght_temp_buffer || (new_peaks - (int)(T / 2) + left_i) < 0 || ((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) > selected_sample->lenght_sample || ((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) < 0)
					continue;
				else
					temp_buffer[new_peaks - (int)(T / 2) + left_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] - (int)(T / 2) + left_i];
			}

			if (idx > peaks_idx_end_repeat - 1) {
				count = 0;
			}
			else
				count++;
		}

		//PARTE 3 -> DESDE NUEVA NOTA PRESIONADA HASTA FINAL
		idx = 0;
		new_peaks_begin = (int)(((new_note_pressed_time - abs(selected_sample->note_pressed_time - repeat_time_end)) * (float)fs));
		new_peaks_end = N_1 - (int)(0.01 * N_1);

		//new_peaks_end = N_1;
		correction = -(abs((new_note_pressed_time - abs(selected_sample->note_pressed_time - repeat_time_end)) - repeat_time_end) * fs);

		for (int new_peaks = new_peaks_begin; new_peaks < new_peaks_end; new_peaks = new_peaks + int(P_1)) {

			idx = get_nearest_peak(selected_sample, new_peaks + correction);

			for (int right_i = 0; right_i < (int)(T / 2); right_i++) {
				if ((new_peaks + right_i > lenght_temp_buffer) || idx > lenght_peaks || idx < 0 || (((int)selected_sample->peaks[idx] + right_i) < 0) || (((int)selected_sample->peaks[idx] + right_i) > N_0) || (new_peaks + right_i) < 0)
					continue;
				else
					temp_buffer[new_peaks + right_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] + right_i];
			}

			for (int left_i = 0; left_i < (int)(T / 2); left_i++) {
				if (((new_peaks - (int)(T / 2) + left_i) > lenght_temp_buffer) || ((new_peaks - (int)(T / 2) + left_i) < 0) || idx <0 || idx > lenght_peaks || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) < 0) || (((int)selected_sample->peaks[idx] - (int)(T / 2) + left_i) > N_0))
					continue;
				else
					temp_buffer[new_peaks - (int)(T / 2) + left_i] += selected_sample->sample_s[idx][(int)selected_sample->peaks[idx] - (int)(T / 2) + left_i];
			}
		}

		temp_buffer[N_1] = INFINITY;
	}
}
int SamplingInstrument::get_nearest_peak(Sample* selected_sample, int number) {
	int peaks_lenght = selected_sample->lenght_peaks;
	int temp = selected_sample->peaks[peaks_lenght - 1] - selected_sample->peaks[0];
	int i = 0;
	for (i = 0; i < peaks_lenght; i++) {
		if (abs(selected_sample->peaks[i] - number) < temp) {
			temp = abs(selected_sample->peaks[i] - number);
		}
		else {
			break;
		}
	}

	if ((i - 1) < 0)
		return 0;
	else
		return(i - 1);
}

int SamplingInstrument::synthFunction(float* outputBuffer, const unsigned int outputBufferSize, const int keyNumber, const float lengthInMilliseconds, const int velocity, const int sampleRate)
{
	float velocitymulti = (float)velocity / 127.0;
	int first_keyNumber = 24;
	int keys_per_octave = 12;
	int num_octave = 0;
	int key_dif;
	int key_num_octave;

	int keyNumber2 = keyNumber;


	for (int i = min_octave; i <= max_octave; i++)
	{

		if ((keyNumber2 >= first_keyNumber + (i * keys_per_octave) && keyNumber2 < (first_keyNumber + keys_per_octave) + (i * keys_per_octave))) {
			num_octave = i + 1;
			break;
		}
	}

	if (num_octave > max_octave || num_octave < min_octave) {
		cout << "Nota pedida se sale del rango" << endl;

		if (keyNumber2 > (keyNumber2 + (12 * (max_octave - 1))))
			num_octave = max_octave;

		if (keyNumber2 < (keyNumber2 + (12 * (min_octave - 1))))
			num_octave = min_octave;
	}

	key_num_octave = first_keyNumber + (12 * (num_octave - 1)); //Numero de nota de la mustra a utilizar
	key_dif = keyNumber2 - key_num_octave;
	float B = pow(2, (key_dif / 12.));




	key_modification(num_octave, B, lengthInMilliseconds);

	int i = 0;
	while (temp_buffer[i] != INFINITY) {

		outputBuffer[i] = temp_buffer[i] * velocitymulti;
		i++;
	}

	outputBuffer[i] = INFINITY;
	return 0;

}

samplingParams_t * SamplingInstrument::parseSamplingJson(Json::Value data) {
	samplingParams_t temp;
	temp.minOctave = data["min-octave"].asInt();
	temp.maxOctave = data["max-octave"].asInt();
	temp.notePressedTime = data["note-pressed-time"].asFloat();

	temp.samples = new vector<Sample*>;
	// parsear los archivos y generar un Sample * por cada uno de ellos
	for (int i = 0; i < data["files"].size(); i++) {
		Sample* tempSample = new Sample(data["files"][i].asCString(), data["min-octave"].asInt() + i);
		temp.samples->push_back(tempSample);
	}
	return new samplingParams_t(temp);
}