/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "../include/Board.h"
#include "../include/Game.h"
#include "../include/ConsolePlayer.h"
#include "../include/AIPlayer.h"
#include "../include/OnlinePlayer.h"

#define NUMROW 3
#define NUMCOL 3
int opponentChoice();
using namespace std;
int main() {
    Board board(NUMROW,NUMCOL);
    GameLogic1* logic = new GameLogic1(board);
    do {
        int userChoice = opponentChoice();
        if (userChoice == 1) {
            ConsolePlayer pl1=ConsolePlayer('X');
            ConsolePlayer pl2('O');
            Game game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 2) {
            ConsolePlayer pl1=ConsolePlayer('X');
            AIPlayer pl2('O', board, logic);
            Game game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 3) {
            OnlinePlayer pl1=OnlinePlayer('X');
            OnlinePlayer pl2('O');
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
    cout << "Welcome to Reversi!" << endl;
    cout << "Choose an opponent type:" << endl;
    cout << "1. a human local Player" << endl;
    cout << "2. an AI Player" << endl;
    cout << "3. remote Player" << endl;
    cin >> userChoice;
    if (userChoice == 1) {
        return 1;
    } if (userChoice == 2) {
        return 2;
    } if (userChoice == 3) {
        return 3;
    }
    return -1;
}