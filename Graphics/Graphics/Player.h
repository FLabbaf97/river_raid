 #ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Player :public QObject ,  public QGraphicsPixmapItem
{
public:
    Player();
    void keyPressEvent(QKeyEvent* event);
};

#endif // Player_H
