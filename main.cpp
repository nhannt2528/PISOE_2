#include "mainwindow.h"
//#include "DI.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    DI di;
    return a.exec();
}
