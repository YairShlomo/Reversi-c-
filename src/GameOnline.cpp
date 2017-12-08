/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include <unistd.h>
#include <cstring>
#include "../include/GameOnline.h"
#include "../include/Game.h"
#include "../include/Client.h"

GameOnline::GameOnline(Client &pl1,Player &pl2,Board &boards ,GameLogic* logic):
        Game(pl1,pl2,boards,logic),pl1(pl1),pl2(pl2),board(boards),logic(logic) {


}

void GameOnline::play() {
    if (pl1.getSign()=='X') {
        blackTurn = true;
    } else {
        blackTurn = false;
    }
        while ((score(pl1) + score(pl2) < board.getSizeY() * board.getSizeX())&(countMoveTurn<2)) {
        if (blackTurn) {
            countMoveTurn += play1Turn(pl1);
        } else {
            char* message=pl1.getMessage();
            if (strcmp(message,"NOMOVE")==0){
                pl1.moveTurn();
            }
            if (strcmp(message,"END")==0) {
                pl1.endGame();
            }
            char x=message[0];
            char y=message[1];
            /*
            int xint=atoi(&x);
            int yint=atoi(&y);
             */
            int xint=x-'0';
            int yint=y-'0';
            cout << xint << endl;
            cout << yint << endl;

            Point* nextMove=new Point(xint,yint);
            board.setSign(nextMove->getRowNum()-1,nextMove->getColNum()-1,pl2.getSign());
            logic->checkFlipPieces(nextMove->getRowNum()-1,nextMove->getColNum()-1,pl2.oppositeSign(pl2.getSign()),true);
            oppositeTurn();
            delete(nextMove);
        }
        if (countMoveTurn==1) {
            pl1.endGame();
        }
    }
    printWinner();
    if (blackTurn) {
        pl1.endGame();
    } else {
        countMoveTurn+=play1Turn(pl2);
    }
}
int GameOnline::play1Turn(Player &pl) {
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
    //int send = read(clientSocket,&newPoint, sizeof(newPoint));

    if(!logic->checkValidPoint(userPlay,pl.getSign())) {
        delete(userPlay);

        return 0;
    }
    board.setSign(userPlay->getRowNum()-1,userPlay->getColNum()-1,pl.getSign());
    logic->checkFlipPieces(userPlay->getRowNum()-1,userPlay->getColNum()-1,pl.oppositeSign(pl.getSign()),true);
    oppositeTurn();
    /*
    char buffer[7];
    buffer[0]='0'+userPlay->getRowNum();
    buffer[1]='0'+userPlay->getColNum();
    cout << buffer[0] << endl;
    cout << buffer[1] << endl;

    pl1.sendMessage(buffer);
     */
    delete(userPlay);
    return 0;
}









