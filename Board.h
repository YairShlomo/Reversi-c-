/*
Name:Yair Shlomo
ID: 308536150
Mission 1
*/

#ifndef BOARD_H_
#define BOARD_H_
using namespace std;
#include<stdio.h>
#include<string>
#include<iostream>
/**
 * Board represent gameboard.
*/
class Board {
public:
    Board(int rowCount,int colCount);
    /**
    * Destructor of Board.
    */
    ~Board();
    /**
    * printBoard function-prints the board.
    */
    void printBoard();
    /**
     * printRow function-print row format in given rowNumb.
     * @param rowNum - numb of row to print.
    */
    void printRow(int rowNum);
    /**
     * getStringVal function-select print sign depeneds of value in the cell.
     * @param rowNum - number of row.
     * @param colNum- number col.
     * @return string - string for print
    */
    string getStringVal(int rowNum,int colNum);
    /**
    * flip is in charge to flip a cell in given it.
    * @param rowNum - number of row.
    * @param colNum- number col.
    */
    void flip (int rowNum,int colNum);
    /**
 * setSign changing the sign of cell in given it.
 * @param rowNum - number of row.
 * @param colNum- number col.
*/
    void setSign(int x, int y,char sign);
    /**
 * getSizeX retuns num of row in board.
 * @return int - number of rows in board
*/
    int getSizeX();
    /**
 * getSizeX retuns num of row in board.
 * @return int - number of columns in board
*/
    int getSizeY();
    /**
 * getBoard returns the gameboard.
 * @param rowNum - number of row.
 * @return char** - the gameboard
*/
    char** getBoard();

private:
    //2 dimension array ,each cell represent cell in board.
    char** board;
    //number of rows of Board.
    int rowCount;
    //number of columns of Board.
    int colCount;

};

#endif /* BOARD_H_ */