/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include <cstring>
#include "../include/GameOnline.h"


GameOnline::GameOnline(Client &pl1,Player &pl2,Board &boards ,GameLogic* logic):
        Game(pl1,pl2,boards,logic),pl1(pl1),pl2(pl2),board(boards),logic(logic) {
}

void GameOnline::play() {
    if (pl1.getSign()=='X') {
        blackTurn = true;
    } else {
        blackTurn = false;
    }
    cout << "current board:" << endl;
    board.printBoard();
        while ((score(pl1.getSign()) + score(pl2.getSign()) < board.getSizeY() * board.getSizeX())) {
            if (blackTurn) {
                countMoveTurn += play1Turn(pl1);
            } else {
                cout << "waiting for other player's move..." << endl;
                char *message = pl1.getMessage();
                if (strcmp(message, "NOMOVE") == 0) {
                    if(countMoveTurn==1) {
                        break;
                    }
                    oppositeTurn();

                } else if (strcmp(message, "END") == 0) {
                    printWinner();
                    return;
                } else {
                    char x = message[0];
                    char y = message[1];
                    int xint = x - '0';
                    int yint = y - '0';
                    Point *nextMove = new Point(xint, yint);
                    board.setSign(nextMove->getRowNum() - 1, nextMove->getColNum() - 1, pl2.getSign());
                    logic->checkFlipPieces(nextMove->getRowNum() - 1, nextMove->getColNum() - 1,
                                           pl2.oppositeSign(pl2.getSign()), true);
                    oppositeTurn();
                    delete (nextMove);
                }
            }
        }
    printWinner();
    pl1.endGame();
}
int GameOnline::play1Turn(Player &pl) {
    if   (!pl.checkNextTurn(logic)) {
        oppositeTurn();
        return 1;
    }
    countMoveTurn=0;
    vector<Point> optionalMoves=logic->optionalTurns(pl.getSign());
    Point* userPlay=pl.yourPlay(optionalMoves);
    if(userPlay==NULL){
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
    cout << "current board:" << endl;
    board.printBoard();
    return 0;
}









