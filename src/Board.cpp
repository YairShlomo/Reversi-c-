/*
Name:Yair Shlomo
ID: 308536150
Mission 2
*/
#include "../include/Board.h"



/*
Board& Board::operator=(Board& board1) {
    delete [] gameBoard;
    if (this != &board1) {  // make sure not same object
        rowCount = board1.rowCount;
        colCount = board1.colCount;
        gameBoard = new char *[rowCount];
        for (int i = 0; i < colCount; ++i) {
            gameBoard[i] = new char[colCount];
        }
        for (int i = 0; i < colCount; ++i) {
        for (int j = 0; j < colCount; ++j) {

            char sign = board1.getBoard()[i][j];
            gameBoard[i][j] = sign;
        }}
    }
    return *this;    // Return ref for multiple assignment

}
 */
Board::Board (Board& board1):rowCount(board1.rowCount),colCount(board1.colCount) {
    //delete [] gameBoard;
   // if (this != &board1) {  // make sure not same object
        gameBoard = new char *[rowCount];
        for (int i = 0; i < colCount; ++i) {
            gameBoard[i] = new char[colCount];
        }
        for (int i = 0; i < colCount; ++i) {
            for (int j = 0; j < colCount; ++j) {

                char sign = board1.getBoard()[i][j];
                gameBoard[i][j] = sign;
            }
        }

}

Board::Board(int rowCount,int colCount):rowCount(rowCount),colCount(colCount) {
    gameBoard = new char *[rowCount];
    for (int i = 0; i < colCount; ++i) {
        gameBoard[i] = new char[colCount];
    }
    int mdlle = (rowCount / 2) - 1;
    gameBoard[mdlle][mdlle] = 'O';
    gameBoard[mdlle][mdlle + 1] = 'X';
    gameBoard[mdlle + 1][mdlle] = 'X';
    gameBoard[mdlle + 1][mdlle + 1] = 'O';
}

Board::~Board() {
    for (int i = 0; i < colCount; ++i) {
        delete gameBoard[i];
    }
    delete[] gameBoard;
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
        if (gameBoard[rowNum][colNum] == 'X') {
            return "X ";
        }
        if (gameBoard[rowNum][colNum] == 'O') {
            return "O ";
        }
        return "  ";
    }

void Board::flip (int x,int y) {
    if (gameBoard[x][y] == 'X') {
        gameBoard[x][y] = 'O';
        return;
    }
    if (gameBoard[x][y] == 'O') {
        gameBoard[x][y] = 'X';
    }
}

void Board::setSign(int x, int y,char sign) {
    gameBoard[x][y] = sign;

}

int Board::getSizeX() {
    return rowCount;
}

int Board::getSizeY() {
    return colCount;
}

char** Board::getBoard() {
    return gameBoard;
}


