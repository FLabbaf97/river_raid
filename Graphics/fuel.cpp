#include "fuel.h"
#include <QFont>
#include <QGraphicsTextItem>
#define FUELNUMBER 50

Fuel::Fuel(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    fuel = 100;
    // draw
    setPlainText(QString("FUEL: ") + QString :: number(fuel));
    setDefaultTextColor(Qt :: red);
    setFont(QFont("Times" , 16));
}

void Fuel::increase()
{
    if(fuel + FUELNUMBER >= 100)
        fuel += FUELNUMBER;
    else
        fuel = 100;
    setPlainText(QString("FUEL: ") + QString :: number(fuel));
}

void Fuel::decrease()
{
    fuel--;
    setPlainText(QString("FUEL: ") + QString :: number(fuel));

}

int Fuel::get_fuel()
{
    return fuel;
}
