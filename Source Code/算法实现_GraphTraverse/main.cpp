#include "mainwindow.h"
#include "mgraph.h"
#include <iostream>
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString::fromLocal8Bit("Í¼µÄ±éÀú"));
    w.show();
    return a.exec();
}
