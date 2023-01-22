// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "DisplayCommand.h"

using namespace std;

/******************
* Function Name: DisplayCommand
* Input: DefaultIO *dio, ClientData *data
* Output: DisplayCommand
* Function Operation:The constructor of the DisplayCommand class, which is derived from the Command class. It takes two parameters:
 a DefaultIO pointer, and a ClientData pointer.
******************/
DisplayCommand::DisplayCommand(DefaultIO *dio, ClientData *data) : Command (dio, data){
    this->description = "display results";
}
/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation:The function The function performs the process that this command performs in accordance with the exercise definitions.
 This function is a load for the execute function defined in the abstract class command
******************/
void DisplayCommand::execute() {
    if (this->getData()->getFlag() != 1) {
        //This line writes the string "please upload data" to the DefaultIO object.
        this->getIO()->write("please upload data");
        return;
    }
    // This line checks if the classified member variable in the ClientData object is empty.
    if (this->getData()->getClassified().empty()) {
        //This line writes the string "please classify the data" to the DefaultIO object.
        this->getIO()->write("please classify the data");
        return;
    }
    else {
        //This loop iterates through all elements in the classified member variable of the ClientData object.
        for (int i = 0; i<this->getData()->getClassified().size(); i++) {
            stringstream ss;
            // This line writes the current index, a tab character, and the current element in the classified member variable of the ClientData object to the stringstream object.
            ss << (i+1) << '\t' << this->getData()->getClassified().at(i);
            //This line writes the contents of the stringstream object to the DefaultIO object.
            this->getIO()->write(ss.str());
        }
        //This line writes the string "Done." to the DefaultIO object to indicate that the display process is complete.
        this->getIO()->write("Done.");
    }
}
