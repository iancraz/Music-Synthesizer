#include "Leandro.h"
#include "Additive.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
#include <time.h>

Instrument* randInst();

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
	program.addMidiFile("", "sm64.mid", true);
	//Instrument* instrument = new AdditiveInstrument("piano_envelope.txt", "Additive Piano");
	for (int i = 0; i < program.channels.size(); i++) {
		Instrument* instrument = new additiveInstrument(&params1, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
		//Instrument* instrument = randInst();
		Effect* effect = new vibratoEffect();
		program.channels[i]->setChannelInstrument(instrument);
		//program.channels[i]->addEffectToChannel(effect);
	}
	//Instrument* instrument = new additiveInstrument(&params1, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
	//Instrument* instrument = new additiveInstrument(&params1, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
	//program.channels.front()->setChannelTrack(program.midiTracks.front());
	//additiveInstrument* piano = new additiveInstrument;

	//program.channels.front()->setChannelInstrument(piano);
	PaError err = Pa_StartStream(program.stream);
	if (err != paNoError) throw "Error! PortAudio couldnt start stream";

	program.show();
	return a.exec();
}

Instrument* randInst() {
	srand(time(NULL));
	int randInt = rand() % 3 + 1;
	Instrument* ret;
	std::string str;
	std::string name;
	switch (randInt) {
	case 1:
		str = "guitar_envelope.txt";
		name = "Additive Guitar";
		break;
	case 2:
		str = "piano_envelope.txt";
		name = "Additive Piano";
		break;
	case 3:
		str = "trumpet_envelope.txt";
		name = "Additive Trumpet";
		break;
	default:
		break;
	}
	ret = new AdditiveInstrument(str, name);
	return ret;
}