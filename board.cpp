#include "board.h"
#include "game.h"
#include "cplayer.h"
#include "button.h"
using namespace std;

extern Game* game;

Board::Board()
{

}

void Board::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Pressed.";
}

/*deque<CDomino *> Board::getDominos()
{
    return dominos;
}*/

/*int Board::keyPress()
{
    QKeyEvent() n;
    int playerMove;
    if (n.key()== Qt::Key_0)
        playerMove = 0;
    if (n.key() == Qt::Key_1)
        playerMove = 1;
    if (n.key() == Qt::Key_2)
        playerMove = 2;
    if (n.key() == Qt::Key_3)
        playerMove = 3;
    if (n.key() == Qt::Key_4)
        playerMove = 4;
    if (n.key() == Qt::Key_5)
        playerMove = 5;
    if (n.key() == Qt::Key_6)
        playerMove = 6;
    if (n.key() == Qt::Key_7)
        playerMove = 7;
    if (n.key() == Qt::Key_8)
        playerMove = 8;
    if (n.key() == Qt::Key_9)
        playerMove = 9;

    return playerMove;

}*/

void Board::clearBoard()
{
    game->scene->clear();
}

void Board::placeDominos(int x,int y,int num,int size, deque<data_domino> stack)
{
    createDominoRow(x,y,num,size, stack);
}

void Board::createDominoRow(int x, int y, int numDominos, int size, std::deque<data_domino> stack)
{
    int gap = size*2 + 5;
    for (size_t i =0, n=numDominos; i<n; i++){
        CDomino* cdomino = new CDomino(NULL, size);
        cdomino->setPos(x+gap*i, y);
        dominos.append(cdomino);
        game->scene->addItem(cdomino);
        placeNumber(x+gap*i, y, size, stack.at(i));

    }
}

void Board::placeNumber(int x,int y, int size, struct data_domino dom){

    QString right, left;
    if (dom.left == 1)
        left = ":/img/1.png";
    else if(dom.left == 2)
        left = ":/img/2.png";
    else if(dom.left == 3)
        left = ":/img/3.png";
    else if(dom.left == 4)
        left = ":/img/4.png";
    else if(dom.left == 5)
        left = ":/img/5.png";
    else if(dom.left == 6)
        left = ":/img/6.png";
    else
        left = ":/img/huh.png";

    if (dom.right == 1)
        right = ":/img/1.png";
    else if(dom.right == 2)
        right = ":/img/2.png";
    else if(dom.right == 3)
        right = ":/img/3.png";
    else if(dom.right == 4)
        right = ":/img/4.png";
    else if(dom.right == 5)
        right = ":/img/5.png";
    else if(dom.right == 6)
        right = ":/img/6.png";
    else
        right = ":/img/huh.png";

    Button *myItem=new Button(QPixmap(left));
    myItem->setPos(x,y);
    if(size == 40)
        myItem->setScale(2);
    else{
        myItem->setScale(.75);
        myItem->setAcceptHoverEvents(true);
        myItem->num = dom.left;
    }
    game->scene->addItem(myItem);

    Button *myItem2=new Button(QPixmap(right));
    if(size==40)
        myItem2->setPos(x+40,y);
    else
        myItem2->setPos(x+15,y);

    if(size == 40)
        myItem2->setScale(2);
    else{
        myItem2->setScale(.75);
        myItem2->setAcceptHoverEvents(true);
        myItem2->num = dom.right;
    }
    game->scene->addItem(myItem2);



    //item->setScale(1);
    //item->setPos(100,100);
    //game->scene->addItem(item);
}

void Board::drawAPiece(int playerID)
{
    int pieceNO,pieceWasAvailable=0;
    cout << "Drawing a piece." << endl;

    while(!pieceWasAvailable){
        pieceNO=playerOBJ[playerID].getRandomPublic(0,player_pDominoOBJ->myDomino.size()-1);
        pieceWasAvailable=playerOBJ[playerID].takePiece(pieceNO);
    }
}

bool Board::goodPiece(int move, int playerID)
{
    if (playerOBJ[playerID].gotHand.at(move).left == board.at(board.size() - 1).right || playerOBJ[playerID].gotHand.at(move).right == board.at(board.size() - 1).right
            || playerOBJ[playerID].gotHand.at(move).left == board.at(0).left || playerOBJ[playerID].gotHand.at(move).right == board.at(0).left)
        return true;
    return false;
}

