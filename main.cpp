/*
Name:Yair Shlomo
ID: 308536150
Mission 1
*/
#include "Board.h"
#include "Game.h"
#include "ConsolePlayer.h"
#include <iostream>
using namespace std;
int main() {
    ConsolePlayer pl1('X');
    ConsolePlayer pl2('O');
    Board board(8,8);
    GameLogic1* logic =new GameLogic1(board);
    Game game(pl1,pl2,board ,logic);
    game.play();
    delete (logic);
}

