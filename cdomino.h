#ifndef CDOMINO_H
#define CDOMINO_H
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <iostream>
#include <deque>
#include <ctime>
#include <deque>
#include <QGraphicsPolygonItem>
struct data_domino{
    int right, left, available;
};

class CDomino: public QGraphicsPolygonItem
{
public:
    CDomino(QGraphicsItem* parent = NULL, int SCALE_BY = 20);  // constructor
    ~CDomino(){} // destructor
    std::deque<data_domino> myDomino;
    void API(void);
    data_domino getPiece(int pieceID);

    void removePiece(int pieceNo);

private:
    void init(void);
};

#endif // CDOMINO_H