bool Board::goodSpot(int move, int playerID, char pos)
{
    if (pos == 't')
        if (playerOBJ[playerID].gotHand.at(move).left == board.at(board.size() - 1).right || playerOBJ[playerID].gotHand.at(move).right == board.at(board.size() - 1).right)
            return true;
        else
            return false;
    else
        if (playerOBJ[playerID].gotHand.at(move).left == board.at(0).left || playerOBJ[playerID].gotHand.at(move).right == board.at(0).left)
            return true;
        else
            return false;
}

void Board::selecting_pieces()
{
    int pieceNO,piece_wasAvailable,totalPlayer=2;
    cout << "selecting pieces and giving 12 pieces to each player" << endl;

    for(int playerID=0;playerID<totalPlayer;playerID++){
        for(int i=0; i<10; i++){
            pieceNO=playerOBJ[playerID].getRandomPublic(0,(int) player_pDominoOBJ->myDomino.size()-1);
            cout <<" pieceNO : "<< pieceNO << endl;
            piece_wasAvailable=playerOBJ[playerID].takePiece(pieceNO);

            if(piece_wasAvailable){
                cout<< "piece available" << endl;
            }else{
                cout<< "////////////////////////////////////////////////" << endl;
                cout<< "piece not available - try to take a piece again" << endl;
                i--;
            }
        }
    }
}

void Board::nextTurn(int *turn)
{
    if(*turn == 1)
        {
        *turn =0;
        }
    else
        {
        *turn = 1;
        }
    cout << "Player " << *turn << "'s turn." <<endl;
}

void Board::showPlayerHand()
{
    data_domino showpiece;
    int totalPlayer = 2;
    for(int playerID=0;playerID<totalPlayer;playerID++){
        cout << "playerID = " << playerID << " stores " <<
                playerOBJ[playerID].gotHand.size() << " pieces.\n";
        for(int pieceNo=0; pieceNo<playerOBJ[playerID].gotHand.size(); pieceNo++){
            showpiece=playerOBJ[playerID].gotHand.at(pieceNo);
            cout <<"["<< showpiece.left << "|"<< showpiece.right <<"]"
                << " available = " << showpiece.available << endl;
        }
    }
}

void Board::showPlayerHand(int playerID)
{

    data_domino showpiece;
    if( playerID == 0){
        cout << "playerID = " << playerID << " has " <<
                playerOBJ[playerID].gotHand.size() << " pieces.\n";
        for(int pieceNo=0; pieceNo<playerOBJ[playerID].gotHand.size(); pieceNo++){
            showpiece=playerOBJ[playerID].gotHand.at(pieceNo);
            // if(showpiece.available == 1){
            placeDominos(50,600,playerOBJ[playerID].gotHand.size(), 40, playerOBJ[playerID].gotHand);
            // }

            QGraphicsTextItem *n = new QGraphicsTextItem;
            n->setPlainText(QString::number(pieceNo));
            n->setPos(60+84*pieceNo, 650);
            n->setDefaultTextColor(Qt::red);
            n->setFont(QFont("times", 40,75));

            game->scene->addItem(n);
        }
    }
    /*
        cout << "playerID = " << playerID << " has " <<
                playerOBJ[playerID].gotHand.size() << " pieces.\n";
        for(int pieceNo=0; pieceNo<playerOBJ[playerID].gotHand.size(); pieceNo++){
            showpiece=playerOBJ[playerID].gotHand.at(pieceNo);*/
    if(gameOver==true){
        placeDominos(50,100,playerOBJ[1].gotHand.size(), 40, playerOBJ[1].gotHand);



    }


    QGraphicsTextItem *pieces = new QGraphicsTextItem;
    pieces->setPlainText(QString("Robot Color Candy has " + QString::number(playerOBJ[1].gotHand.size()) + " pieces left."));
    pieces->setPos(300,0);
    pieces->setDefaultTextColor(Qt::red);
    pieces->setFont(QFont("times", 20,75));
    game->scene->addItem(pieces);

    Button *robot=new Button(QPixmap(":/img/robotCav"));
    robot->setPos(300,200);
    game->scene->addItem(robot);

    QGraphicsTextItem *p = new QGraphicsTextItem;
    p->setPlainText(QString("Current opponent: Robot Color Candy"));
    p->setPos(290, 190);
    p->setDefaultTextColor(Qt::red);
    p->setFont(QFont("times", 20,75));
    game->scene->addItem(p);


}


