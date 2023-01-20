
#include "TCPclient.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Validation.h"
#include "Knn.h"
#include "Distance.h"

/******************
* Function Name: TCPclient
* Input: int port, const char* ip
* Output: TCPclient
* Function Operation: constructor of TCP client
******************/
TCPclient:: TCPclient (int port, const char* ip) {
    this->clientPort = port;
    this->clientIp = ip;
    //Creating a socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    this->clientSock = sock;
}
/******************
* Function Name: getSocket
* Input: none
* Output: int- the socket of the client.
* Function Operation: getter for the socket of the current client.
******************/
int TCPclient::getSocket() {
    return this->clientSock ;
}
/******************
* Function Name: connectClient
* Input: none
* Output: none
* Function Operation: Attempt to connect to the server.
******************/
void TCPclient:: connectClient() {
    //Declare the structure of the socket address.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(this->clientIp);
    sin.sin_port = htons(this->clientPort);
    // in case the connect is failure - print the error.
     if (connect(this->clientSock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(1);
    }
}
/******************
* Function Name: validationClient
* Input: 
* Output: 
* Function Operation: 
******************/
int TCPclient::validationClient(string message) {
    int result=0, flag = 0;
    string word1, type, number;
    double number1;
    vector<double> v1;
    stringstream iss1(message);
    //read number by number from the vector that entered by the user.
    while (getline(iss1, word1, ' ')) {
        //correctness check in order to check that correct numbers have indeed been inserted into the vector.
        if (ValidCharForString(word1)) {
            //An attempt to convert the string from the user into numbers as long as it is a valid number.
            //In case it is a normal number, insertion of a number into a vector
            try {
                number1 = stod(word1);
                v1.push_back(number1);
            }
            catch (exception e) {
                flag = -1;
            }
        } else {
            break;
        }
    }
    int k;
    //In the case where the conversion failed in the middle i.e. the received vector is invalid.
    if (flag == -1) {
        cout << "invalid input" << endl;
        return result;
    }
    //Checking that the distance string entered by the user is a valid string.
    if (ValidDistance(word1)) {
        string DistanceType = word1;
        //read the next argument that entered by the user as K.
        getline(iss1, number, ' ');
        try {
            //An attempt to convert the string from the user into numbers as long as it is a valid number.
            k = stoi(number);
        } catch (exception e) {
            cout << "invalid input" << endl;
            return result;
        }
    } else {
        cout << "invalid input" << endl;
        return result;
    }
    if (k <= 0) {
        cout << "invalid input" << endl;
        return result;
    }
    result = 1;
    return result;
}
/******************
* Function Name: sendClient
* Input: none
* Output: int - True if the process succeeded, false if it failed.
* Function Operation: Sending the array of characters containing the user's message to the server.
******************/
int TCPclient::sendClient(string message) {
    int result=0;
    //Definition of the array that will contain the user's message that the client will transfer to the server.
    char data_addr[4096];
    memset(&data_addr, 0, sizeof(data_addr));
    //Conversion of the message from the user received as a string to an array of characters sent to the server.
    copy(message.begin(), message.end(), data_addr);
    int data_len = strlen(data_addr);
    //Sending the array of characters containing the user's message to the server.
    int sent_bytes = send(this->clientSock, data_addr, data_len, 0);
    //In case the sending fails.
    if (sent_bytes < 0) {
        cout << "sent is failed" << endl;
        return result;
    }
    result = 1;
    return result;
}
/*
int TCPclient::sendFileClient(string message){
    this->getFileIo().send(this->getSocket(),message);
}
*/
/******************
* Function Name: recieveClient
* Input: none
* Output: int - True if the process succeeded, false if it failed.
* Function Operation: Receipt the answer that will be received from the server with the appropriate classification.
******************/
int TCPclient::recieveClient() {
    int result=0;
    //Definition of the array that will contain the server's response.
    char buffer[4096];
    memset(&buffer, 0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    //Reading the answer that will be received from the server with the appropriate classification.
    int read_bytes = recv(this->clientSock, buffer, expected_data_len, 0);
    //In case the connect faild.
    if (read_bytes == 0) {
        cout << "connection is closed" << endl;
        return result;
    //In case the reading faild.
    } else if (read_bytes < 0) {
        return result;
    } else {
        cout << buffer << endl;
    }
    result = 1;
    return result;
}

