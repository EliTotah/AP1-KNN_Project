// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "TCPServer.h"
/******************
* Function Name: TCPServer
* Input: string& file, int Server_Port
* Output: TCPServer
* Function Operation: constructor of TCP server.
******************/
TCPServer::TCPServer(int Server_Port) {
    this->Server_Port = Server_Port;
    //Creating a socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //Socket creation failed.
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    this->sock = sock;
}
/******************
* Function Name: GetServerPort
* Input: none
* Output: int, the nomber of the server port.
* Function Operation: getter to the nomber of the server port.
******************/
int TCPServer::GetServerPort() {
    return this->Server_Port;
}  
/******************
* Function Name: GetSocket
* Input: none
* Output: int - the socket number
* Function Operation: getter to the number of the socket of the client.
******************/
int TCPServer::GetSocket() {
    return this->sock;
}  
/******************
* Function Name: Bind
* Input: none
* Output: none
* Function Operation: Attempt to bind to the socket in case of failure - print the error.
******************/
void TCPServer::Bind() {
    //Declare the structure of the socket address.
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(Server_Port);
    //Attempt to bind to the socket in case of failure - print the error.
    if (bind(this->sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(1);
    }
}
/******************
* Function Name: Listen
* Input: none
* Output: int : 1 - If listen to the socket of the client was successful.
 -1 - if it failed.
* Function Operation: Attempt to listen to the socket in order to get the message from the client in case of failure, print error.
******************/
int TCPServer::Listen() {
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return -1;
    }
    return 1;
}
/******************
* Function Name: Accept
* Input: none
* Output: int the Client_Sock from the accept operation.
* Function Operation: Attempt to accept the socket of the client in case of failure, print error.
******************/
int TCPServer::Accept() {
    //Declare the structure of the socket address of the current client.
    struct sockaddr_in Client_Sin;
    unsigned int addr_len = sizeof(Client_Sin);
    //Attempt to accept the socket of the client in case of failure, print error.
    int Client_Sock = accept(this->GetSocket(), (struct sockaddr *) &Client_Sin, &addr_len);
    cout << Client_Sock << endl;
    if (Client_Sock < 0) {
        perror("error accepting client");
        return -1;
    }
    return Client_Sock;
}
/******************
* Function Name: Read
* Input:int Client_Sock
* Output: int : 1 - If reading the message from the client was successful.
 -1 - if the reading failed or the message is invalid.
* Function Operation: Attempt to receive the message of the users that sent by the client in case of failure, print error.
******************/
int TCPServer::Read(int Client_Sock) {
    //Definition of the array that will contain the user's message that the client will transfer.
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    //Attempt to receive the message of the users that sent by the client in case of failure, print error.
    int read_bytes = recv(Client_Sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        cout << "connection is closed" << endl;
        return -1;
    } else if (read_bytes < 0) {
            cout << "error" << endl;
                return 0;
            } else {
                string result = KnnProcess(buffer);
                Send(result, Client_Sock);
            }
    return 1;
}
/******************
* Function Name: KnnProcess
* Input: char buffer[4096]
* Output: string- the clasiffication of the vector from the user.
* Function Operation: In the case of correct receipt of the message from the client,
the array of characters is converted into various variables that make up the user's message
******************/
string TCPServer::KnnProcess(char buffer[4096]) {
    string string1(buffer);
    stringstream iss(string1);
    vector<double> v1;
    double number1;
    string word, type;
    int k, flag=0;
    //read number by number from the vector that entered by the user.
    while (getline(iss, word, ' ')) {
        //correctness check in order to check that correct numbers have indeed been inserted.
        if (ValidCharForString(word)) {
            try {
                //An attempt to convert the string from the user into numbers as long as it is a valid number.
                //In case it is a normal number, insertion of a number into a vector.
                number1 = stod(word);
                v1.push_back(number1);
                } catch (exception e) {
                    flag = -1;
                }
            } else {
                   break;
                }
        }
        if (flag == -1) {
            return "-1";
        }
        type = word;
        //read the next argument that entered by the user as K.
        getline(iss, word, ' ');
        try {
        //An attempt to convert the string from the user into numbers as long as it is a valid number.
        k = stoi(word);
        }
        catch (exception e) {
            return "-1";
        }
        //A call to the KNN algorithm whose function is to classify the vector entered by the user
        // using the K nearest neighbors algorithm.
        //Knn knn1(v1, k, type, file);
        //return knn1.KnnProcess();
        return "bla";
}
/******************
* Function Name: Send
* Input: string result, int Client_Sock
* Output: int - the sent_bytes from the send of the classification for the vector of the user.
* Function Operation: constructor of TCP client
******************/
int TCPServer::Send(string result, int Client_Sock) { 
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    //Conversion of the result obtained as a string from the KNN algorithm into an array of characters.
    copy(result.begin(), result.end(), buffer);
    //sent  the array of characters with the correct classification to the client.
    int sent_bytes = send(Client_Sock, buffer, expected_data_len, 0);
    //In case the sending fails.
    if (sent_bytes < 0) {
        perror("error sending to client");
        return -1;
    }
    return sent_bytes;
}
