// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "DownloadCommand.h"

using namespace std;
/******************
* Function Name: execute
* Input: DefaultIO *dio, ClientData *data
* Output: an object DownloadCommand
* Function Operation:constructor of the DownloadCommand class, which is derived from the Command class. It takes two parameters:
 a DefaultIO pointer and a ClientData pointer, and initializes the corresponding member variables of the class. Also, it sets the description of the command
******************/
DownloadCommand::DownloadCommand(DefaultIO *dio, ClientData *data): Command (dio, data) {
    this->description = "download results";
}
/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation:This function is a member function of the DownloadCommand class, it is responsible for executing the download command.
******************/
void DownloadCommand::execute() {
     //This line checks if the flag member variable of the ClientData object is not equal to 1.
    if (this->getData()->getFlag() != 1) {
        //This line writes the string "please upload data" to the DefaultIO object.
        this->getIO()->write("please upload data");
        return;
    }
    //This line checks if the classified member variable of the ClientData object is empty.
    else if (this->getData()->getClassified().empty()) {
         //This line writes the string "please classify the data" to the DefaultIO object.
        this->getIO()->write("please classify the data");
        return;
    }
    // This line executed if the flag is 1 and classified is not empty.
    else {
         //This line writes the string "enter path for the output" to the DefaultIO object.
        this->getIO()->write("enter path for the output");
         // This loop iterates through all elements in the classified member variable of the ClientData object.
        for (int i = 0; i<this->getData()->getClassified().size(); i++) {
            stringstream ss;
            ss << (i+1) << '\t' << this->getData()->getClassified()[i] << endl;
            this->getIO()->write(ss.str());
            this->getIO()->read();
        }
        this->getIO()->write("Done.");
    }
}
