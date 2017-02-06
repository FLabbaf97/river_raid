#-------------------------------------------------
#
# Project created by QtCreator 2017-02-03T14:12:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = river_raid
TEMPLATE = app


SOURCES += main.cpp\
    bullet.cpp \
    enemy.cpp \
    fuel.cpp \
    score.cpp \
    Player.cpp \
    controller.cpp \
    menu.cpp    \
    margin.cpp

HEADERS  += \
    bullet.h \
    controller.h \
    enemy.h \
    fuel.h \
    score.h \
    Player.h \
    menu.h  \
    margin.h

RESOURCES += \
    resources.qrc
