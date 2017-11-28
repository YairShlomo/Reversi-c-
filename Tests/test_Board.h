

#ifndef UNTITLED_TEST_BOARD_H
#define UNTITLED_TEST_BOARD_H
#include <gtest/gtest.h>
#include "../include/Game.h"
#include "../include/AIPlayer.h"
#include <iostream>
using namespace std;
class test_Board: public testing::Test {
public:
    test_Board() :board(8,8) {}
protected:
    Board board;
};
#endif



