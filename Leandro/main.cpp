#include "Leandro.h"
#include "Instrument.h"
#include <QtWidgets/QApplication>
#include <stdio.h>
#include <time.h>
#include <QSplashScreen>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	QPixmap pixmap("images/splash.png");
	QSplashScreen splash(pixmap);
	splash.show();
	Leandro program;
	program.loadData();
	program.show();
	splash.finish(&program);
	return a.exec();
}
