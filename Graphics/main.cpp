//#include "mainwindow.h"
#include <QApplication>
#include "controller.h"

controller* control;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    control = new controller;
    control->show();

    return a.exec();
}
