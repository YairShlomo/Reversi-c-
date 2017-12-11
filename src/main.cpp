/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/

#include <fstream>
#include <cstring>
#include "../include/Board.h"
#include "../include/Game.h"
#include "../include/ConsolePlayer.h"
#include "../include/AIPlayer.h"
#include "../include/GameStandard.h"
#include "../include/GameOnline.h"
#include "../include/Client.h"

#define NUMROW 3
#define NUMCOL 3

int opponentChoice();
string getlineInput(string line);
int main() {
    Board board(NUMROW, NUMCOL);
    GameLogic1 *logic = new GameLogic1(board);
    string line,Numb,port,ipAdress;
    int portNumb;
    ifstream myfile("../serverInfo.txt");
    int i = 0;
    if (myfile.is_open()) {
        getline(myfile, line);
        port = getlineInput(line);
        portNumb =atoi(port.c_str());
        getline(myfile, line);
        ipAdress = getlineInput(line);
    } else {
        cout << "Unable to open file";

        return 0;
    }
    do {
        int userChoice = opponentChoice();
        if (userChoice == 1) {
            ConsolePlayer pl1 = ConsolePlayer('X');
            ConsolePlayer pl2('O');
            GameStandard game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 2) {
            ConsolePlayer pl1=ConsolePlayer('X');
            AIPlayer pl2('O', board, logic);
            GameStandard game(pl1, pl2, board, logic);
            game.play();
            delete (logic);
            return 0;
        } else if (userChoice == 3) {
            const char *f = ipAdress.c_str();
            try {
                Client pl1 = Client('X', f, portNumb);
                ConsolePlayer pl2=ConsolePlayer(logic->oppositeSign(pl1.getSign()));
                GameOnline game(pl1, pl2, board, logic);
                game.play();
                delete (logic);
                return 0;
            } catch (const char *msg) {
                cout << "Failed to connect to server. Reason: " << msg << endl;
                exit(-1);
            }
        }


    } while (opponentChoice()==-1);
}
/**
    * opponentChoice get from user his choice about his opponent.
    * @return int - 1=AIPlayer,0=ConsolePlayer, otherwise -1
   */
int opponentChoice() {
    int userChoice;
    cout << "Welcome to Reversi!" << endl;
    cout << "Choose an opponent type:" << endl;
    cout << "1. a human local Player" << endl;
    cout << "2. an AI Player" << endl;
    cout << "3. remote Player" << endl;
    cin >> userChoice;
    if (userChoice == 1) {
        return 1;
    }
    if (userChoice == 2) {
        return 2;
    }
    if (userChoice == 3) {
        return 3;
    }
    return -1;
}
string getlineInput(string line){
   string delimiter = ":";
    string token = line.substr(line.find(delimiter) + 1, line.find("\n"));
    return token;
}
