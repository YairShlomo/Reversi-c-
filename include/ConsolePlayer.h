/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/


#ifndef ConsolePlayer_H_
#define ConsolePlayer_H_
using namespace std;
#include<stdio.h>
#include<string>
#include "Player.h"
#include "Point.h"
#include "GameLogic1.h"
/**
 * ConsolePlayer represent player from console. inherited from Player.
*/
class ConsolePlayer:public Player {
private:
    //representing sign of player.
    char sign;
public:
    /**
* Constructor initialize father-class and and member sign.
*/
    ConsolePlayer(char sign);
    /**
 * yourPlay print list of available points ,get a point from user and returns it.
 * @param vector<Point> - vector of all available points.
 * @return Point* - the point user choose to play
*/
    Point* yourPlay(vector<Point> vec);
    /**
 * checkNextTurn checks if there is any available play to Player and pass turn if not.
 * @param logic -the logic of game object.
 * @return bool - if there is available play-true. if not-false.
*/
    bool checkNextTurn(GameLogic* logic);
};

#endif /* ConsolePlayer_H_ */
