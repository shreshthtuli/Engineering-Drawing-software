#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //Initializing Qt application
    MainWindow w; //Show main window
    w.show();
    // just using this for testing purposes
    return a.exec();
}
