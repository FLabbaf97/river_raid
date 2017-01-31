#ifndef CONTRIOLLER_H
#define CONTRIOLLER_H
//#include <QObject>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include "Player.h"
#include "score.h"
#include "fuel.h"
class Contrioller : public QGraphicsView
{
public:
    Contrioller(QWidget* parent = 0);
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Fuel* fuel;

//public slots:
//    void show(QGraphicsView* view);
};

#endif // CONTRIOLLER_H
