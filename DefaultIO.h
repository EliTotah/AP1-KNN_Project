// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_DEFAULTIO_H
#define UNTITLED_DEFAULTIO_H

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
using namespace std;
/*
This class is an abstract class whose successors will have to implement the read and write methods in their own way
 */
class DefaultIO {
        
    public:

    DefaultIO();
    ~DefaultIO() = default;
    virtual string read() = 0;
    virtual void write(string s) = 0;
private:
int clientSock;
};

#endif 
