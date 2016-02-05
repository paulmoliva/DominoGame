#ifndef CPLAYER_H
#define CPLAYER_H
#include "crandom.h"
#include<QList>
#include "cdomino.h"

class CPlayer : public CRandom
{
public:
    CPlayer();
    ~CPlayer(){} // destructor
    std::deque<data_domino> gotHand;
    class CDomino *player_pDominoOBJ=NULL;
    // PASSING OBJECT AS POINTER - FOR DIFFERENT CLASSES INTERFACE
    void API(CDomino *receive_dominoPointerOBJ);
    int takePiece(int pieceNo);

};

#endif // CPLAYER_H
