// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_CLIENTDATAT_H
#define UNTITLED_CLIENTDATAT_H

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
using namespace std;

class ClientData {

    public:
    ClientData();
    ~ClientData() = default;
    int getFlag();
    void setFlag();
    void setSettings (int k, string distance);
    void setClassified (vector <string> v);
    void setNonClassified(vector<string> NonClassified); 
    void setDataBase(vector<string> dataBase); 
    int getK();
    string getMetrica();
    vector<string> getNonClassified();
    vector<string> getDataBase();
    vector<string> getClassified();

    private:
    int flag = 0;
    string metrica;
    int k;
    vector<string> NonClassified;;
    vector <string> Classified;
    vector<string> dataBase;;
};

#endif
