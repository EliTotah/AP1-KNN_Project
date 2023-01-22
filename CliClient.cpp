// Eli Totah - 209186014
// Ofir Rothchild - 207434960


#include "CliClient.h"

CliCLient::CliCLient(DefaultIO *_dio, int _clientSock, TCPclient _tcp) : dio(_dio), clientSock(_clientSock), tcpClient(_tcp) {
    ClientData *data = new ClientData();
    vector<CommandsClient*> commands;
    UploadCommandClient *u = new UploadCommandClient(dio, data, this->tcpClient);
    SettingCommandClient *s = new SettingCommandClient(dio, data,this->tcpClient);
    ClassifyCommandClient*c = new ClassifyCommandClient(dio, data,this->tcpClient);
    DisplayCommandClient *d = new DisplayCommandClient(dio, data,this->tcpClient);
    DownloadCommandClient *do1 = new DownloadCommandClient(dio, data,this->tcpClient);
    vec.push_back(u);
    vec.push_back(s);
    vec.push_back(c);
    vec.push_back(d);
    vec.push_back(do1);
}

vector<CommandsClient*>& CliCLient::commands() {
    return this->vec;
}

DefaultIO* CliCLient::getIO() {
    return this->dio;
}

void CliCLient::start() {
     while (true) {
        string choose;
            // scan the line from the user which includes vector, K and distance matrix.
        if (tcpClient.recieveClient() > 0) {
        getline(cin,choose);
        }
        int num;
        try {
            num = stoi(choose);
        }
        catch (exception e) {
            this->getIO()->write("please enter a number-1\n");
            return;
        }
        if (choose == "8") {
            this->getIO()->write("8");
            return;
        }
        if (num <=0 || num > vec.size()) {
            this->getIO()->write("invalid choose\n");
            return;
        }
        vec[num-1]->execute();
}   
}