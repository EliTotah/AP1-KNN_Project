// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "Command.h"
/******************
* Function Name: Command
* Input: DefaultIO *dio, ClientData *data
* Output: Command
* Function Operation:Declares the constructor for the Command class. It takes two pointers as parameters, one for DefaultIO and one for ClientData, and assigns them to the corresponding member variables dio and data using initialization list.
******************/
Command::Command(DefaultIO *_dio, ClientData *_data) : dio(_dio), data(_data) {}
/******************
* Function Name: getDec
* Input: void
* Output: string
* Function Operation:This function is a member function of CommandsClient class, which returns the description of the command.
******************/
string Command::getDec() {
    return this->description;
}
/******************
* Function Name:getIO 
* Input: void
* Output: DefaultIO*
* Function Operation: This function is a member function of CommandsClient class, which returns the DefaultIO pointer of the class.
******************/
DefaultIO* Command::getIO() {
    return this->dio;
}
/******************
* Function Name: getData
* Input: void
* Output: ClientData*
* Function Operation:This function is a member function of CommandsClient class, which returns the ClientData pointer of the class.
******************/
ClientData* Command::getData() {
    return this->data;
}


