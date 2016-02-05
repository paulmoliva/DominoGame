#include <QApplication>
#include "game.h"
#include "cdomino.h"
Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game;
    game->show();
    game->displayMainMenu();

    return a.exec();
}

