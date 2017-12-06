#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../include/Client.h"
#include "../include/Player.h"
#include "../include/ConsolePlayer.h"

using namespace std;
Client::Client(char sign,const char *serverIP, int serverPort):
        Player(sign),sign(sign),serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    cout << "Client" << endl;

}
void Client::connectToServer() {
    int clientSocket = socket(AF_INET, SOCK_STREAM,0);
    if(clientSocket<0)
        perror("error creating socket");
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(serverIP);
    sin.sin_port = htons(serverPort);
    if(connect(clientSocket, (struct sockaddr*) &sin, sizeof(sin)) <0) {
        perror("error connecting to server");
    }
    char data_addr[] ="im a message";
    int data_len = strlen(data_addr);
    int sent_bytes = send(clientSocket,data_addr,data_len,0);
    if(sent_bytes<0)
        perror("error writing to socket");
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(clientSocket,buffer, expected_data_len,0);
    if (read_bytes == 0){
        perror("connection is close");
    }
    else if(read_bytes < 0)
        perror("error");
    else
        cout << buffer;
    //close(clientSocket);
}
int Client::message(int arg1, char op, int arg2){

    int sendSize = read(clientSocket,&sign, sizeof(sign));
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
    Point* newPoint=new Point(userX, userY);
    send
    return newPoint;
}

bool Client::checkNextTurn(GameLogic* logic) {
    if (logic->optionalTurns((getSign())).empty()) {
        cout << "No possible moves. play passes back to other player. press any key to countinue" << endl;
        cin.get();
        return false;
    }
    return true;
}
/*void sendToSocket(int sock, char* data,struct sockaddr_in &sin) {
    int sent_bytes = sendto(sock,data,strlen(data),0,(struct sockaddr*) &sin, sizeof(sin));
    if(sent_bytes<0)
        perror("error writing to socket");
}
void recieveFromSocket(int sock){
    struct sockaddr_in from;
    unsigned int from_len= sizeof(struct sockaddr_in);
    char buffer[4096];
    memset(&buffer,0,sizeof(buffer));
    int bytes = recvfrom(sock,buffer,sizeof(buffer),0,(struct sockaddr*) &from, &from_len);
    if(bytes<0)
        perror("error reading from socket");
    cout << "the server sent:" << buffer << endl;
}
int main(int argc, char const *argv[])
{
    const char* ip_addres = "127.0.0.1";
    const int port_no = 5555;
    int sock = socket(AF_INET, SOCK_DGRAM,0);
    if(sock<0)
        perror("error creating socket");
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_addres);
    sin.sin_port = htons(port_no);
    sendToSocket(sock,"hello",sin);
    recieveFromSocket(sock);
    sendToSocket(sock,"blablablao",sin);
    recieveFromSocket(sock);
    close(sock);
    return 0;
}*/