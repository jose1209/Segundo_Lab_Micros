#include "block.h"
#include <QBrush>
#include <QGraphicsScene>

Block::Block(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // draw rect
    setPixmap(QPixmap(":/imagenes/bloque_verde.png"));
    /*setRect(16,16,60,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);*/
}
