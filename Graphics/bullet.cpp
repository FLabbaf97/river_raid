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

//bool Bullet::check_collision()
//{
////    QList <QGraphicsItem* > colliding_items = collidingItems();
////    for(int i = 0; i < colliding_items.size(); i++){
////        if(typeid(*(colliding_items[i])) == typeid(enemy)){
////            //delete them
////            scene()->removeItem(colliding_items[i]);
////            scene()->removeItem(this);
//////            delete colliding_items[i];
////            colliding_items[i] = 0;
////            colliding_items.erase(colliding_items.begin()+i);
////            delete this;

////            qDebug() << "enemy deleted by colliding with bullet";
////            qDebug () << "bullet deleted by colliding with enemy";
////            return true;
////        }
////    }
////    return false;
//}

void Bullet::move()
{
        setPos(x() , y()-20);
        if(pos().y() < 0){
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted by getting out of scene";
        }

}
