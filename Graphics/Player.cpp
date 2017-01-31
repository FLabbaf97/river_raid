#include "Player.h"
#include<QDebug>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt:: Key_Left)
    {
        if(x() > 0)
            setPos(x() - 10 , y());
    }
    if(event->key() == Qt :: Key_Right)
    {
        setPos(x() + 10 , y());
    }
    else if(event->key() == Qt :: Key_Space)
    {
          Bullet* bullet = new Bullet();
          bullet->setPos(x() , y());
          scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    enemy* enemy1 = new enemy();
    scene()->addItem(enemy1);
}