void Board::initialMove(int playerID)
{
    int move;
    bool isAi;
    if(playerID==1)
        isAi = true;
    else
        isAi = false;
    if (isAi)
        move = 0;
    else
    {
        //cout << "Enter piece number to play: ";
        string num;
        bool ok;
        QInputDialog* inputDialog = new QInputDialog();
        inputDialog->setOptions(QInputDialog::NoButtons);

        QString text =  inputDialog->getText(NULL ,"Move Input",
                                             "Piece # to play:", QLineEdit::Normal,
                                             "0", &ok);

        if (ok && !text.isEmpty())
        {
            num=text.toStdString();
            move = std::atoi(num.c_str());
        }


        //move = keyPress();
    }
    playerOBJ[playerID].gotHand.at(move).available=0;
    board.push_back(playerOBJ[playerID].gotHand.at(move));
    playerOBJ[playerID].gotHand.erase(playerOBJ[playerID].gotHand.begin()+move);
    clearBoard();
}

void Board::move(int playerID)
{
    int move;
    char pos;
    const char *r;
    bool isMove = false;
    bool isAi;
    if(playerID==1)
        isAi = true;
    else
        isAi = false;
    ai bob;
    if (moveAvailable(playerID)){
        if(player_pDominoOBJ->myDomino.size() != 0 && playerOBJ[0].gotHand.size() != 0 && playerOBJ[1].gotHand.size() != 0){
            while (true){
                cout << "Enter piece number to play: ";
                if (isAi == true)
                {
                    move = bob.counterMoves;
                    bob.counterMoves++;
                }
                else{
                    //cin >> move;
                    //move = keyPressEvent(*event);

                    string num;
                    bool ok;
                    QInputDialog* inputDialog = new QInputDialog();
                    inputDialog->setOptions(QInputDialog::NoButtons);

                    QString text =  inputDialog->getText(NULL ,"Move Input",
                                                         "Piece # to play:", QLineEdit::Normal,
                                                         "0", &ok);

                    if (ok && !text.isEmpty())
                    {
                        num=text.toStdString();
                        move = std::atoi(num.c_str());
                    }


                }
                isMove = goodPiece(move, playerID);
                if (isMove)
                    break;
                else
                    cout << "That is not a valid move." << endl;
            }

            isMove = false;
            playerOBJ[playerID].gotHand.at(move).available=0;


            while(true){
                cout << "Play domino at head or tail? (h/t)" <<endl;
                if (isAi == true)
                {
                    if (pos % 2 == 1)
                        pos = 't';
                    else
                    {
                        pos = bob.counterHeads;
                        bob.counterHeads++;
                    }
                }
                else{
                    //cin >> pos;

                    string num;
                    bool ok;
                    QInputDialog* inputDialog = new QInputDialog();
                    inputDialog->setOptions(QInputDialog::NoButtons);

                    QString text =  inputDialog->getText(NULL ,"Move Input",
                                                         "Play at Head or tail? h/t", QLineEdit::Normal,
                                                         "h", &ok);

                    if (ok && !text.isEmpty())
                    {
                        num=text.toStdString();
                        r = num.c_str();
                        pos = r[0];
                    }

                }
                isMove = goodSpot(move, playerID, pos);
                if (isMove)
                    break;
                else
                    cout << "That is not a valid spot." << endl;
            }

            if (pos == 't'){
                if (playerOBJ[playerID].gotHand.at(move).left == board.at(board.size()-1).right)
                    board.push_back(playerOBJ[playerID].gotHand.at(move));

                else {
                    int tmp = playerOBJ[playerID].gotHand.at(move).left;
                    playerOBJ[playerID].gotHand.at(move).left = playerOBJ[playerID].gotHand.at(move).right;
                    playerOBJ[playerID].gotHand.at(move).right = tmp;
                    board.push_back(playerOBJ[playerID].gotHand.at(move));
                }

                playerOBJ[playerID].gotHand.erase(playerOBJ[playerID].gotHand.begin()+move);

            }
            else {
                if (playerOBJ[playerID].gotHand.at(move).right == board.at(0).left)
                    board.push_front(playerOBJ[playerID].gotHand.at(move));

                else {
                    int tmp = playerOBJ[playerID].gotHand.at(move).left;
                    playerOBJ[playerID].gotHand.at(move).left = playerOBJ[playerID].gotHand.at(move).right;
                    playerOBJ[playerID].gotHand.at(move).right = tmp;
                    board.push_front(playerOBJ[playerID].gotHand.at(move));

                }

                playerOBJ[playerID].gotHand.erase(playerOBJ[playerID].gotHand.begin()+move);

            }
        }
        else
            gameOver=true;
    }
    else{
        if(player_pDominoOBJ->myDomino.size() != 0 && playerOBJ[0].gotHand.size() != 0 && playerOBJ[1].gotHand.size() != 0){
            while (!moveAvailable(playerID) && player_pDominoOBJ->myDomino.size() != 0){
                drawAPiece(playerID);
                showPlayerHand(playerID);
                printBoard();
            }
            if(moveAvailable(playerID)){
                while (true){
                    cout << "Enter piece number to play: ";
                    if (isAi == true)
                    {
                        move = bob.counterMoves;
                        bob.counterMoves++;
                    }
                    else{
                        //cin >> move;
                        //move = keyPressEvent(*event);
                        string num;
                        bool ok;
                        QInputDialog* inputDialog = new QInputDialog();
                        inputDialog->setOptions(QInputDialog::NoButtons);

                        QString text =  inputDialog->getText(NULL ,"Move Input",
                                                             "Piece # to play:", QLineEdit::Normal,
                                                             "0", &ok);

                        if (ok && !text.isEmpty())
                        {
                            num=text.toStdString();
                            move = std::atoi(num.c_str());
                        }

                    }
                    isMove = goodPiece(move, playerID);
                    if (isMove)
                        break;
                    else
                        cout << "That is not a valid move." << endl;
                }

                isMove = false;
                playerOBJ[playerID].gotHand.at(move).available=0;


                while(true){
                    cout << "Play domino at head or tail? (h/t)" <<endl;
                    if (isAi == true)
                    {
                        if (pos % 2 == 1)
                            pos = 't';
                        else
                        {
                            pos = bob.counterHeads;
                            bob.counterHeads++;
                        }
                    }
                    else{
                        //cin >> pos;

                        string num;
                        bool ok;
                        QInputDialog* inputDialog = new QInputDialog();
                        inputDialog->setOptions(QInputDialog::NoButtons);

                        QString text =  inputDialog->getText(NULL ,"Move Input",
                                                             "Play at Head or tail? h/t", QLineEdit::Normal,
                                                             "h", &ok);

                        if (ok && !text.isEmpty())
                        {
                            num=text.toStdString();
                            r = num.c_str();
                            pos = r[0];
                        }

                    }
                    isMove = goodSpot(move, playerID, pos);
                    if (isMove)
                        break;
                    else
                        cout << "That is not a valid spot." << endl;
                }

                if (pos == 't'){
                    if (playerOBJ[playerID].gotHand.at(move).left == board.at(board.size()-1).right)
                        board.push_back(playerOBJ[playerID].gotHand.at(move));

                    else {
                        int tmp = playerOBJ[playerID].gotHand.at(move).left;
                        playerOBJ[playerID].gotHand.at(move).left = playerOBJ[playerID].gotHand.at(move).right;
                        playerOBJ[playerID].gotHand.at(move).right = tmp;
                        board.push_back(playerOBJ[playerID].gotHand.at(move));
                    }

                    playerOBJ[playerID].gotHand.erase(playerOBJ[playerID].gotHand.begin()+move);

                }
                else {
                    if (playerOBJ[playerID].gotHand.at(move).right == board.at(0).left)
                        board.push_front(playerOBJ[playerID].gotHand.at(move));

                    else {
                        int tmp = playerOBJ[playerID].gotHand.at(move).left;
                        playerOBJ[playerID].gotHand.at(move).left = playerOBJ[playerID].gotHand.at(move).right;
                        playerOBJ[playerID].gotHand.at(move).right = tmp;
                        board.push_front(playerOBJ[playerID].gotHand.at(move));
                    }
                    playerOBJ[playerID].gotHand.erase(playerOBJ[playerID].gotHand.begin()+move);
                }
            }
        }
        else
            gameOver=true;
    }


}

