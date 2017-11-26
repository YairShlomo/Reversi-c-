/*
Name:Yair Shlomo
ID: 308536150
Mission 1
*/

#ifndef GameLogic_H_
#define GameLogic_H_
using namespace std;
#include<stdio.h>
#include<string>
#include "Point.h"
#include "Board.h"
#include<vector>


/**
 * GameLogic contains the rules of game.Father-class.
*/
class GameLogic {
public:
    GameLogic(Board &board);
    /**
* CanPutInPiece is a abstract. returns if piece is available to play or not.
*/
    virtual bool CanPutInPiece(int x, int y,char sign)=0;
    /**
* optionalTurns is a abstract. returns vector of optional mooving plays.
*/
    virtual vector<Point> optionalTurns(char sign)=0;
    /**
* flipCheck is a abstract. returns if cell suppose to flip.
*/
    virtual bool flipCheck(int x,int ix, int y,int iy,char sign,bool boolean)=0;
    /**
* isFlipCheck is a abstract and recursive. returns if all cells in order suppose to flip
*/
    virtual bool isFlipCheck(int x,int ix, int y,int iy, char sign,bool boolean)=0;
    /**
* checkFlipPieces is a abstract. checks for all flipping options directions of cell.
*/
    virtual bool checkFlipPieces(int x, int y,char sign,bool boolean)=0;
    /**
* getPoint returns the place of cell.
* @param rowNum - number of row.
* @param colNum- number col.
* @return Point - the place of cell.
*/
    Point getPoint(int rowNum,int colNum);
    /**
* checkSign checks if cell contains the given sign.
* @param rowNum - number of row.
* @param colNum- number col.
* @return bool - cell contains the given sign or not.
*/
    bool checkSign(int rowNum,int colNum,char sign);
    /**
* isFull checks if cell is full.
* @param rowNum - number of row.
* @param colNum- number col.
* @return bool - cell is full or not.
*/
    bool isFull(int rowNum, int colNum);
    /**
* checkValidPoint checks if user point is valid.
* @param Point* - point of user.
* @param char - a sign.
* @return bool -  user point is valid or not.
*/
    bool checkValidPoint(Point* userPoint,char sign);
    /**
* oppositeSign returns the opposite sign.
* @param char - a sign to turn from.
* @return char - the turned sign.
*/
    char  oppositeSign(char sign);

private:
    Board &board;
    char** gameBoard;
    int rowCount;
    int colCount;

};

#endif /* GameLogic_H_ */