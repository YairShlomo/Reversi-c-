/*
Name:Yair Shlomo
ID: 308536150
Name:Gal Eini
ID: 305216962
*/
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/Client.h"

#include <sstream>
#include <string>
#include <map>


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
    char buffer[11];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is close");
    }
    if (read_bytes == -1) {
        throw "Error accepting client";
    }
    if (buffer[0] == '1') {
        cout << "connected to server" << endl;
        //main cout << "connected to server" << endl;


        do {
            char myCommand[100];

            int myCommandSize = sizeof(myCommand);
            //string myCommand;
//            gets(myCommand );
            fgetc(stdin);
            fgets(myCommand,myCommandSize,stdin);

           // cout<< myCommand<< endl;
            int sendMessage = write(clientSocket, &myCommand, myCommandSize);
            cout<< myCommand<< endl;

            if (sendMessage == -1) {
                throw "Error writing to socket";
            }

            read_bytes = recv(clientSocket, buffer, expected_data_len, 0);

            if (read_bytes == 0) {
                perror("connection is close");
                return;
            } else if (read_bytes < 0) {
                perror("error");
                return;
            }
            /*
            if (buffer[0] == '1')
                sign = 'X';
                */
            else if (buffer[0] == '2') {
                sign = 'O';
            } else if (strcmp(buffer, "start") == 0) {
                cout << "Waiting for another client connections..." << endl;
                read_bytes = recv(clientSocket, buffer, expected_data_len, 0);
                if (read_bytes == 0) {
                    perror("connection is close");
                    return;
                } else if (read_bytes < 0) {
                    perror("error");
                    return;
                } else if (strcmp(buffer, "bad name")==0) {
                    continue;
                } else if (buffer[0] == '1') {
                    sign = 'X';
                } else
                    throw "error";
            } else if (strcmp(buffer, "list_games") == 0) {
                cout << "Games avaliable to play are:\n";
                char bufferGames[50];

                do {
                    read_bytes = recv(clientSocket, bufferGames, expected_data_len, 0);

                    if (read_bytes == 0) {
                        perror("connection is close");
                        return;
                    } else if (read_bytes < 0) {
                        perror("error");
                        return;
                    }
                    if (bufferGames[0] != '0') {
                        cout << bufferGames << "\n";
                    }
                } while (bufferGames[0] != '0');
            }
        } while (strcmp(buffer, "list_games") == 0);
    }
}

int Client::isValidCommand(string myCommand) {
    stringstream ss(myCommand);
    string command;
    ss >> command;
    const char *firstWord = command.c_str();
    if ((!strcmp(firstWord,"play")!=0)) {
        return 1;
    }
    if (!strcmp(firstWord,"close")!=0) {
        return 2;

    } else {
        cout << "wrong command.only 'play','close' commands available ";
        return 0;
    }
}

void Client::sendCommand(char* myCommand) {
    int myCommandSize= sizeof(myCommand);
    int sendMessage = write(clientSocket,&myCommand,myCommandSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
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
    string finish ="play NOMOVE";
    //char finish[7] ="play NOMOVE";
    int finishSize= sizeof(finish);
    int sendMessage = write(clientSocket,&finish,finishSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
}
Point* Client::extractPoint(string myCommand) {
    string buf;
    stringstream ss(myCommand);
    vector<string> tokens;
    string command;
    ss >> command;


    //tokens.push_back(command);

    while (ss >> buf)
        tokens.push_back(buf);
    //tokens.erase(tokens.begin());
    int x = atoi(tokens[0].c_str());
    int y = atoi(tokens[1].c_str());

    return new Point(x, y);

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

    char myCommand[100];
    int isValid;
    do {
        int myCommandSize = sizeof(myCommand);

        fgetc(stdin);
        fgets(myCommand, myCommandSize, stdin);
        string myCommandString(myCommand);
        isValid=(isValidCommand(myCommandString));
        // string myCommand;
        if (isValid== 2) {
            //sendMessage(myCommand);
            int myCommandSize= sizeof(myCommand);
            int sendMessage = write(clientSocket,&myCommand,myCommandSize);
            if (sendMessage == -1) {
                throw "Error writing to socket";
            }
            return NULL;
        }
    }while(isValid==0);
    string myCommandString(myCommand);
    Point* newPoint = extractPoint(myCommandString);
   // sendCommand(myCommand);
    int myCommandSize= sizeof(myCommand);
    int sendMessage = write(clientSocket,&myCommand,myCommandSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
        /*
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
              */

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
