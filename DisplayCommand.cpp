// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "DisplayCommand.h"

using namespace std;

DisplayCommand::DisplayCommand(DefaultIO *dio, ClientData *data) : Command (dio, data){
    this->description = "display results";
}

void DisplayCommand::execute() {
    if (this->getData()->getFlag() != 1) {
        this->getIO()->write("please upload data");
        return;
    }
    if (this->getData()->getClassified().empty()) {
        this->getIO()->write("please classify the data");
        return;
    }
    else {
        for (int i = 0; i<this->getData()->getClassified().size(); i++) {
            stringstream ss;
            ss << (i+1) << '\t' << this->getData()->getClassified().at(i);
            this->getIO()->write(ss.str());
        }
        this->getIO()->write("Done.");
    }
}
