#include "Leandro.h"
#include "Additive.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Leandro program;
	program.show();
	return a.exec();
}
