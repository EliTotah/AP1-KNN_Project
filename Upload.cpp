
#include "Upload.h"
using namespace std;

Upload::Upload(DefaultIO *dio, ClientData *data) : Command (dio, data) {
    this->description = "upload an unclassified csv data file";
}

void Upload::execute() {
    string line;
    vector<string> train;
    vector<string> test;
    dio->write("Please upload your local train CSV file.");
    string lineTrain = dio->read();
    this->dio->write("okay");
    while(lineTrain != "end"){
        train.push_back(lineTrain);  
        lineTrain= dio->read();
        this->dio->write("okay");
    }
    this->getData()->setDataBase(train);
    this->getIO()->write("Upload Complete.");
    dio->write("Please upload your local test CSV file.");
    string lineTest = dio->read();
    this->dio->write("okay");
    while(lineTest != "end"){
        test.push_back(lineTest);  
        lineTest= dio->read();
        this->dio->write("okay");
    }
    this->getData()->setNonClassified(test);
    this->getIO()->write("Upload Complete");
    //the file upload
    this->getData()->setFlag();
}
