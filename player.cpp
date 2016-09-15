#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QBrush>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/imagenes/plataforma.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 20)        //Prueba y error los limites
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }

}

double Player::getCenterX(){
    return x()+pixmap().width()/2;
}


void Player::spawn(){

}
