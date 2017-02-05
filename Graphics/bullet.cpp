#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>


qreal Bullet::rate = 0;
Bullet::Bullet()
{
    // draw bullet

    setRect(50, -15 , 1 , 15);

    // we want it that every 50ms bullet move

    QTimer* timer = new QTimer();

    connect (timer , SIGNAL(timeout()) , this , SLOT(move()));
    timer->start(50); // 50 ms
}


void Bullet::move()
{
        setPos(x() , y()- (qreal)15 - rate);
        if(rate < 35)
            rate += 0.001;
        if(pos().y() < 0){
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted by getting out of scene";
        }

}
