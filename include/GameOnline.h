#ifndef UNTITLED_GAMEONLINE_H
#define UNTITLED_GAMEONLINE_H
/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/


using namespace std;
#include<stdio.h>
#include<string>
#include<iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic1.h"
#include "Game.h"


/**
* Game is managing steps of the game
*/
class GameOnline :public Game {
private:
    Board &board;
    Player &pl1;
    Player &pl2;
    GameLogic *logic;
    //BlackTurn('X')-true. WhiteTurn('O')-false.
    bool blackTurn;
    //counts num of times turns passed in a row.
    int countMoveTurn;
public:
    GameOnline(Player &pl1, Player &pl2, Board &boards, GameLogic *logic);

/*
* play in charge of the loop game and managing turns.
*/
    void play();

    /**
* play1Turn is sets of action in any turn in game.
* @param Player - current Player playing.
* @return int - if turns passed=1 ,otherwise 0.
*/
    int play1Turn(Player &pl);

};

#endif /* UNTITLED_GAMEONLINE_H */
