// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_STANDARDIO_H
#define UNTITLED_STANDARDIO_H

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

using namespace std;

class StandardIO : public DefaultIO { 
   public:
    StandardIO(int sock);
    string read();
    void write(string s);
private:
int sock;
};

#endif 