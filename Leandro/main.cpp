#include "Leandro.h"
#include "Instrument.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
#include <time.h>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Leandro program;

	PaError err = Pa_StartStream(program.stream);
	if (err != paNoError) throw "Error! PortAudio couldnt start stream";

	program.show();
	return a.exec();
}
