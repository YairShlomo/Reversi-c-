/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#ifndef UNTITLED_TEST_AIPLAYER_H
#define UNTITLED_TEST_AIPLAYER_H
#include <gtest/gtest.h>
#include "../include/Game.h"
#include "../include/AIPlayer.h"
#include <iostream>
using namespace std;
class test_AIPlayer: public testing::Test {
public:
    test_AIPlayer() :board(3,3),logic(new GameLogic1(board)),pl1('O', board, logic) {
    }
protected:
    Board board;
    GameLogic1* logic;
    AIPlayer pl1;
};
#endif
