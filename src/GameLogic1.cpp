
#include "../include/GameLogic1.h"

GameLogic1::GameLogic1(Board &board):
        GameLogic(board),
rowCount(board.getSizeX()),colCount(board.getSizeY()),
gameBoard(board.getBoard()),board(board) {
}


vector<Point>  GameLogic1::optionalTurns(char sign) {
    vector<Point> vec;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            if (CanPutInPiece(i, j, sign)) {
                vec.push_back(getPoint(i,j));
            }
        }
    }
    return vec;
}
    bool GameLogic1::CanPutInPiece(int x, int y,char sign) {
        if (isFull(x,y)){
            return false;
        }
        if (checkFlipPieces( x, y, oppositeSign(sign),false)) {
            return true;
        }
        return false;
    }
bool GameLogic1::flipCheck(int x,int ix, int y,int iy, char sign,bool boolean) {
    if (checkSign(x + ix, y + iy, sign)) {
        if(isFlipCheck(x,ix,y,iy,sign,boolean)) {
            return true;
        }
    }

    return false;
}
bool GameLogic1::isFlipCheck(int x,int ix, int y,int iy, char sign,bool boolean) {
    int currX=x + ix,currY=y + iy;
    if (checkSign(currX, currY, sign)) {
        if (!isFlipCheck(currX, ix , currY, iy , sign, boolean)) {
            return false;
        }
        if (boolean) {
            board.flip(x + ix, y + iy);
        }
        return true;
    }
    if (checkSign(x + ix, y + iy, oppositeSign(sign))) {
        return true;
    }
    return false;
}
    bool GameLogic1::checkFlipPieces(int x, int y,char sign,bool boolean) {
        if (flipCheck(x,-1,y,-1,sign,boolean)| (flipCheck(x,-1,y,0,sign,boolean))|
                (flipCheck(x,-1,y,+1,sign,boolean))| (flipCheck(x,0,y,-1,sign,boolean))|
                (flipCheck(x,0,y,+1,sign,boolean))| (flipCheck(x,+1,y,-1,sign,boolean))|
                (flipCheck(x,+1,y,0,sign,boolean))| (flipCheck(x,+1,y,+1,sign,boolean))){
            return true;
        }
    }


