/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#include <gtest/gtest.h>
#include "test_Board.h"
//check board sizes
TEST_F(test_Board, checkLimits) {
    EXPECT_EQ(board.getSizeX(), 8);
    EXPECT_EQ(board.getSizeY(), 8);
}
//check board func operating on gameboard.
TEST_F(test_Board, checksanity) {
    EXPECT_EQ(board.getStringVal(3, 3), "O ");
    EXPECT_EQ(board.getStringVal(3, 4), "X ");
    board.setSign(3, 3, 'O');
    EXPECT_EQ(board.getStringVal(3, 3), "O ");
    board.flip(3, 3);
    EXPECT_EQ(board.getStringVal(3, 3), "X ");
}