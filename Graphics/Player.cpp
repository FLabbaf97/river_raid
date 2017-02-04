#include "Player.h"
#include<QDebug>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

Player::Player()
{

    this->setPixmap(QPixmap(":/images/fig/airplane.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt:: Key_Left)
    {
        if(x() > 0)
            setPos(x() - 10 , y());
    }
    if(event->key() == Qt :: Key_Right)
    {
        if(x() < 700 )
            setPos(x() + 10 , y());
    }
    else if(event->key() == Qt :: Key_Space)
    {
          Bullet* bullet = new Bullet();
          bullet->setPos(x() , y());
          scene()->addItem(bullet);
    }
}

