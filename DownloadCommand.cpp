// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "DownloadCommand.h"

using namespace std;

DownloadCommand::DownloadCommand(DefaultIO *dio, ClientData *data): Command (dio, data) {
    this->description = "download results";
}

void DownloadCommand::execute() {
    if (this->getData()->getFlag() != 1) {
        this->getIO()->write("please upload data");
        return;
    }
    else if (this->getData()->getClassified().empty()) {
        this->getIO()->write("please classify the data");
        return;
    }
    else {
        this->getIO()->write("enter path for the output");
        for (int i = 0; i<this->getData()->getClassified().size(); i++) {
            stringstream ss;
            ss << (i+1) << '\t' << this->getData()->getClassified()[i] << endl;
            this->getIO()->write(ss.str());
        }
        this->getIO()->write("Done.");
    }
}
