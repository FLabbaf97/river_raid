#ifndef CONTRIOLLER_H
#define CONTRIOLLER_H
//#include <QObject>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include "Player.h"
#include <enemy.h>
#include "score.h"
#include <QVector>
#include "fuel.h"
#include <bullet.h>
class controller : public QGraphicsView
{
    Q_OBJECT
public:
    controller();
    void start();
    int gameOver(int score);
    QGraphicsScene* scene;
    Player* player;
    QVector<enemy*> enemies;
    Score* score;
    Fuel* fuel;

public slots:
    void create_enemy();
    void routine();
};

#endif // CONTRIOLLER_H
