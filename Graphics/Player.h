 #ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QObject>

class Player :public QObject ,  public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent* event);
};

#endif // Player_H
