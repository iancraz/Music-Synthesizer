#include "Leandro.h"
#include "Additive.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
#include <time.h>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Leandro program;

	adsrParams_t params1;
	params1.tAttack = 0.5;
	params1.tDecay = 2;
	params1.sustainRate = 0.005;
	params1.k = 1.5;
	params1.tRelease = 1;
	params1.sustainLevel = 0.7;

	adsrParams_t params2;
	params2.tAttack = 0.05;
	params2.tDecay = 0.2;
	params2.sustainRate = 0.1;
	params2.k = 1.5;
	params2.tRelease = 0.5;
	params2.sustainLevel = 0.3;

	//program.addChannel(channel1);
	program.addMidiFile("", "pirates.mid", true);
	program.loadData();


	instrumentModel* pianoModel = program.instrumentModels.at(1);
	instrumentModel* clarinetModel = program.instrumentModels.at(0);

	additiveParams_t* pianoParams = (additiveParams_t*)pianoModel->params;
	additiveParams_t* clarinetParams = (additiveParams_t*)clarinetModel->params;

	Instrument* clarinet = new AdditiveInstrument(*clarinetParams, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE);
	Instrument* piano = new AdditiveInstrument(*pianoParams, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE);

	Instrument* instrumentList[] = { clarinet, piano };

	//Instrument* instrument = new AdditiveInstrument("piano_envelope.txt", "Additive Piano");
	for (int i = 0; i < program.channels.size(); i++) {
		//Instrument* instrument = new ADSRInstrument(&params1, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
		Instrument* instrument = new SamplingInstrument(2, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE);
		

		//Instrument* instrument = randInst();
		//Effect* effect = new VibratoEffect();
		program.channels[i]->setChannelInstrument(clarinet);
		//program.channels[i]->addEffectToChannel(effect);
	}
	//Instrument* instrument = new ADSRInstrument(&params1, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
	//Instrument* instrument = new ADSRInstrument(&params1, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);aaaaaaasaaaa
	//program.channels.front()->setChannelTrack(program.midiTracks.front());
	//ADSRInstrument* piano = new ADSRInstrument;

	//program.channels.front()->setChannelInstrument(piano);
	PaError err = Pa_StartStream(program.stream);
	if (err != paNoError) throw "Error! PortAudio couldnt start stream";

	program.show();
	return a.exec();
}