 #ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include<QImage>
class Player :public QObject ,  public QGraphicsPixmapItem
{

public:
   Player();
    void keyPressEvent(QKeyEvent* event);
};

#endif // Player_H
