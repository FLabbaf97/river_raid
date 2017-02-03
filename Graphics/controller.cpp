#include "controller.h"
#include "Player.h"
#include <QDebug>
#include <QTimer>
#include <enemy.h>
#include <QVector>
#include <bullet.h>
controller::controller()
{
    //creat scene
    scene = new QGraphicsScene;
    setScene(scene);
    //creat player
    player = new Player;
    player->setRect(0 , 0 , 100 , 50);
    //creat score & fuel
    score = new Score;
    fuel = new Fuel;
    fuel -> setPos(fuel->x() , fuel->y() + 25);

    //add items  to scen
    scene->addItem(player);
    scene->addItem(score);
    scene->addItem(fuel);

    // set focus on player
    player->setFlag(QGraphicsRectItem:: ItemIsFocusable);
    player->setFocus();

    // add to view
    QGraphicsView* view = new QGraphicsView(scene);


    // fix the view and set position of player
    view->setFixedSize(800 , 600);
    scene->setSceneRect(0 , 0 ,800 , 600);
    player->setPos(view->width()/2 , view->height()  - 100);


   // creat enemy every 2 seconds
    QTimer* timer2 = new QTimer;
    controller::connect(timer2 , SIGNAL(timeout()) ,this , SLOT(create_enemy()));
    timer2->start(2000);
    QTimer* timer3 = new QTimer;
    controller::connect(timer3 , SIGNAL(timeout()) , this , SLOT(routine()));
    timer3->start(50);
    show();
}

void controller::create_enemy()
{
    enemy* enemy1 = new enemy(rand()%5);
    this->scene->addItem(enemy1);
    enemies.push_back(enemy1);
}

void controller::routine()
{
    fuel->decrease();
    for(int i = 0; i < enemies.size() ; i++){
        if(enemies[i]->y() > 600){
            scene->removeItem(enemies[i]);
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
            break;
        }
        if(enemies[i]->collidesWithItem(player)){

            if(enemies[i]->get_type() == 4){////was a fule depot
                fuel->increase();
                qDebug()<< "collision with fuel depot";
                continue;
            }
            qDebug() << "collision with enemy";
            scene->removeItem(enemies[i]);
            delete enemies[i];
            enemies.erase(enemies.begin() + i);

            break;
        }
    }
    //    for(/*int i = 0 ; i < enemies.size(); i++){
    //        if(enemies[i]->collidesWithItem(Bullet)){
    //            qDebug() << "collsion with Bullet";
    //        }
    //    }*/
}
