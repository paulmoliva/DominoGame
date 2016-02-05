#include "game.h"
#include "board.h"
#include <QImage>
#include "cplayer.h"
#include"startbutton.h"
#include<QGraphicsTextItem>



Game::Game(QWidget *parent){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setBackgroundBrush(QBrush(QImage(":/img/wood.jpg")));
    setScene(scene);

}

void Game::clearBoard()
{
    scene->clear();
}

void Game::start()
{
    /*hand = new Board();
    hand->placeDominos(100,600,10, 40);

    board = new Board();
    //pos = 512-size*num
    board->placeDominos(512-80,200,4, 20);*/
    scene->clear();

    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl("qrc:/sound/domino.wav"));
    player->play();

    struct timeval time;
    int pieceID;

    gettimeofday(&time, NULL);
    srand((unsigned int) time.tv_usec);

    CDomino dominoOBJ,*dominoPointer;
    dominoOBJ.API();
    dominoPointer=&dominoOBJ;

    // EXAMPLE: PASSING OBJECT AS A NEW POINTER
    //			- FOR DIFFERENT CLASSES INTERFACE
    CPlayer *playerOBJ;
    playerOBJ=new CPlayer[2];
    playerOBJ[0].API(dominoPointer);
    playerOBJ[1].API(dominoPointer);

    CRandom n;
    int turn, *turnPointer;
    turn = n.getRandomPublic(0,1);
    turnPointer = &turn;

    Board myTableObj;
    Board *b;
    b=new Board;
    b->setFlag(QGraphicsItem::ItemIsFocusable);
    b->setFocus();
    myTableObj.API(playerOBJ,&dominoOBJ ,turnPointer);




}

void Game::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Oh, Domino!"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tYpos = 150;
    titleText->setPos(txPos, tYpos-27);
    scene->addItem(titleText);

    StartButton* playButton = new StartButton(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    StartButton* quitButton = new StartButton(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);



}
