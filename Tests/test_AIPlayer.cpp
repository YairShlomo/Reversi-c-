/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#include <gtest/gtest.h>
#include "../include/Game.h"
#include "../include/AIPlayer.h"
#include "test_AIPlayer.h"

//check correct choices of AIPlayer
TEST_F(test_AIPlayer, checkPlay) {
    board.setSign(1,2,'X');
    board.flip(1,1);
    vector<Point> optionalMoves=logic->optionalTurns(pl1.getSign());
    Point* s=pl1.yourPlay(optionalMoves);
    EXPECT_EQ(s->getRowNum(),3);
    EXPECT_EQ(s->getColNum(),3);
    board.setSign(2,2,'O');
    board.flip(1,1);
    board.setSign(2,1,'X');
    board.flip(1,1);
    Point* s1=pl1.yourPlay(optionalMoves);
    EXPECT_EQ(s1->getRowNum(),1);
    EXPECT_EQ(s1->getColNum(),3);
    delete(logic);
}
