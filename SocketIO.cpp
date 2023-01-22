// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "SocketIO.h"
/*
class constructor accepts an integer argument, clientSock, which is used to initialize the socket file descriptor of the class.
*/
SocketIO::SocketIO(int clientSock) {
    this->socket = clientSock;
}

string SocketIO::read() {
    //Definition of the array that will contain the user's message that the client will transfer.
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    //Attempt to receive the message of the users that sent by the client in case of failure, print error.
    int read_bytes = recv(this->socket, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
            return "connection is closed";
    } else if (read_bytes < 0) {
            return "error";
            } else {
                return buffer;
            }
}

void SocketIO::write(string s) {
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    //Conversion of the result obtained as a string from the KNN algorithm into an array of characters.
    copy(s.begin(), s.end(), buffer);
    //sent  the array of characters with the correct classification to the client.
    int sent_bytes = send(this->socket, buffer, expected_data_len, 0);
    //In case the sending fails.
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}
   
