/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#ifndef TEST_GAME_H_H
#define TEST_GAME_H_H
#include <gtest/gtest.h>
#include "../include/Game.h"
#include "../include/AIPlayer.h"
#include <iostream>
using namespace std;
class test_Game: public testing::Test {
public:
    test_Game() :board(3,3),logic(new GameLogic1(board)),pl1('X', board, logic),
                  pl2('O', board, logic),game(pl1, pl2, board, logic) {
            //Board board(3, 3);
            //logic = ;
            //AIPlayer pl1('X', board, logic);
            //AIPlayer pl2('O', board, logic);
            //Game game(pl1, pl2, board, logic);
    }
protected:
    Board board;
    GameLogic1* logic;
    AIPlayer pl1,pl2;
    Game game;
};
#endif
