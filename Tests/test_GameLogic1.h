/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#ifndef UNTITLED_TEST_GAMELOGIC1_H
#define UNTITLED_TEST_GAMELOGIC1_H
#include <gtest/gtest.h>
#include "../include/GameLogic1.h"

#include "../include/Board.h"
#include <iostream>
using namespace std;
class test_GameLogic1: public testing::Test {
public:test_GameLogic1(): board(4,4), logic(board){
    }

protected:
    Board board;
    GameLogic1 logic;
};


#endif //UNTITLED_TEST_GAMELOGIC1_H
