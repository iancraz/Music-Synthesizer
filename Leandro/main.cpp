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

	adsrParams_t params;
	params.tAttack = 0.2;
	params.tDecay = 0.3;
	params.sustainRate = 0.3;
	params.k = 1.5;
	params.tRelease = 0.5;
	params.sustainLevel = 0.5;

	Instrument* instrument = new AdditiveInstrument("piano_envelope.txt", "Additive Piano");


	//program.addChannel(channel1);
	program.addMidiFile("", "mario_midi.mid", true);
	for (int i = 0; i < program.channels.size(); i++) {
		//Instrument* instrument = randInst();
		Effect* effect = new vibratoEffect();
		program.channels[i]->setChannelInstrument(instrument);
		//	program.channels[i]->addEffectToChannel(effect);
	}
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