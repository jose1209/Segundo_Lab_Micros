#-------------------------------------------------
#
# Project created by QtCreator 2016-09-11T23:46:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arkanoid1_0
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    game.cpp \
    block.cpp \
    health.cpp \
    score.cpp \
    ball.cpp

HEADERS  += \
    player.h \
    game.h \
    block.h \
    health.h \
    score.h \
    ball.h

RESOURCES += \
    res.qrc
