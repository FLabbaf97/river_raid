#include "enemy.h"
#include<QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

enemy::enemy()
{
    // draw enemy
    int randomNum = rand() %  500;
    setRect(randomNum , 0 , 100 , 100);
    // we want it that every 50ms bullet move

    QTimer* timer = new QTimer();

    connect (timer , SIGNAL(timeout()) , this , SLOT(move()));
    timer->start(50);
}

void enemy::move()
{
    setPos(x() , y()+5);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "deleted";
    }


}

