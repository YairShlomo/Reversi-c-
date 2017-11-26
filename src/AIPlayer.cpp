
#include "../include/AIPlayer.h"
#include "../include/GameLogic1.h"
#include<iostream>
#include<stdio.h>
AIPlayer::AIPlayer(char sign,Board& board,GameLogic* logic):
        board(board),logic(logic),Player(sign),sign(sign) {
}

Point* AIPlayer::yourPlay(vector<Point> vec) {
    int bestOption = board.getSizeX() * board.getSizeY();
    int bestPointPos = 0;
    board.printBoard();
    for (int i = 0; i < vec.size(); ++i) {
        //Board b (board.getSizeX(),board.getSizeY())
        //b.setSign(board.getBoard()[])
        Board b(board);
        GameLogic1* tempLogic = new GameLogic1(b);
        //char** gameBoard=b.getBoard();
        Point current = vec[i];

        b.setSign(current.getRowNum() - 1, current.getColNum() - 1, getSign());
        tempLogic->checkFlipPieces(current.getRowNum() - 1, current.getColNum() - 1, oppositeSign(getSign()), true);
        vector<Point> opponentOptions = tempLogic->optionalTurns(tempLogic->oppositeSign(getSign()));
        int tempBestOption = board.getSizeX() * board.getSizeY();
        //b.printBoard();

        for (int j = 0; j < opponentOptions.size(); ++j) {
            int scoreGame=score(b);
            if ( scoreGame< bestOption) {
                tempBestOption = scoreGame;
                //b.printBoard();
            }
        }
        if (tempBestOption < bestOption) {
            bestPointPos = i;
        }
        delete(tempLogic);
    }
    Point* myPoint=new Point(vec[bestPointPos].getRowNum(), vec[bestPointPos].getColNum());
    cout << "currMove: " << flush;
    myPoint->printPoint();
    cout << "" << endl;

    return myPoint;
}

bool AIPlayer::checkNextTurn(GameLogic* logic) {
    if (logic->optionalTurns((getSign())).empty()) {
        cout << "No possible moves. play passes back to other player. press any key to countinue" << endl;
        cin.get();
        return false;
    }
    return true;
}

int AIPlayer::score(Board& b) {
    int myScore = 0;
    int opponentScore = 0;
    for (int i = 0; i < b.getSizeX(); ++i) {
        for (int j = 0; j < b.getSizeY(); ++j) {
            if (b.getBoard()[i][j] == getSign()) {
                myScore++;
            }

                else if (b.getBoard()[i][j] == logic->oppositeSign(getSign())) {
                opponentScore++;
            }
        }
    }
    return opponentScore-myScore;
}





