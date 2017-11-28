/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "../include/Point.h"

#include<iostream>
#include<stdio.h>

Point::Point(int rowNum,int colNum) :
        rowNum(rowNum),colNum(colNum) {
}
void Point::printPoint() {
    cout <<"("<< rowNum << "," <<colNum<<")" <<flush;

}
int Point::getRowNum() {
    return rowNum;
}
int Point::getColNum() {
    return colNum;
}
