// Eli Totah - 209186014
// Ofir Rothchild - 207434960


#include "CLI.h"

CLI::CLI(DefaultIO *_dio, int _clientsock) : dio(_dio),clientsock(_clientsock) {
    ClientData *data = new ClientData();
    vector<Command*> commands;
    Upload *u = new Upload(dio, data);
    Setting *s = new Setting(dio, data);
    Classify *c = new Classify(dio, data);
    DisplayCommand *d = new DisplayCommand(dio, data);
    DownloadCommand *do1 = new DownloadCommand(dio, data);
    vec.push_back(u);
    vec.push_back(s);
    vec.push_back(c);
    vec.push_back(d);
    vec.push_back(do1);
}

vector<Command*>& CLI::commands() {
    return this->vec;
}

DefaultIO* CLI::getIO() {
    return this->dio;
}


void CLI::menu() {
    string msg = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    for (int i = 0; i<vec.size(); i++) {
        msg.append(to_string(i+1) + ". " + vec.at(i)->getDec() + "\n");
    }
    msg.append("8. exit");
    this->getIO()->write(msg);
}

void CLI::start() {
    while(true) {
        menu();
        string choose = this->getIO()->read();
        int num;
        try {
            num = stoi(choose);
        }
        catch (exception e) {
            this->getIO()->write("please enter a number-2\n");
            continue;
        }
        if (choose == "8") {
            // close interaction
            return;
        }
        if (num <=0 || num > vec.size()) {
            this->getIO()->write("invalid choose\n");
            continue;
        }
        vec[num-1]->execute();
    }
}   