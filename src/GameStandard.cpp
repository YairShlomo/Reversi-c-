/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "../include/GameStandard.h"
#include "../include/Game.h"

GameStandard::GameStandard(Player &pl1,Player &pl2,Board &boards ,GameLogic* logic):
        Game(pl1,pl2,boards,logic),pl1(pl1),pl2(pl2),board(boards),logic(logic){
}


void GameStandard::play() {
    while ((score(pl1) + score(pl2) < board.getSizeY() * board.getSizeX())&(countMoveTurn<2)) {
        if (blackTurn) {
            countMoveTurn+=play1Turn(pl1);
        } else {
            countMoveTurn+=play1Turn(pl2);
        }
    }
    printWinner();
}
int GameStandard::play1Turn(Player &pl) {
    if   (!pl.checkNextTurn(logic)) {
        oppositeTurn();
        return 1;
    }
    countMoveTurn=0;
    board.printBoard();
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
    return 0;
}









