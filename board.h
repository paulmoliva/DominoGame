#ifndef BOARD_H
#define BOARD_H
#include <QList>
#include <iostream>
#include "cdomino.h"
#include <QGraphicsPixmapItem>
#include <deque>
#include<QString>
#include<QKeyEvent>
#include<QDebug>
#include<QInputDialog>
#include<QDir>
#include<string>
#include<cstdlib>
#include<stdlib.h>


class Board: public QGraphicsPixmapItem
{

public:
    Board();
    ~Board() {}

    std::deque<CDomino*> getDominos();
    void keyPressEvent(QKeyEvent *event);
    void clearBoard();
    void placeDominos(int x, int y, int num, int size, std::deque<data_domino> stack);
    void placeNumber(int x, int y, int size, data_domino dom);

    std::deque<data_domino> board;
    class CDomino *player_pDominoOBJ=NULL;
    class CPlayer *playerOBJ=NULL;
    bool gameOver=false;
    struct ai{
        int counterHeads = 0;
        int counterMoves = 0;
    };
    void drawAPiece(int playerID);
    bool goodPiece(int move, int playerID);
    bool goodSpot(int move, int playerID, char pos);
    void selecting_pieces();
    void nextTurn (int *turn);
    void showPlayerHand(void);
    void showPlayerHand(int playerID);
    void initialMove(int playerID);
    void move(int playerID);
    void declareWinner();
    void printBoard();
    int moveAvailable(int playerID);
    void API(CPlayer *receive_playersOBJ, CDomino *receive_dominoPointerOBJ, int *turn);

private:
    QList<CDomino*> dominos;
    void createDominoRow(int x, int y, int numDominos, int size, std::deque<data_domino> stack);


};

#endif // BOARD_H
