//#include "mainwindow.h"
#include <QApplication>
#include "contrioller.h"

Contrioller* control;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    control = new Contrioller;
    control->show();

//    //creat scene
//    QGraphicsScene* scene = new QGraphicsScene;
//    rect* player = new rect;
//    player->setRect(0 , 0 , 100 , 50);

//    //add item to scen
//    scene->addItem(player);

//    // set focus on player
//    player->setFlag(QGraphicsRectItem:: ItemIsFocusable);
//    player->setFocus();

//    // add to view
//    QGraphicsView* view = new QGraphicsView(scene);

//    //show the view
//    view->show();

    // fix the view and set position of player
//    view->setFixedSize(1000 , 700);
//    scene->setSceneRect(0 , 0 ,1000 , 700);
//    player->setPos(view->width()/2 , view->height()  - 100);
//    // creat enemy every 2 seconds
//    QTimer* timer = new QTimer;
//    QObject :: connect(timer , SIGNAL(timeout()) , player , SLOT(spawn()));
//    timer->start(2000);

    return a.exec();
}
