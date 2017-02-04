#ifndef ENEMY_H
#define ENEMY_H

#include <QDebug>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

enum Type{helicopter , Nave , balloon , Jet , Fuel_depot};


class enemy : public QObject ,  public QGraphicsRectItem
{
    Q_OBJECT
    int type;
    int val;
public:
    int getval();
    int get_type();
    enemy(int);
public slots:
    void move();
//    ~enemy();
//    void spawn();
};

#endif // ENEMY_H
