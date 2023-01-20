// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_CLI_H
#define UNTITLED_CLI_H

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
#include "Command.h"
#include "StandardIO.h"
#include "DownloadCommand.h"
#include "DisplayCommand.h"
#include "Upload.h"
#include "Setting.h"
#include "Classify.h"

using namespace std;

class CLI {
    private:
    DefaultIO *dio;
    vector<Command*> vec;
    ClientData *data;
    int clientsock;
    void menu();

    public:
    CLI (DefaultIO *dio, int clientsock);
    void start();
    vector<Command*>& commands();
    DefaultIO *getIO();

};

#endif 