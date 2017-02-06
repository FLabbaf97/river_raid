#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include "score.h"
#include <controller.h>
class menu : public QDialog
{
    Q_OBJECT
private:
    QPushButton* Play;
    QLabel* topScore;
    int topscore;
    QWidget* startPage;
    controller* game;
public:
    menu(QDialog *parent = 0);

public slots:
    void start_game();
    void change_high_score(Score* score);
};

#endif // MENU_H
