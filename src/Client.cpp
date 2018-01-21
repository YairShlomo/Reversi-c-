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
    fgetc(stdin);
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

        menu();
        do {
            char myCommand[100];

            int myCommandSize = sizeof(myCommand);
            //string myCommand;
//            gets(myCommand );
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
            if (buffer[0] == '2') {
                sign = 'O';
            } else if (strcmp(buffer,"ENS")==0){
                "Server closed. you disconnected";
                return;
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
                int expected_data_len = sizeof(bufferGames+1);

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
void Client::menu(){
    cout<<"Commands availavle are:"<<endl;
    cout<<"press start x- for start new game name x"<<endl;
    cout<<"press join x- for joining a game name x"<<endl;
    cout<<"press list_games - to see all games avaliable to join to"<<endl;

}
void Client::menuGame(){
    cout<<"Commands availavle are:"<<endl;
    cout<<"press play x- for playing x move"<<endl;

}
int Client::isValidCommand(string myCommand) {
    stringstream ss(myCommand);
    string command;
    ss >> command;
    const char *firstWord = command.c_str();
    if ((!strcmp(firstWord,"play")!=0)) {
        return 1;
    }
    if (!strcmp(firstWord,"ENDS")!=0) {
        return 2;

    } else {
        cout << "wrong command.only 'play','close' commands available \n";
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
char finish[9] ="play END";
    //int finishSize= sizeof(finishSize);
    int finishSize= 9;
    int sendMessage = write(clientSocket,&finish,finishSize);
    if (sendMessage == -1) {
        throw "Error writing to socket";
    }
}
void Client::moveTurn() {
    char finish[10] ="play NOM";

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
    int x;
    x = atoi(tokens[0].c_str());
    int y;
    y = atoi(tokens[1].c_str());

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
    cout << "Please enter your move row ,col like this: play x y" << endl;
    //void menu();

    char myCommand[100];
    int isValid;
    do {
        int myCommandSize = sizeof(myCommand);
        //fgetc(stdin);
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
vector<string> Client::getArgs() {
    char bufferArg[10];
    int expected_data_len = sizeof(bufferArg);
    int read_bytes;
    vector<string> tokens;

        read_bytes = recv(clientSocket, bufferArg, expected_data_len, 0);
        cout<<bufferArg<<endl;
        if (read_bytes == 0) {
            perror("connection is close");
            throw "client disconnected";
        } else if (read_bytes < 0) {
            perror("error");
            throw "error reading";
        }
/*
    do {
        int read_bytes = recv(clientSocket, bufferArg, expected_data_len, 0);
        cout<<bufferArg<<endl;
        if (read_bytes == 0) {
            perror("connection is close");
            throw "client disconnected";
        } else if (read_bytes < 0) {
            perror("error");
            throw "error reading";
        }
            stringstream ss;
            string s;
            char c = bufferArg[0];
            ss << c;
            ss >> s;
            tokens.push_back(s);
    } while (bufferArg[2]!='S');
    return tokens;
*/

    if ((strcmp(bufferArg,"NOM")==0)||(strcmp(bufferArg,"ENC")==0)||
            (strcmp(bufferArg,"END")==0)||(strcmp(bufferArg,"ENS")==0)) {
        string command(bufferArg);
        tokens.push_back(command);
        return tokens;
    }
    stringstream xSS;
    string x;
    char xC = bufferArg[0];
    xSS << xC;
    xSS >> x;
    tokens.push_back(x);
    stringstream ySS;
    string y;
    char yC = bufferArg[1];
    ySS << yC;
    ySS >> y;
    tokens.push_back(y);

    return tokens;
}
