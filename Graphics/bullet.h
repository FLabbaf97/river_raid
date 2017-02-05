#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsRectItem>
#include <QObject>
class Bullet : public QObject  , public QGraphicsRectItem
{
    Q_OBJECT
    static qreal rate ;
public:
    Bullet();
public slots:
    void move();
};



#endif // BULLET_H
