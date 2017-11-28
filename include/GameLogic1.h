/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/



#ifndef GameLogic1_H_
#define GameLogic1_H_
using namespace std;

#include<stdio.h>
#include<string>
#include "GameLogic.h"

#include "Point.h"
#include "Board.h"
#include<vector>

/**
 * GameLogic1 contains the rules of game.Father-class.
*/
class GameLogic1  :public GameLogic {
public:
    GameLogic1(Board &board);
    /**
* CanPutInPiece returns if cell is available to play or not.
* @param rowNum - number of row.
* @param colNum- number col.
* @param char- PLayer's sign.
* @return bool - if cell is available to play or not.
*/
    bool CanPutInPiece(int rowNum, int colNum,char sign);
    /**
* optionalTurns returns vector of optionals moves..
* @param char- PLayer's sign.
* @return vector<Point>  - vector contains optionals moves.
*/
    vector<Point> optionalTurns(char sign);
    /**
* flipCheck returns if cell suppose to flip..
* @param rowNum - number of row.
* @param colNum- number col.
* @param rowChange- number col.
* @param colChange- number col.
* @param sign- number col.
* @param toFlip- to flip or not.
* @return bool - returns if cell suppose to flip.
*/
    bool flipCheck(int rowNum,int rowChange, int colNum,int colChange,char sign,bool toFlip);
    /**
* recursive func. returns if all cells in order suppose to flip.
* @param rowNum - number of row.
* @param colNum- number col.
* @param rowChange- number col.
* @param colChange- number col.
* @param sign- number col.
* @param toFlip- to flip or not.
* @return bool - returns if cell suppose to flip.
*/
    bool isFlipCheck(int rowNum,int rowChange, int colNum,int colChange, char sign,bool boolean);
    /**
* isFlipCheck checks for all flipping options directions of cell.
* @param rowNum - number of row.
* @param colNum- number col.
* @param toFlip- to flip or not.
* @return bool - returns if cell suppose to flip.
*/
    bool checkFlipPieces(int rowNum, int colNum,char sign,bool boolean);
private:
Board& board;
char** gameBoard;
int rowCount;
int colCount;

};

#endif /* GameLogic1_H_ */