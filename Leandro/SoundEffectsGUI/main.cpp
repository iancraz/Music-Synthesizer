#include "SoundEffects.h"
#include "Effect.h"
#include "AudioFile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SoundEffects w;
	w.show();
	return a.exec();
}
