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

/*
This class is an abstract class that implements the execute function that all the commands that inherit it must implement
according to the design template called Command
 */
class Command {
    protected:
    DefaultIO *dio;
    ClientData *data;
    string description;
    
    public:
    Command(DefaultIO *_dio, ClientData *_data);
    ~Command() = default;
    virtual void execute() = 0;
    string getDec();
    DefaultIO *getIO();
    ClientData *getData();
};

#endif 
