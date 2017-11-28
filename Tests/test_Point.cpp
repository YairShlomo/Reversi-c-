/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "test_Point.h"
TEST_F(test_Point, xYPoint) {
    EXPECT_EQ(p1.getRowNum(),1);
    EXPECT_EQ(p1.getColNum(),2);
    EXPECT_NE(p2.getColNum(),10);
}