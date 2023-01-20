
#ifndef UNTITLED_TCPCLIENT_H
#define UNTITLED_TCPCLIENT_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Validation.h"
#include "Knn.h"
#include "Distance.h"
#include "DefaultIO.h"

class TCPclient {
public:
    TCPclient(int port, const char* ip);
    int getSocket ();
    void connectClient();
    int validationClient (string message);
    int sendClient (string message);
    int sendFileClient (string message);
    int recieveClient ();
    string recieveFileClient();

private:
    int clientPort;
    const char* clientIp;
    int clientSock;

};


#endif //UNTITLED_TCPCLIENT_H
