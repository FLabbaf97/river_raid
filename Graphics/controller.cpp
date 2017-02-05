#include "controller.h"
#include "Player.h"
#include <QDebug>
#include <QTimer>
#include <enemy.h>
#include <QVector>
#include <typeinfo>
#include <QThread>
#include "bullet.h"

controller::controller()
{
    //creat scene
    scene = new QGraphicsScene;
    setScene(scene);
    //creat player
    player = new Player;
//    player->setRect(0 , 0 , 100 , 50);

    //creat score & fuel
    score = new Score;
    fuel = new Fuel;
    fuel -> setPos(fuel->x() , fuel->y() + 25);

    //add items  to scen

    scene->addItem(score);
    scene->addItem(fuel);
    scene->addItem(player);
    //back ground us blue!
    scene->setBackgroundBrush(* new QBrush(Qt::lightGray));
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
    int x = rand()%8;
    qDebug() << x;
    QVector <enemy*> temp;
    for(int i = 0 ; i < x ; i++){
        enemy* enemy1 = new enemy(rand()%5);
        scene->addItem(enemy1);
        bool flag = false;
        for(int j = 0 ; j < temp.size() ; j++){
            if(enemy1->collidesWithItem(temp[j])){
                scene->removeItem(enemy1);
                delete enemy1;
                flag = true;
                break;
            }
        }
        if(!flag){
            enemies.push_back(enemy1);
            temp.push_back(enemy1);
        }

    }
}

void controller::routine()
{
    player->setZValue(1);
    fuel->decrease();


    for(int i = 0; i < enemies.size() ; i++){
        if(enemies.at(i)->y() > 600){
                    scene->removeItem(enemies.at(i));
                    delete enemies.at(i);
                    enemies.erase(enemies.begin() + i);
                    continue;
        }
        QList <QGraphicsItem* > colliding_items = enemies.at(i)->collidingItems();
        for(int j = 0; j < colliding_items.size(); j++){
            if(typeid(*(colliding_items.at(j))) == typeid(Bullet)){
                score->increase(enemies.at(i)->getval());
                scene->removeItem(colliding_items.at(j));
                scene->removeItem(enemies.at(i));
                delete colliding_items.at(j);
                colliding_items.erase(colliding_items.begin()+j);
                delete enemies.at(i);
                enemies.erase(enemies.begin() + i);
                qDebug() << "enemy deleted by a shot";
                qDebug() << "bullet deleted bo colliding na enemy";
                continue;
            }

            //if player collided with an enemy(or fuel depot)
            if(typeid(*(colliding_items.at(j))) == typeid(Player)){
                //if it was only fuel depot
                if(enemies.at(i)->get_type() == 4)///fuel depot
                {
                    fuel->increase();
                    qDebug() << "fuel depot!";
                    continue;
                }
                //if game over
                else
                {
                    scene->removeItem(enemies.at(i));
                    delete enemies.at(i);
                    enemies.erase(enemies.begin()+i);
                    qDebug() << "player collided with enemy";
                    qDebug() << "****************************** GAME OVER ************************";

                }
            }
         }

    }


}
