 #ifndef PLAYER_H
#define PLAYER_H
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QObject>

class Player :public QObject ,  public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
};

#endif // Player_H
