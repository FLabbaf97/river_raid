#include "score.h"
#include <QFont>
#include <QGraphicsTextItem>
#define SCORENUMBER 5
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    // draw
    setPlainText(QString("SCORE: ") + QString :: number(score));
    setDefaultTextColor(Qt :: blue);
    setFont(QFont("Times" , 16));
}

void Score::increase()
{
    score += SCORENUMBER;
     setPlainText(QString("SCORE: ") + QString :: number(score));
}


int Score::get_score()
{
    return score;
}
