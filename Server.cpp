// Eli Totah - 209186014
// Ofir Rothchild - 207434960

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
#include "ClientData.h"
#include "Command.h"
#include "DefaultIO.h"
#include "StandardIO.h"
#include "CLI.h"
#include "DownloadCommand.h"
#include "DisplayCommand.h"
#include "Upload.h"
#include "Setting.h"
#include "Classify.h"
#include "SocketIO.h"
#include <thread>


using namespace std;


void RunClient(int clientSock);
/******************
* Function Name: main
* Input: Arguments passed to the client from the user. the IP address of the server,
  and the port that the client listen in it.
* Output: string - the type of the k nearest vector to the vector that the user enter.
* Function Operation:The function establishes contact with the server and transmits to it the message from the user
  that includes a vector, a type of matrix according to which the distance will be calculated and a number K
  that symbolizes the K nearest neighbors according to which the vector will be classified into a certain type.
******************/
int main(int argc, char *argv[]) {
    try 
    {
        //checks if all the arguments are entered.
        if (argc != 2) {
            cout << "you need to insert 1 arguments only";
            exit(1);
        }
        //The first argument sent to the function is the port number on which the server should listen.
        char *s = argv[1];
        //Conversion of the argument received from the user as a string to an integer number using the stoi function.
        int Server_Port = stoi(s);
        TCPServer server(Server_Port);
        
        //Attempt to bind to the socket in case of failure - print the error.
        server.Bind();
        //Attempt to listen to the socket in order to get the message from the client in case of failure, print error.
        if(server.Listen() == -1) {
             exit(1);
        }
        //The server loop is running continuously and is ready to receive information from the client.
        vector<thread> threads;
        while (true)
        {   
            //Attempt to accept the socket of the client in case of failure, print error.
            int ClientSock = server.Accept();
            cout << ClientSock;
            if(ClientSock != -1) {
            threads.push_back(thread (RunClient, ClientSock));
            }
            // to see what happen here
        }
        for(int i=0; i<threads.size(); i++){
                threads.at(i).join();
            }
        //closing the sock of the client.
        close(server.GetSocket());
        return 0;
    }
    catch (exception e) {
        cout << "invalid input" << endl;
        return 0;
    } 
}


void RunClient (int clientSock) {
    SocketIO *dio = new SocketIO(clientSock);
    CLI cli(dio,clientSock);
    cli.start();
    //disconnect
}


