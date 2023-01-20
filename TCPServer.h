// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_TCPSERVER_H
#define UNTITLED_TCPSERVER_H

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

class TCPServer {
    public:
    TCPServer(int Server_Port);
    int GetServerPort();
    int GetSocket();
    void Bind();
    int Listen();
    int Accept();
    int Read(int Client_Sock);
    string KnnProcess(char buffer[4096]);
    int Send(string result, int Client_Sock);

    private:
    string file; 
    int Server_Port;   
    int sock;
};

#endif 