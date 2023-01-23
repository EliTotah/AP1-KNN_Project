// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_SOCKETIO_H
#define UNTITLED_SOCKETIO_H

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

class SocketIO : public DefaultIO { 

public:
    SocketIO(int cilentSock);
    ~SocketIO() = default;
    string read();
    void write(string s);
private:
   int socket;
};

#endif 
