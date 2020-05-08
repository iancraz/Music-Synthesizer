#include "Leandro.h"
#include "Additive.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Leandro program;
	

	Channel* channel1 = new Channel(program.currentSample);
	//program.addChannel(channel1);
	program.addMidiFile("", "sm64.mid", true);
	//program.channels.front()->setChannelTrack(program.midiTracks.front());
	//additiveInstrument* piano = new additiveInstrument;
	
	//program.channels.front()->setChannelInstrument(piano);
	Pa_StartStream(program.stream);


	program.show();
	return a.exec();
}
