#ifndef STARTBUTTON_H
#define STARTBUTTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class StartButton : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    StartButton(QString name, QGraphicsItem *parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
private:
    QGraphicsTextItem* text;

};

#endif // STARTBUTTON_H
