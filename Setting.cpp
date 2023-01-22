
#include "Setting.h"

Setting:: Setting (DefaultIO *dio, ClientData *data) : Command (dio, data){
    this->description = "algorithm setting";
}

void Setting:: execute(){
    int k;
    string distance;
    stringstream ss;
    string user_input;
    ss << "the current KNN parameters are: k = " << this->getData()->getK();
    ss << ", distance metric = " << this->getData()->getMetrica();
    string result = ss.str();
    dio->write(result);
    user_input = dio->read();
    if (user_input == "\0") {
        this->getIO()->write("enter");
        return;
    }
    istringstream iss(user_input);
    string token;
    string msg;
    vector<std::string> parameters;
    while (getline(iss, token, ' ')) {
        parameters.push_back(token);
    }
    if (parameters.size() != 2) {
        this->getIO()->write("Expected 2 parameters");
        return;
    }
    try {
            k = stoi(parameters[0]);
        }
    catch (exception e) {
        //k should be an int
        msg.append("invalid value for K\n");
    }
    if (k < 0 || (floor(k) != k)) {
        msg.append("invalid value for K\n");
    }
    distance = parameters[1];
    //check if the distance is valid
    if (!ValidDistance(distance)){
        msg.append("invalid value for metric");
    }
    this->getIO()->write(msg);
    this->getData()->setSettings(k, distance);
    }
