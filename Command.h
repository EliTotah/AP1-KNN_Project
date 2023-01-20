// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_COMMAND_H
#define UNTITLED_COMMAND_H

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include "Validation.h"
#include "Knn.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "TCPServer.h"
#include "DefaultIO.h"
#include "ClientData.h"
using namespace std;

class Command {
    protected:
    DefaultIO *dio;
    ClientData *data;
    string description;
    
    public:
    Command(DefaultIO *_dio, ClientData *_data);
    virtual void execute() = 0;
    string getDec();
    DefaultIO *getIO();
    ClientData *getData();
};

#endif 