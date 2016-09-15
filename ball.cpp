#include "ball.h"
#include <QTimer>
#include <QBrush>
#include "game.h"
#include "player.h"
#include "block.h"
#include <QGraphicsScene>

extern Game* game;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw rect
     setPixmap(QPixmap(":/imagenes/bolapng.png"));
/*    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);*/

// move up right initially
     xVelocity = 0;
     yVelocity = -5;

     QTimer* timer = new QTimer();
     connect(timer,SIGNAL(timeout()),this,SLOT(move()));
     timer->start(25);
 }

double Ball::getCenterX(){
    return x() + pixmap().width()/2;
}

void Ball::move(){
    // if out of bounds, reverse the velocity
//    reverseVelocityIfOutOfBounds();

    // if collides with paddle, reverse yVelocity, and add xVelocity
    // depending on where (in the x axis) the ball hits the paddle
    handlePaddleCollision();

    // handle collisions with blocks (destroy blocks and reverse ball velocity)
    handleBlockCollision();

    moveBy(xVelocity,yVelocity);

}

void Ball::handlePaddleCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Player* player = dynamic_cast<Player*>(cItems[i]);
        if (player){
            // collides with paddle

            // reverse the y velocity
            yVelocity = -1 * yVelocity;

            // add to x velocity depending on where it hits the paddle
            double ballX = getCenterX();
            double playerX = player->getCenterX();

            double dvx = ballX - playerX;
            xVelocity = (xVelocity + dvx)/15;

            return;
        }
    }
}

void Ball::handleBlockCollision(){
    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Block* block = dynamic_cast<Block*>(cItems[i]);
        // collides with block
        if (block){
            double yPad = 15;
            double xPad = 15;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();

            // collides from bottom
            if (bally > blocky + yPad && yVelocity < 0){
                yVelocity = -1 * yVelocity;
            }

            // collides from top
            if (blocky > bally + yPad && yVelocity > 0 ){
                yVelocity = -1 * yVelocity;
            }

            // collides from right
            if (ballx > blockx + xPad && xVelocity < 0){
                xVelocity = -1 * xVelocity;
            }

            // collides from left
            if (blockx > ballx + xPad && xVelocity > 0){
                xVelocity = -1 * xVelocity;
            }

            // delete block(s)
            game->scene->removeItem(block);
            delete block;
        }
    }
}



/*
void Ball::reverseVelocityIfOutOfBounds(){
    // check if out of bound, if so, reverse the proper velocity
    double screenW = game->width();
    double screenH = game->height();

    // left edge
    if (mapToScene(ball().topLeft()).x() <= 0){
        xVelocity = -1 * xVelocity;
    }

    // right edge
    if (mapToScene(ball().topRight()).x() >= screenW){
        xVelocity = -1 * xVelocity;
    }

    // top edge
    if (mapToScene(ball().topLeft()).y() <= 0){
        yVelocity = -1 * yVelocity;
    }

    // bottom edge - NONE (can fall through bottom
}*/

