/*
Name:Yair Shlomo
ID: 308536150
Mission 1
*/

#ifndef Point_H_
#define Point_H_
using namespace std;
#include<stdio.h>
#include<string>
/**
* Point represent a cell gameboard.
*/
class Point {
public:
    Point(int rowNum,int colNum);
    /**
     * printPoint function-prints the Point
    */
    void printPoint();
    /**
* getRowNum returns number of rows in gameboard
* @return int -  number of rows in gameboard
*/
    int getRowNum();
    /**
* getRowNum returns number of columns in gameboard
* @return int - number of columns in gameboard
*/
    int getColNum();
private:
    // number of rows in gameboard.
    int rowNum;
    //number of columns in gameboard
    int colNum;

};

#endif /* Point_H_ */