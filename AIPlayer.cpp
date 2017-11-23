
#include "AIPlayer.h"
#include "GameLogic1.h"
#include<iostream>
#include<stdio.h>
AIPlayer::AIPlayer(char sign,Board& board,GameLogic* logic):
        board(board),logic(logic),Player(sign),sign(sign) {
}

Point* AIPlayer::yourPlay(vector<Point> vec) {

    for (unsigned i = 0; i < vec.size(); ++i) {
        Board 
    }
    cout << "" << endl;
    cout << "Please enter your move row ,col:(enter row,col separately)" << endl;
    cin >> userX;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "not an integer input" << endl;
        return NULL;
    }
    cin >> userY;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "not an integer input" << endl;
        return NULL;
    }
    return new Point(userX, userY);
}

bool AIPlayer::checkNextTurn(GameLogic* logic) {
    if (logic->optionalTurns((getSign())).empty()) {
        cout << "No possible moves. play passes back to other player. press any key to countinue" << endl;
        cin.get();
        return false;
    }
    return true;
}

int AIPlayer::score(Board b) {
    int counter = 0;
    for (int i = 0; i < board.getSizeX(); ++i) {
        for (int j = 0; j < board.getSizeY(); ++j) {
            //if (board.getBoard()[i][j] == (char)pl.getSign()) {
                counter++;

        }
    }
    return 1;
}





