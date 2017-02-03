#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
class Bullet : public QObject  , public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet();
//    bool check_collision();
public slots:
    void move();
};

#endif // BULLET_H
