/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include "../include/OnlinePlayer.h"
#include "../include/GameLogic1.h"
#include<iostream>
#include<stdio.h>
#include "../src/Client/Client.h"
OnlinePlayer::OnlinePlayer(char sign):
        Player(sign),sign(sign){
}

Point* OnlinePlayer::yourPlay(vector<Point> vec) {
    int userX, userY;
    cout << getSign() << ": It's your move" << endl;
    cout << "Your possible moves: " << flush;
    for (unsigned i = 0; i < vec.size(); ++i) {
        vec[i].printPoint();
        if (i != vec.size() - 1) {
            cout << "," << flush;
        }
    }
    cout << "" << endl;
    cout << "Please enter your move row ,col:(enter row,col separately)" << endl;
    cin >> userX;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "not an integer input" << endl;
        return NULL;
    }
    cin >> userY;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "not an integer input" << endl;
        return NULL;
    }
    return new Point(userX, userY);
}

bool OnlinePlayer::checkNextTurn(GameLogic* logic) {
    if (logic->optionalTurns((getSign())).empty()) {
        cout << "No possible moves. play passes back to other player. press any key to countinue" << endl;
        cin.get();
        return false;
    }
    return true;
}







