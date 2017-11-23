#include "GameLogic.h"
#include<iostream>
GameLogic::GameLogic(Board &board):
rowCount(board.getSizeX()),colCount(board.getSizeY()),
gameBoard(board.getBoard()),board(board) {

}

char  GameLogic::oppositeSign(char sign) {
    if (sign == 'X') {
        return 'O';
    }
    if (sign == 'O') {
        return 'X';
    }
}
bool GameLogic::checkSign(int x,int y,char sign) {
    if ((x<rowCount)&(x>=0)&(y<rowCount)&(y>=0)){
        if (gameBoard[x][y] == sign) {
            return true;
        }
    }
    return false;

}
bool  GameLogic::isFull(int x, int y) {
    if ((gameBoard[x][y]=='X')|(gameBoard[x][y]=='O')){
        return true;
    }
    return false;
}
Point GameLogic::getPoint(int x,int y) {
    return Point(x+1,y+1);
}
bool GameLogic::checkValidPoint(Point* userPoint,char sign) {
    if ((userPoint->getRowNum()>rowCount)|(userPoint->getRowNum()<0)
        |(userPoint->getColNum()>colCount)|(userPoint->getColNum()<0)) {
        cout << "not allowed move,please try again" << endl;

        return false;
    }
    if(CanPutInPiece(userPoint->getRowNum()-1,userPoint->getColNum()-1,sign)) {
        return true;
    }
    cout << "not allowed move,please try again" << endl;
    return false;
}
