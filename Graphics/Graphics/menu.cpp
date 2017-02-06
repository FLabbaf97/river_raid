#include "menu.h"

#include <QLayout>
#include <QDebug>
#include <controller.h>

menu::menu(QDialog *parent) : QDialog(parent)
{

//    qDebug() << "here heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeyyyyyyyyyyy";
    //allocate button and ..
    Play = new QPushButton("Play now");
    topScore = new QLabel("New Top Score");
    topScore->setAlignment(Qt:: AlignCenter);
    //set start layout
    QVBoxLayout * startLayout = new QVBoxLayout;
    startLayout->setContentsMargins(0, 0 , 0, 50);
    startLayout->addWidget(Play);

    //set start widget
    startPage = new QWidget;
    startPage->setLayout(startLayout);
    startPage->show();
//    game = new controller();
//    game->show();
    game = NULL;
    connect(Play , SIGNAL(clicked()) , this , SLOT(start_game()));
}

void menu::start_game()
{
//    change_high_score(game->score);
//    if(game)
//        delete game;

    game = new controller();
    game->show();
}

void menu::change_high_score(Score *score)
{
    if(score->get_score() > topscore)
        topscore = score->get_score();
}
