#include "contrioller.h"
#include "Player.h"
#include <QDebug>
#include <QTimer>
Contrioller::Contrioller(QWidget* parent)
{
    //creat scene
    scene = new QGraphicsScene;
    setScene(scene);
    //creat player
    player = new Player;
    player->setRect(0 , 0 , 100 , 50);
    //creat score & fuel
    score = new Score;
    fuel = new Fuel;
    fuel -> setPos(fuel->x() , fuel->y() + 25);

    //add items  to scen
    scene->addItem(player);
    scene->addItem(score);
    scene->addItem(fuel);

    // set focus on player
    player->setFlag(QGraphicsRectItem:: ItemIsFocusable);
    player->setFocus();

    // add to view
    QGraphicsView* view = new QGraphicsView(scene);


    // fix the view and set position of player
    view->setFixedSize(1000 , 700);
    scene->setSceneRect(0 , 0 ,1000 , 700);
    player->setPos(view->width()/2 , view->height()  - 100);


   // creat enemy every 2 seconds
    QTimer* timer2 = new QTimer;
    QObject :: connect(timer2 , SIGNAL(timeout()) , player , SLOT(spawn()));
    timer2->start(2000);

    show();
}
