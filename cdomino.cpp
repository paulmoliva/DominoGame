//========================================================================//
//========================================================================//

#include "cdomino.h"
#include "QDebug"
using namespace std;

CDomino::CDomino(QGraphicsItem *parent, int SCALE_BY)
{
    QVector<QPointF> dominoPoints;
    dominoPoints << QPointF(0,0) << QPointF(2,0) << QPointF(2,1) << QPointF(0,1);

    for (size_t i = 0, n=dominoPoints.size(); i <n; i++){
        dominoPoints[i] *= SCALE_BY;
    }

    QPolygonF domino(dominoPoints);

    setPolygon(domino);


}

void CDomino::API()
{
    init();
}

data_domino CDomino::getPiece(int pieceID)
{
    data_domino mypiece=myDomino[pieceID];
    cout <<"["<< mypiece.left << "|"<< mypiece.right <<"]"
            << " available = " << mypiece.available << endl;

    myDomino[pieceID]=mypiece;
    return(mypiece);
}

void CDomino::removePiece(int pieceNo)
{
        myDomino.erase(myDomino.begin()+pieceNo);
}

void CDomino::init()
{
    data_domino mypiece;
    for(int right=0;right<7;right++){
        for(int left=right; left<7;left++){
            mypiece.right=right;
            mypiece.left=left;
            mypiece.available=1;
            qDebug() <<"["<< mypiece.left << "|"<< mypiece.right <<"]"<< "  ";
            myDomino.push_back(mypiece);
        }
        qDebug() << endl;
    }
    qDebug() << "myDomino stores " << (int) myDomino.size() << " pieces.\n";
}







