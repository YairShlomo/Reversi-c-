/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#include <gtest/gtest.h>
#include "../include/GameLogic1.h"
#include "../include/Board.h"
#include "test_GameLogic1.h"
/*
 * cechk if i get the right vector of points
 */

TEST_F(test_GameLogic1, CanPlayOnSpot) {
    EXPECT_EQ(logic.CanPutInPiece(2,3,'X'),1);
    EXPECT_NE(logic.CanPutInPiece(2,3,'X'),0);
    EXPECT_NE(logic.CanPutInPiece(2,0,'O'),0);
    EXPECT_NE(logic.CanPutInPiece(2,3,'O'),1);
}
/*
 * cechk if you get the right vector of points
 */
TEST_F(test_GameLogic1, CheckOptionalPlays) {
    vector<Point> vec= logic.optionalTurns('X');
    EXPECT_EQ(vec.size(),4);
    EXPECT_EQ(vec[0].getRowNum(),1);
    EXPECT_EQ(vec[0].getColNum(),2);
}