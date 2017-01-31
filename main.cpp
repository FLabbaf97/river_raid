//
// Created by Ashkar on 1/31/2017.
//

#include <iostream>
#include <vector>
#define WIDTH 800
#define HEIGHT 600
using namespace std;
//comment to test pulling

enum class Type{helicopter = 60 , nave  = 30, baloon  = 60 , jet = 100, fueldepot = 150};

class Item{
protected:
    int x , y , height , width;
public:
    Item(int x , int y , int height , int width) : x(x) , y(y) , height(height) , width (width) {}
    virtual void show() = 0;
    bool collide(int x , int y);
};

class PLayer:public Item{
    int fuel_rate;
public:
    PLayer(int x, int y, int height, int width) : Item(x, y, height, width) {fuel_rate = 100;}
    void icrease_fuel();///passing fuel depot
    void decrease_fuel(int rate); /// moving forward
    int get_fuel();
    void move_right();
    void move_left();
    virtual void show();
    ~Player();
};

class Enemy : public Item{/// if it collided with the player, scene checks if it's fuel depot or not
    Type type;
    int score;
public:
    Enemy(int x, int y = 0, int height, int width , Type t) : Item(x, y, height, width) {
        type = t;
        score = (int)t;
    }
    int get_score();
    Type get_type();
    void move_forward();
    virtual void show();
    ~Enemy();
};


class Bullet : public Item {
public:
    Bullet(int x, int y, int height = 15, int width = 1) : Item(x, y, height, width) {}
    ~Bullet();
    void move_forward();
    virtual void show();
};

class Scene{
    Item* player;
    vector<Enemy*> enemy;
    vector<Enemy*> fuel_depot;
    vector<Bullet*> bullet;
    int total_score;
public:
    Scene(){
        player = new PLayer(WIDTH/2 - 25 , HEIGHT - 60 , 50 , 50);
    }
    void go_forward();///moves every one forward , checks for collisions , decrease fuel , increase total score\
    // generates fuel depots or enemies , deletes who ever exits the plane , game over when fuel finishes
    void command(string);//start , right , left , shoot , enter ---> goes forward after doing the command
    ~Scene();
};

int main(){
    /////
}