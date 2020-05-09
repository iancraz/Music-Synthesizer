#include "Leandro.h"
#include "Additive.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Leandro program;

	adsrParams_t params;
	params.tAttack = 0.001;
	params.tDecay = 0.002;
	params.sustainRate = 0.5;
	params.k = 1.5;
	params.tRelease = 0.003;

	
	//program.addChannel(channel1);
	program.addMidiFile("", "sm64.mid", true);
	for (int i = 0; i < program.channels.size(); i++) {
		Instrument* instrument = new additiveInstrument(params, SAMPLE_RATE * MAX_NOTE_LENGTH_SECONDS);
		program.channels[i]->setChannelInstrument(instrument);
	}
	//program.channels.front()->setChannelTrack(program.midiTracks.front());
	//additiveInstrument* piano = new additiveInstrument;

	//program.channels.front()->setChannelInstrument(piano);
	PaError err =	Pa_StartStream(program.stream);
	if (err != paNoError) throw "Error! PortAudio couldnt start stream";
	
	

	program.show();
	return a.exec();
}
