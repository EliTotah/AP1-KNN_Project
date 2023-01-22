// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_SETTING_H
#define UNTITLED_SETTING_H

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
This department executes the command process for the option the user chooses in 2-
and setting the parametters k and distance according to the user choose.
 */
class Setting: public Command {
    public:
    Setting(DefaultIO *dio, ClientData *data);
    void execute();
};

#endif 