void Board::declareWinner()
{
    game->scene->clear();

    QFont font;
    font.setPixelSize(50);
    QFont small;
    small.setPixelSize(20);
    if (playerOBJ[0].gotHand.size() == playerOBJ[1].gotHand.size())
    {
        game->scene->addText("Tie game!", font);
        cout << "Tie game!" << endl;
        cout << "Player 1 had " << playerOBJ[1].gotHand.size() << " pieces left." <<endl;
        cout << "Player 1's remaining hand: " << endl;
        for (int i=0; i < playerOBJ[1].gotHand.size(); i++){

            cout << "[" << playerOBJ[1].gotHand.at(i).left << " | " << playerOBJ[1].gotHand.at(i).right << "]";
        }
        cout << endl;
        cout << "Player 0 had " << playerOBJ[0].gotHand.size() << " pieces left." <<endl;
        cout << "Player 0's remaining hand: " << endl;
        for (int i=0; i < playerOBJ[0].gotHand.size(); i++){

            cout << "[" << playerOBJ[0].gotHand.at(i).left << " | " << playerOBJ[0].gotHand.at(i).right << "]";
        }
        cout << endl;


    }

    else if (playerOBJ[0].gotHand.size() < playerOBJ[1].gotHand.size())
    {
        game->scene->addText("You win!", font);
        cout << "Player 0 wins!" << endl;
        //game->scene->addText("Player 1 had " + QString::number(playerOBJ[1].gotHand.size()) + " pieces left." , small);
        cout << "Player 1's remaining hand: " << endl;
        for (int i=0; i < playerOBJ[1].gotHand.size(); i++){
            cout << "[" << playerOBJ[1].gotHand.at(i).left << " | " << playerOBJ[1].gotHand.at(i).right << "]";
        }
        cout << endl;
    }
    else
    {
        game->scene->addText("You lose!", font);
        cout << "Player 1 wins!" << endl;
        //game->scene->addText("Player 1 had " + QString::number(playerOBJ[1].gotHand.size()) + " pieces left." , small);
        cout << "Player 0's remaining hand: " << endl;
        for (int i=0; i < playerOBJ[0].gotHand.size(); i++){
            cout << "[" << playerOBJ[0].gotHand.at(i).left << " | " << playerOBJ[0].gotHand.at(i).right << "]";
        }
        cout << endl;
    }
    gameOver = true;
    printBoard();
    showPlayerHand(0);
    game->displayMainMenu();
}

