#include <QApplication>
#include "controller.h"
#include "menu.h"

controller* control;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    menu* mainMenu = new menu();
//    mainMenu->show();

    control = new controller();
    control->show();

    return a.exec();
}
