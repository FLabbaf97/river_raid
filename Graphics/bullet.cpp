#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>

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
        setPos(x() , y()-20);
        if(pos().y() < 0){
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted by getting out of scene";
        }

}
