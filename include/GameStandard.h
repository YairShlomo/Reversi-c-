/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#ifndef GAMESTANDARD_H
#define GAMESTANDARD_H
using namespace std;
#include<stdio.h>
#include<string>
#include<iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic1.h"
#include "../include/Game.h"


/**
* GameStandard is managing steps of regular game
*/
class GameStandard :public Game {
private:
    Board &board;
    Player &pl1;
    Player &pl2;
    GameLogic* logic;
    //BlackTurn('X')-true. WhiteTurn('O')-false.
    bool blackTurn;
    //counts num of times turns passed in a row.
    int countMoveTurn;
public:
    GameStandard(Player &pl1,Player &pl2,Board &boards,GameLogic* logic);

    void play();
/** play in charge of the loop game and managing turns.
   */
    int play1Turn(Player &pl);

};




#endif /* GAMESTANDARD_H_ */


