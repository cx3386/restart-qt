#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    int nExitCode;
    do {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        nExitCode = a.exec();
    } while (nExitCode == 773);

    return nExitCode;
}
