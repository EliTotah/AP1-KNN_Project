
#include "CommandsCilent.h"

/******************
* Function Name: isFile
* Input:string &name
* Output: bool
* Function Operation: verify that the input string is file
******************/
bool isFile(const string &name) {
    struct stat buffer{};
    return ((stat(name.c_str(), &buffer) == 0) and (buffer.st_mode & S_IFREG));
}

/******************
* Function Name: RunDownload
* Input: vector<string> v1
* Output: void
* Function Operation: the function forward the string from the vector to the file
******************/
void RunDownload(vector<string> v1){
            ofstream file;
            // open file in the entered path 
            string myFIle = v1.at(0);
            file.open(myFIle);
                for(int i=1; i<v1.size(); i++){
                    // forward the string from the vector to the file
                     file << v1.at(i);
                }
                file.close();
                return;
}


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



UploadCommandClient::UploadCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}

/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation: the function forward the data in the files to the server 
******************/
void UploadCommandClient::execute()  {
        string string1, line, nextLine;
        this->dio->write("1");
        string1 = this->dio->read();
        cout << string1 << endl;
        // get the path from the user
        getline(cin, string1);
        if (isFile(string1)) {
            ifstream MyReadFile(string1);
            getline(MyReadFile,line);
            while (getline(MyReadFile, nextLine)) {
            // validation check of the string in the file.
            if (!(stringToVector(line))) {
                perror("invalid input");
                this->getIO()->write("return");
                return;
            }  
                //Sending the string to the server.
                this->dio->write(line);
                this->dio->read();
                line = nextLine;
            }
                this->dio->write(line);
                this->dio->read();
                string1 = "end";
                dio->write(string1);
            }
            //if the user not enter path
            else{
                perror("invalid input");
                this->getIO()->write("return");
                return;
            }
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
                    // validation check of the strings in the file.
                    if (!(stringToVector(line))) {
                        perror("invalid input");
                        this->getIO()->write("return");
                        return;
                    } 
                //Sending the strings to the server.
                this->dio->write(line);
                this->dio->read();
                line = nextLine;
            }
            this->dio->write(line);
                this->dio->read();
                string1 = "end";
                dio->write(string1);
            }
        //if the user not enter path
        else{
            perror("invalid input");
            this->getIO()->write("return");
            return;
        }
            //read the massege from server;
            dio->read();
            string output = dio->read();
            cout << output << endl;
            return;
    }


    SettingCommandClient::SettingCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation: the function prints the currents k and metrica and give the user option to change them
******************/
    void SettingCommandClient::execute()  {
        string output, string1;
        this->dio->write("2");
        output = this->dio->read();
        cout << output << endl;
        getline(cin, string1);
        this->dio->write(string1);
        output = this->dio->read();
        if (output == "enter") {
            return;
        }
        cout << output << endl;
    }


    ClassifyCommandClient::ClassifyCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation: the function send to server the choice - so the server will classify the data
******************/
    void ClassifyCommandClient::execute()  {
        string output, string1;
        this->dio->write("3");
        output = this->dio->read();
        cout << output << endl;
    }


DisplayCommandClient::DisplayCommandClient(DefaultIO *_dio, ClientData *_data, TCPclient _tcpClient): CommandsClient (_dio, _data, _tcpClient){}
/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation: the function gets the classifications from the server and display them on the screen
******************/
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

/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation: the function gets the classifications from the server and download them to file in the path that the user insert
******************/
    void DownloadCommandClient::execute()  {
        thread t;
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
            vector<string> v1;
            cout << output << endl;
            getline(cin, string1);
            v1.push_back(string1);
            output = this->dio->read();
            this->getIO()->write("okay");
            while (output!= "Done.")
               {
                v1.push_back(output);
                output = this->dio->read();
                this->getIO()->write("okay");
                }
            ofstream file;
            // open file in the entered path 
            string myFIle = v1.at(0); 
            // check if the path if with file and insert to him the results
            if (isFile(myFIle)) {   
                t = thread (RunDownload, v1);
                t.detach(); }  
            else {
                // if we got path without text file, we create it
                if (DownloadCommandClient::isValidPath(v1.at(0))) {
                    v1.at(0).append("/results.txt");
                    t = thread (RunDownload, v1);
                    t.detach(); } 
                else {    
                cout << "invalid input" << endl;
            }    
        }
    }
}

bool DownloadCommandClient::isValidPath (string name) {
    struct stat buffer;
    return ((stat(name.c_str(), &buffer) == 0));
}