void Board::printBoard()
{
    for (int i=0; i < board.size(); i++){

        placeDominos(10,525,board.size(), 15,board);

    }
}

int Board::moveAvailable(int playerID)
{
    int n=0;
    for (int i=0; i<playerOBJ[playerID].gotHand.size(); i++){
        if(playerOBJ[playerID].gotHand.at(i).left == board.at(0).left || playerOBJ[playerID].gotHand.at(i).right == board.at(0).left
                || playerOBJ[playerID].gotHand.at(i).left == board.at(board.size()-1).right || playerOBJ[playerID].gotHand.at(i).right == board.at(board.size()-1).right)
        {
            n=1;
        }
    }
    return n;
}

void Board::API(CPlayer *receive_playersOBJ, CDomino *receive_dominoPointerOBJ, int *turn)
{
    Game n;
    playerOBJ=receive_playersOBJ;
    player_pDominoOBJ=receive_dominoPointerOBJ;
    selecting_pieces();
    showPlayerHand();
    showPlayerHand(*turn);
    initialMove(*turn);
    showPlayerHand(*turn);
    nextTurn(turn);
    showPlayerHand(*turn);
    printBoard();

    while (playerOBJ[0].gotHand.size() > 0 && playerOBJ[1].gotHand.size() > 0){
        move(*turn);
        if(gameOver)
            break;
        else
        {
            clearBoard();
            nextTurn(turn);
            showPlayerHand(*turn);
            if (*turn ==1)
                showPlayerHand(0);
            else
                showPlayerHand(1);
            printBoard();


        }
    }

    declareWinner();
}

