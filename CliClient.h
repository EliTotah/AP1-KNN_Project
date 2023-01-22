// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_CLI_H
#define UNTITLED_CLI_H


#include <sys/stat.h>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "DefaultIO.h"
#include "CommandsCilent.h"

using namespace std;

class CliCLient {
    private:
    DefaultIO *dio;
    vector<CommandsClient*> vec;
    ClientData *data;
    int clientSock;
    TCPclient tcpClient;

    public:
    CliCLient(DefaultIO *dio,int clientSock,TCPclient tcpCLient);
    void start();
    vector<CommandsClient*>& commands();
    DefaultIO *getIO();

};

#endif 