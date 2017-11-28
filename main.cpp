/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "include/Board.h"
#include "include/Game.h"
#include "include/ConsolePlayer.h"
#include "include/AIPlayer.h"
#define NUMROW 8
#define NUMCOL 8
int opponentChoice();
using namespace std;
int main() {
    Board board(NUMROW,NUMCOL);
    GameLogic1* logic = new GameLogic1(board);
    ConsolePlayer pl1('X');
    do {
        int userChoice = opponentChoice();
        if (userChoice == 1) {
            AIPlayer pl2('O', board, logic);
            Game game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 0) {
            ConsolePlayer pl2('O');
            Game game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        }
    }while (opponentChoice()==-1);


}
/**
    * opponentChoice get from user his choice about his opponent.
    * @return int - 1=AIPlayer,0=ConsolePlayer, otherwise -1
   */
int opponentChoice() {
    int userChoice;
    cout << "enter 1 if you want play against the computer , 0 if you want to play with human player" << endl;
    cin >> userChoice;
    if (userChoice == 1) {
        return 1;
    } else if (userChoice == 0) {
        return 0;
    }
    return -1;
}