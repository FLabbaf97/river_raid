#ifndef FUEL_H
#define FUEL_H
#include <QGraphicsTextItem>

class Fuel : public QGraphicsTextItem
{
public:
    Fuel(QGraphicsItem* parent = 0);
    void increase();
    void decrease();
    int get_fuel();
private:
    int fuel;
};

#endif // FUEL_H
