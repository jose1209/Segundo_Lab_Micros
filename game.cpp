#include "game.h"
#include "block.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>


Game::Game(QWidget* parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/imagenes/fondo_2.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);

    // create a ball
    Ball* ball = new Ball();
    ball->setPos(400,500);
    scene->addItem(ball);

    // create the player
    player = new Player();
    player->setPos(400,570); // TODO generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);
    // create the blocks grid
    for (size_t a = 0, n = 13; a < n; ++a){
        for (size_t i = 0, n = 5; i < n; ++i){
            Block* block = new Block();
            block->setPos(a*62+18,i*32+20); // 2 space b/w blocks (50 height of block)
            scene->addItem(block);
    }
    }


   // create the score/health
    score = new Score();
    score->setPos(score->x()+870,score->y()+50);
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x()+870,health->y()+25);
    scene->addItem(health);


    show();
}


