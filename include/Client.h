

#ifndef CLIENT_H
#define CLIENT_H
#include "Player.h"
#include<stdio.h>
#include<string>

class Client :public Player{
public:
    Client(char sign ,const char *serverIP, int serverPort);
    void connectToServer();
    /**
* yourPlay is a abstract. returns a point play fom user.
*/
    Point* yourPlay(vector<Point> vec);
    /**
* * checkNextTurn is a abstract. checks if there is any option of play to Player.
*/
    bool checkNextTurn(GameLogic* logic);
    int message(int arg1, char op, int arg2);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    //representing sign of player.
    char sign;
};
#endif /*CLIENT_H*/
