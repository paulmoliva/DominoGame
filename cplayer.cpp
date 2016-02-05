#include "cplayer.h"
using namespace std;
CPlayer::CPlayer()
{

}

void CPlayer::API(CDomino *receive_dominoPointerOBJ)
{
    int pieceID;
    player_pDominoOBJ=receive_dominoPointerOBJ;
}

int CPlayer::takePiece(int pieceNo)
{
    int playerID;
    int counter=0,max=14, number_wasAvailable=0;

    data_domino takenPiece;
    takenPiece=player_pDominoOBJ->getPiece(pieceNo);

    //if(takenPiece.available){
        number_wasAvailable=takenPiece.available;
    //	takenPiece.available=0; // no longer available from the dominoes pile
        player_pDominoOBJ->myDomino.at(pieceNo)=takenPiece;
        cout << " ["<< takenPiece.left
                << "|"<< takenPiece.right <<"]"
                      << " just taken - no longer available from pile = "
                << takenPiece.available << endl;
        takenPiece.available=1; // available on Player's hand
        gotHand.push_back(takenPiece);
        player_pDominoOBJ->myDomino.at(pieceNo);
        player_pDominoOBJ->removePiece(pieceNo);



    //}else{
    //	cout << "NOT AVAILABLE" << endl;
    //}
    return (number_wasAvailable);
}


