// Eli Totah - 209186014
// Ofir Rothchild - 207434960


#include "CLI.h"
/******************
* Function Name: CLI
* Input: DefaultIO *dio, ClientData *data
* Output: CLI
* Function Operation: constructor that accepts two arguments, a pointer to a DefaultIO object, _dio, and an integer, _clientsock, and initializes the dio and clientsock member variables of the clas
******************/
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

CLI::~CLI(){
    delete data;
    delete dio;
    for (auto & v:vec) {
        delete v;
    }
}

vector<Command*>& CLI::commands() {
    return this->vec;
}

DefaultIO* CLI::getIO() {
    return this->dio;
}

/******************
* Function Name: menu
* Input:void
* Output: void
* Function Operation: menu function that displays a list of options to the user and the corresponding descriptions
******************/
void CLI::menu() {
    // creates a message with a welcome message and the list of options
    string msg = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    // loop through the vector of Command pointers
    for (int i = 0; i<vec.size(); i++) {
        // append the option number, a period, and the description of the option to the message
        msg.append(to_string(i+1) + ". " + vec.at(i)->getDec() + "\n");
    }
    //append the option to exit to the message
    msg.append("8. exit");
    // write the message to the user
    this->getIO()->write(msg);
}
/******************
* Function Name: start
* Input:void
* Output: void
* Function Operation: start function that starts the command-line interface
******************/

void CLI::start() {
    while(true) {
        menu();
        //reads the input of the user
        string choose = this->getIO()->read();
        // check if the input is out of range
        if (choose == "invalid choose\n") {
            this->getIO()->write("invalid choose\n");
            continue;
        }
        int num;
        try {
            // try to convert the input to integer
            num = stoi(choose);
        }
        // if the input is not a number, display the error message
        catch (exception e) {
            this->getIO()->write("please enter a number\n");
            continue;
        }
        // check if the input is 8 for exit
        if (choose == "8") {
            // close interaction
            return;
        }
        // check if the input is out of range
        if (num <=0 || num > vec.size()) {
            this->getIO()->write("invalid choose\n");
            continue;
        }
        // execute the corresponding command
        vec[num-1]->execute();
    }
}   
