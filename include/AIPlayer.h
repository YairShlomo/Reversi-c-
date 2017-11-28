/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/


#ifndef AIPlayer_H_
#define AIPlayer_H_
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "Player.h"
#include "Point.h"
#include "GameLogic.h"
/**
 * ConsolePlayer represent player from console. inherited from Player.
*/
class AIPlayer:public Player {
private:
    //representing sign of player.
    char sign;
    Board &board;
    GameLogic* logic;
public:
    /**
* Constructor initialize father-class and and member sign.
*/
    AIPlayer(char sign, Board& board,GameLogic* logic);

    /**
 * yourPlay print list of available points ,get a point from user and returns it.
 * @param vector<Point> - vector of all available points.
 * @return Point* - the point user choose to play
*/
    Point*yourPlay(vector<Point> vec);

    /**
 * checkNextTurn checks if there is any available play to Player and pass turn if not.
 * @param logic -the logic of game object.
 * @return bool - if there is available play-true. if not-false.
*/
    bool checkNextTurn(GameLogic *logic);
    /**
 * score returns the diff between this AIPlayer and the other player
 * @param board - refrence to a board the checks is been made on.
 * @return int - the diff between this AIPlayer and the other player
*/
    int score(Board& b);

};

#endif /* ConsolePlayer_H_ */
