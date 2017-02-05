#include "enemy.h"
#include<QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <stdlib.h>

qreal enemy::rate = 0;
int values[] = {60 , 30 , 60 , 100 , 150};

int enemy::getval()
{
    return val;
}

int enemy::get_type()
{
    return type;
}

enemy::enemy(int t)
{
    type = t;

    val = values[(int)t];
    if(t == 0)
        this->setPixmap(QPixmap(":/images/fig/heli.png"));
    if(t == 1)
        this->setPixmap((QPixmap(":/images/fig/nave.png")));
    else if(t == 2)
        this->setPixmap(QPixmap(":/images/fig/balloon.png"));
    else if(t == 3)
        this->setPixmap(QPixmap(":/images/fig/jet.png"));
    else if(t == 4)
        this->setPixmap(QPixmap(":/images/fig/fuel.png"));

    // draw enemy
    int randomNum = rand() %  500;
    setPos(randomNum , 0);
//    setRect(randomNum , 0 , 100 , 100);
    // we want it that every 50ms bullet move

    QTimer* timer = new QTimer();

    connect (timer , SIGNAL(timeout()) , this , SLOT(move()));
    timer->start(50);
}

void enemy::move()
{
    setPos(x() , y()+ (qreal)5 + rate);
    if(rate < 30)
        rate += 0.001;
}

