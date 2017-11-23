/*
Name:Yair Shlomo
ID: 308536150
Mission 2
*/
#include "Board.h"

Board::Board(int rowCount,int colCount):rowCount(rowCount),colCount(colCount) {
    board = new char *[rowCount];
    for (int i = 0; i < colCount; ++i) {
        board[i] = new char[colCount];
    }
    int mdlle = (rowCount / 2) - 1;
    board[mdlle][mdlle] = 'O';
    board[mdlle][mdlle + 1] = 'X';
    board[mdlle + 1][mdlle] = 'X';
    board[mdlle + 1][mdlle + 1] = 'O';
}

Board::~Board() {
    for (int i = 0; i < colCount; ++i) {
        delete board[i];
    }
    delete[] board;
}

void Board::printBoard() {
    cout << " |   " << flush;
    for (int i = 1; i <= colCount; i++) {
        cout << i << "   |   " << flush;
    }
    cout << "" << endl;
    for (int i = 1; i <= colCount; i++) {
        cout << " - - - -" << flush;
    }
    cout << "" << endl;
    for (int i = 1; i <= rowCount; i++) {
        printRow(i);
    }
}

void Board::printRow(int rowNum) {
    cout << rowNum << "|  " << flush;
    for (int x = 0; x < colCount; x++) {
        cout << getStringVal(rowNum - 1, x) << "   |  " << flush;
    }
    cout << "" << endl;
    for (int x = 0; x < colCount; x++) {

        cout << " - - - -" << flush;
    }
    cout << "" << endl;
}

string Board::getStringVal(int rowNum,int colNum) {
        if (board[rowNum][colNum] == 'X') {
            return "X ";
        }
        if (board[rowNum][colNum] == 'O') {
            return "O ";
        }
        return "  ";
    }

void Board::flip (int x,int y) {
    if (board[x][y] == 'X') {
        board[x][y] = 'O';
        return;
    }
    if (board[x][y] == 'O') {
        board[x][y] = 'X';
    }
}

void Board::setSign(int x, int y,char sign) {
    board[x][y] = sign;

}

int Board::getSizeX() {
    return rowCount;
}

int Board::getSizeY() {
    return colCount;
}

char** Board::getBoard() {
    return board;
}


