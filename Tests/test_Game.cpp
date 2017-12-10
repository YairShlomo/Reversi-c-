

#include <gtest/gtest.h>
#include "test_Game.h"
//check Score func.
TEST_F(test_Game,checkScore) {
    EXPECT_EQ(game.score(pl1.getSign()),2);
    EXPECT_EQ(game.score(pl2.getSign()),2);
    board.setSign(0,2,'O');
    EXPECT_EQ(game.score(pl2.getSign()),3);
    board.setSign(1,2,'O');
    EXPECT_EQ(game.score(pl2.getSign()),4);
}
//check Play1Turn func.
TEST_F(test_Game,checkPlay1Turn) {
    board.setSign(0,2,'O');
    board.setSign(1,2,'O');
    board.setSign(0, 1, 'O');
    EXPECT_EQ(game.play1Turn(pl1), 1);
    board.setSign(1, 2, 'X');
    EXPECT_EQ(game.play1Turn(pl2), 0);
}

