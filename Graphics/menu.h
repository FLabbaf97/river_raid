#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QWidget>

class menu : public QDialog
{
    Q_OBJECT
private:
    QPushButton* Play;
    QLabel* topScore;
    QWidget* startPage;
public:
    menu(QDialog *parent = 0);

signals:

public slots:
};

#endif // MENU_H
