#include "button.h"




void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

}

void Button::clicked()
{

}
