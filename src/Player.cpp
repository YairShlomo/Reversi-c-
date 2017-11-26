/*
Name:Yair Shlomo
ID: 308536150
Mission 2
*/
#include "../include/ConsolePlayer.h"

Player::Player(char sign):sign(sign)
{};

char Player::getSign() {
    return sign;
}


char  Player::oppositeSign(char sign) {
    if (sign == 'X') {
        return 'O';
    }
    if (sign == 'O') {
        return 'X';
    }
}





