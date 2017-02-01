#ifndef ENEMY_H
#define ENEMY_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
class enemy : public QObject ,  public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemy();
public slots:
    void move();
//    ~enemy();
//    void spawn();
};

#endif // ENEMY_H
