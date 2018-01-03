/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#ifndef CLIENT_H
#define CLIENT_H
#include "Player.h"
#include<stdio.h>
#include<string>
#include<cstdio>
#include<iostream>
class Client :public Player {
public:
    Client(char sign ,const char *serverIP, int serverPort);
    void moveTurn();
    void sendMessage(char* message);
    void connectToServer();
    /**
* yourPlay is a abstract. returns a point play fom user.
*/
    Point* yourPlay(vector<Point> vec);
    /**
* * checkNextTurn is a abstract. checks if there is any option of play to Player.
*/
    bool checkNextTurn(GameLogic* logic);
    char* getMessage();
    void endGame();
    void closeMe();
    void sendCommand(char* myCommand);
    Point* extractPoint(string command);
    int isValidCommand(string myCommand);
    vector<string> getArgs();
    void menu();
    void menuGame();

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    char buffer[7];

    //representing sign of player.
    //char sign;
};
#endif /*CLIENT_H*/
