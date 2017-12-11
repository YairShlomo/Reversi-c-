/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/Client.h"


using namespace std;
Client::Client(char sign,const char *serverIP, int serverPort):
        Player(sign),serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    connectToServer();

}

void Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
        perror("error creating socket");
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(serverIP);
    sin.sin_port = htons(serverPort);
    if (connect(clientSocket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    char buffer[2];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is close");
    }
    if (clientSocket == -1) {
        throw "Error accepting client";
    }
    if (buffer[0] == '1') {
        cout << "connected to server" << endl;
        cout << "Waiting for another client connections..." << endl;
        read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
    }
        if (read_bytes == 0) {
            perror("connection is close");
            return;
        } else if (read_bytes < 0) {
            perror("error");
            return;
        }
    if (buffer[0] == '1')
        sign = 'X';
    else
        sign = 'O';
}



char* Client::getMessage() {
    int sendSize = read(clientSocket,&buffer, sizeof(buffer));
    return buffer;
}
void Client::closeMe() {
    char finish[7];
    finish[0]=getSign();
    int finishSize= sizeof(finishSize);
    int sendMessage = write(clientSocket,&finish,finishSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
}
void Client::endGame() {
char finish[7] ="END";
    int finishSize= sizeof(finishSize);
    int sendMessage = write(clientSocket,&finish,finishSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
}
void Client::moveTurn() {
    char finish[7] ="NOMOVE";
    int finishSize= sizeof(finish);
    int sendMessage = write(clientSocket,&finish,finishSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
}
Point* Client::yourPlay(vector<Point> vec) {
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
        throw "not an integer input";
    }
    cin >> userY;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000,'\n');
        throw "not an integer input";
    }
    Point* newPoint=new Point(userX, userY);
    char sendPoint[7];
    sendPoint[0]=userX +'0';
    sendPoint[1]=userY +'0';
    int sendMessage = write(clientSocket,&sendPoint, sizeof(sendPoint));
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
    return newPoint;
}

bool Client::checkNextTurn(GameLogic* logic) {
    if (logic->optionalTurns((getSign())).empty()) {
        cout << "No possible moves. play passes back to other player" << endl;
        moveTurn();
        return false;
    }
    return true;
}
