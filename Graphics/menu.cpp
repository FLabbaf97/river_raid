#include "menu.h"

#include <QLayout>
#include <QDebug>

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
}
