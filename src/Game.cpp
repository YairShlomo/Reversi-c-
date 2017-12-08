/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "../include/Game.h"

Game::Game(Player &pl1,Player &pl2,Board &boards ,GameLogic* logic)
        : pl1(pl1),pl2(pl2),board(boards),logic(logic){
    blackTurn=true;
    countMoveTurn=0;
}

void Game::play() {
    while ((score(pl1.getSign()) + score(pl2.getSign()) < board.getSizeY() * board.getSizeX())&(countMoveTurn<2)) {
        if (blackTurn) {
            countMoveTurn+=play1Turn(pl1);
        } else {
            countMoveTurn+=play1Turn(pl2);
        }
    }
    printWinner();
}
int Game::play1Turn(Player &pl) {
    if   (!pl.checkNextTurn(logic)) {
        oppositeTurn();
        return 1;
    }
    countMoveTurn=0;
    board.printBoard();
    vector<Point> optionalMoves=logic->optionalTurns(pl.getSign());
    Point* userPlay=pl.yourPlay(optionalMoves);
    if(userPlay==NULL) {
        delete(userPlay);

        return 0;
    }
    if(!logic->checkValidPoint(userPlay,pl.getSign())) {
        delete(userPlay);

        return 0;
    }
    board.setSign(userPlay->getRowNum()-1,userPlay->getColNum()-1,pl.getSign());
    logic->checkFlipPieces(userPlay->getRowNum()-1,userPlay->getColNum()-1,pl.oppositeSign(pl.getSign()),true);
    oppositeTurn();
    delete(userPlay);
    return 0;
}

void Game::oppositeTurn() {
    if (blackTurn) {
        blackTurn = false;
        return;
    }
    blackTurn = true;
}

int Game::score(char sign) {
    int counter = 0;
    for (int i = 0; i < board.getSizeX(); ++i) {
        for (int j = 0; j < board.getSizeY(); ++j) {
            if (board.getBoard()[i][j] == sign) {
                counter++;
            }
        }
    }
    return counter;
}

void Game::printWinner() {
    if (score(pl1.getSign())>score(pl2.getSign())) {
        cout<< "Player '"<<pl1.getSign()<<"' wins!" <<endl;
        return;
    }
    if (score(pl2.getSign())>score(pl1.getSign())) {
        cout << "Player '"<<pl2.getSign() << "' wins!" << endl;
        return;
    }
    cout << "Great Game ,it's a tie!" << endl;

}





