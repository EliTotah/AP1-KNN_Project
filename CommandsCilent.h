// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_COMMANDSCLIENT_H
#define UNTITLED_COMMANDSCLIENT_H

#include <vector>
#include <iostream>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include "Validation.h"
#include "Knn.h"
#include "Distance.h"
#include "TCPclient.h"
#include <regex>
#include "ClientData.h"

using namespace std;

class CommandsClient {
    protected:
    DefaultIO *dio;
    ClientData *data;
    TCPclient tcpClient;
    string description;
    
    public:
    CommandsClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient);
    virtual void execute() = 0;
    string getDec();
    DefaultIO *getIO();
    ClientData *getData();
    bool isFile(const string &name);
};

class UploadCommandClient : public CommandsClient {
public:
    UploadCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient);
    void execute();
};

class SettingCommandClient : public CommandsClient {
public:
    SettingCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient);
    void execute();
};

class ClassifyCommandClient : public CommandsClient {
public:
    ClassifyCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient);
    void execute();
};

class DisplayCommandClient : public CommandsClient {
public:
DisplayCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient);
void execute();
};

class DownloadCommandClient : public CommandsClient {
public:
DownloadCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient);
void execute();
};








#endif 