
#include "CommandsCilent.h"

CommandsClient::CommandsClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient) : dio(_dio), data(_data),tcpClient(_tcpClient){}

string CommandsClient::getDec() {
    return this->description;
}

DefaultIO* CommandsClient::getIO() {
    return this->dio;
}

ClientData* CommandsClient::getData() {
    return this->data;
}

bool CommandsClient::isFile(const string &name) {
    struct stat buffer{};
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}


UploadCommandClient::UploadCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}

void UploadCommandClient::execute()  {
        string string1, line, nextLine;
        this->dio->write("1");
        string1 = this->dio->read();
        cout << string1 << endl;
        getline(cin, string1);
        //if (isFile(string1)) {
                ifstream MyReadFile(string1);
                getline(MyReadFile,line);
                while (getline(MyReadFile, nextLine)) {
                // validation check of the atgument that the user insert.
                //if (!(tcpClient.validationClient(line))){
                  //  perror("invalid input");
                    //return;
                //}  
                //Sending the array of characters containing the user's message to the server.
                this->dio->write(line);
                this->dio->read();
                line = nextLine;
            }
                this->dio->write(line);
                this->dio->read();
                string1 = "end";
                dio->write(string1);
            /*}
            //ip the user not enter path
            else{
                perror("invalid input");
                return;
            }*/
            this->dio->read();
            string1 = this->dio->read();
            cout << string1 << endl;
            string1 = this->dio->read();
            cout << string1 << endl;
            getline(cin, string1);
            if (isFile(string1)) {
                ifstream MyReadFile(string1);
                getline(MyReadFile,line);
                while (getline(MyReadFile, nextLine)) {
                    // validation check of the atgument that the user insert.
                    //if(!ValidCharForString(line)){
                      // perror("invalid input");
                       //return;
                    //}
                //Sending the array of characters containing the user's message to the server.
                this->dio->write(line);
                this->dio->read();
                line = nextLine;
            }
            this->dio->write(line);
                this->dio->read();
                string1 = "end";
                dio->write(string1);
                
            }
            //ip the user not enter path
            else{
                perror("invalid input");
                return;
            }
            //read the massege from server;
            dio->read();
            string output = dio->read();
            cout << output << endl;
            return;
    }



    SettingCommandClient::SettingCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
    void SettingCommandClient::execute()  {
        string output, string1;
        this->dio->write("2");
        output = this->dio->read();
        cout << output << endl;
        getline(cin, string1);
        if(string1 == "\n"){
            return;
        }
        else{
            this->dio->write(string1);
            output =this->dio->read();
            cout << output << endl;
        }
        return;
    }



    ClassifyCommandClient::ClassifyCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
    void ClassifyCommandClient::execute()  {
        string output, string1;
        this->dio->write("3");
        output = this->dio->read();
        cout << output << endl;
    }



DisplayCommandClient::DisplayCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
    void DisplayCommandClient::execute()  {
        string output, string1;
        this->dio->write("4");
        output = this->dio->read();
        if (output == "please upload data"){
            cout << output << endl;
            return;
        }
        if (output == "please classify the data"){
            cout << output << endl;
            return;
        }
        else{
            while (output != "Done.")
            {
                cout << output << endl;
                output = this->dio->read();
            }
            cout << output << endl;
        }
        getline(cin, string1);
        if(string1 == "\n"){
            return;
        }
    }


DownloadCommandClient::DownloadCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
    void DownloadCommandClient::execute()  {
      string output, string1;
        this->dio->write("5");
        output = this->dio->read();
        if (output == "please upload data"){
            cout << output << endl;
            return;
        }
        if (output == "please classify the data"){
            cout << output << endl;
            return;
        }
        else {
            output = this->dio->read();
            cout << output << endl;
            getline(cin, string1);
            if (isFile(string1)){
                ofstream file;
                file.open(string1);
                 while (output!= "Done.")
            {
                file << output << endl;
                output = this->dio->read();
            }
            } else{
                perror("invalid input");
                return;
            }
        }
    }
