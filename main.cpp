/*
Name:Yair Shlomo
ID: 308536150
Mission 3
*/
#include "Board.h"
#include "Game.h"
#include "ConsolePlayer.h"
#include "AIPlayer.h"
using namespace std;
int main() {
    Board board(3,3);
    GameLogic1* logic = new GameLogic1(board);
    ConsolePlayer pl1('X');
    AIPlayer pl2('O',board,logic);
    Game game(pl1,pl2,board ,logic);
    game.play();
    delete (logic);
}

