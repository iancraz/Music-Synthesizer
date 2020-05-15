#include "Leandro.h"
#include "Instrument.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
#include <time.h>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	Leandro program;
	program.show();
	return a.exec();
}
