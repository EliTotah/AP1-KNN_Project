// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_DOWNLOADCOMMAND_H
#define UNTITLED_DOWNLOADCOMMAND_H

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
#include "Command.h"
using namespace std;
/*
This department executes the command process for the option the user chooses in 5-
and downloads the classified file to the user's computer
 */
class DownloadCommand : public Command {
    public:
    DownloadCommand(DefaultIO *dio, ClientData *data);
    ~DownloadCommand() = default;
    void execute();
};

#endif 
