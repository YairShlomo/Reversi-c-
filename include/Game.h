/*
Name:Yair Shlomo
ID: 308536150
Mission 2
*/
#ifndef Game_H_
#define Game_H_
using namespace std;
#include<stdio.h>
#include<string>
#include<iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic1.h"

/**
* Game is managing steps of the game
*/
class Game {
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
    Game(Player &pl1,Player &pl2,Board &boards,GameLogic* logic);
    /**
* score returns number of cells Player owns.
* @param Player - a player.
* @return int - number of cells Player owns
*/
    int score(Player &pl);
    /**
* play in charge of the loop game and managing turns.
*/
    void play();
    /**
* play1Turn is sets of action in any turn in game.
* @param Player - current Player playing.
* @return int - if turns passed=1 ,otherwise 0.
*/
    int play1Turn(Player &pl);
    /**
* oppositeTurn turn the turn to other Player
*/
    void oppositeTurn();
    /**
* printWinner print the Winner when game end.
*/
    void printWinner();
};

#endif /* Game_H_ */
