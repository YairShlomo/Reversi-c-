/*
Name:Yair Shlomo
ID: 308536150
Mission 2
*/

#ifndef Player_H_
#define Player_H_
using namespace std;
#include<stdio.h>
#include<string>
#include <vector>
#include "Point.h"
#include "GameLogic1.h"

/**
 * Player represent any player. Father-class.
*/
class Player {
private:
    //representing sign of player.
    char sign;
public:
    /**
* Constructor initialize member sign.
*/
    Player(char sign);
    /**
* getSign returns player sign.
* @return char - PLayer's sign
*/
    char getSign();
    /**
* yourPlay is a abstract. returns a point play fom user.
*/
    virtual Point* yourPlay(vector<Point> vec)=0;
    /**
* * checkNextTurn is a abstract. checks if there is any option of play to Player.
*/
    virtual bool checkNextTurn(GameLogic* logic)=0;
    /**
* oppositeSign returns the opposite sign in given sign.
* @param char - sign to turn from
* @return char - the turned sign.
*/
    char  oppositeSign(char sign);
};

#endif /* Player_H_ */
