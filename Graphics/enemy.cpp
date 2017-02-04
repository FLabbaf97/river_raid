#include "enemy.h"
#include<QDebug>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

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
        setBrush(*new QBrush(Qt::black));
    else if(t == 1)
        setBrush(*new QBrush(Qt::red));
    else if(t == 2)
        setBrush(*new QBrush(Qt::blue));
    else if(t == 3)
        setBrush(*new QBrush(Qt::white));
    else
        setBrush(*new QBrush(Qt::green));
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



}

