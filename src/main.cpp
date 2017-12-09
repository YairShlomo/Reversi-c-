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
#include "../include/GameStandard.h"
#include "../include/GameOnline.h"
#include "../include/Client.h"

#define NUMROW 3
#define NUMCOL 3

int opponentChoice();
int main() {
    Board board(NUMROW,NUMCOL);
    GameLogic1* logic = new GameLogic1(board);
    do {
        int userChoice = opponentChoice();
        if (userChoice == 1) {
            ConsolePlayer pl1=ConsolePlayer('X');
            ConsolePlayer pl2('O');
            GameStandard game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 2) {
            ConsolePlayer pl1=ConsolePlayer('X');
            AIPlayer pl2('O', board, logic);
            GameStandard game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 3) {
            Client pl1= Client('X',"127.0.0.1",5556);
            //cout << "Welc";
            ConsolePlayer pl2=ConsolePlayer(logic->oppositeSign(pl1.getSign()));
            GameOnline game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        }
    } while (opponentChoice()==-1);
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
