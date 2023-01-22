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
#include "CliClient.h"
#include "SocketIO.h"

using namespace std;
/******************
* Function Name: main
* Input: Arguments passed to the client from the user. the IP address of the server,
  and the port that the client listen in it.
* Output: string - the type of the k nearest vector to the vector that the user enter.
* Function Operation:The function establishes contact with the server and transmits to it the message from the user
  that includes a vector, a type of matrix according to which the distance will be calculated and a number K
  that symbolizes the K nearest neighbors according to which the vector will be classified into a certain type.
******************/

inline bool isFile(const std::string &name);

int main(int argc, char *argv[]) {
    try
    {
        //checks if all the arguments are entered.
        if (argc != 3) {
            cout << "you need to insert 2 arguments only";
            //if the arguments are not entered properly the program can not continue.
            exit(1);
        }
        const char *ip_address = argv[1];
        const char *buffer;
        //try to convert from presentation format of an Internet number in buffer and store result for interface type AF in buffer starting at BUF.
        // if the convert feild the ip number unvalid.
        if (inet_pton(AF_INET, ip_address, &buffer) == 0 ) {
            cout << " invalid ip" << endl;
            exit(1);
        }
        //the second argument is the port number.
        char* port = argv[2];
        //Conversion of the argument received from the user as a string to an integer number using the stoi function.
        const int port_no = stoi(port);
        //check if the port is in the valid range
        if (port_no < 1025 || port_no > 65535) {
            cout << " invalid port" << endl;
            exit(1);
        }
        //create of object of tcpClient.
        TCPclient tcpClient(port_no, ip_address);
        //Socket creation failed.
        if (tcpClient.getSocket() < 0) {
            perror("error creating socket");
            return 0;
        }
        //Attempt to connect to the server in case of failure - print the error.
        tcpClient.connectClient();
        //As long as the client's communication with the server is normal,
        // the user can insert additional vectors and get the appropriate classification for them.
        SocketIO *dio = new SocketIO(tcpClient.getSocket());
        CliCLient cli(dio,tcpClient.getSocket(),tcpClient);
        cli.start();
        //closing the sock of the client.
        close(tcpClient.getSocket());
    }
    catch (exception e) {
        cout << "invalid input-2" << endl;
    }
}

