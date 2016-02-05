#ifndef GAME
#define GAME
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "board.h"
#include <QMediaPlayer>


class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);


    void displayMainMenu();
    void clearBoard();

    Board* board;
    Board* hand;
    QGraphicsScene* scene;

    QString whoseTurn;

public slots:
    void start();
};

#endif // GAME

