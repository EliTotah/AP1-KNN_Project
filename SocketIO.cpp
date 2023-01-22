// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "SocketIO.h"

/******************
* Function Name: SocketIO
* Input: DefaultIO *dio, ClientData *data
* Output: an object DownloadCommand
* Function Operation:class constructor accepts an integer argument, clientSock, which is used to initialize the socket file descriptor of the class.
******************/
//The SocketIO class constructor accepts an integer argument, clientSock, which is used to initialize the socket file descriptor of the class.
SocketIO::SocketIO(int clientSock) {
    this->socket = clientSock;
}
/******************
* Function Name: read
* Input: void
* Output: string
* Function Operation:used to read data from the socket and returns the data in the form of a string.
It uses a char array buffer of size 4096 to store the received data.
The recv() function is used to receive data from the socket and the number of bytes received is stored in read_bytes. If read_bytes is 0, it returns the string "connection is closed", if read_bytes is less than 0, it returns the string "error" else it returns the buffer as a string.
******************/
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
/******************
* Function Name: write
* Input: string s
* Output: void
* Function Operation:used to send data over the socket. It takes a string argument, s, which contains the data to be sent.
It uses a char array buffer of size 4096 to store the data to be sent. The memset function is used to clear the buffer.
The copy function is used to copy the elements of the string s to the buffer array.The send() function is used to send data to the socket.
The number of bytes sent is stored in sent_bytes. If sent_bytes is less than 0, it prints an error message "error sending to client".
******************/
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
   
