
#include "Setting.h"

Setting:: Setting (DefaultIO *dio, ClientData *data) : Command (dio, data){
    this->description = "algorithm setting";
}
/******************
* Function Name: execute
* Input: void
* Output: void
* Function Operation:The function The function performs the process that this command performs in accordance with the exercise definitions.
 This function is a load for the execute function defined in the abstract class command
******************/
void Setting:: execute(){
    //creates a stringstream object ss and stores the current settings of the k and distance metric using the getters from the data object
    int k;
    string distance;
    stringstream ss;
    string user_input;
    //create a stringstream object to store the current settings in a string
    ss << "the current KNN parameters are: k = " << this->getData()->getK();
    ss << ", distance metric = " << this->getData()->getMetrica();
    //converts the stringstream object to a string and stores it in the variable result.
    string result = ss.str();
    //calls the write function of the dio object to write the current settings to the user.
    dio->write(result);
    //calls the read function of the dio object to get the user input for the new settings.
    user_input = dio->read();
    //check if the user input is empty
    if (user_input == "\0") {
        this->getIO()->write("enter");
        return;
    }
    //creates an istringstream object iss and a vector of strings parameters to store the user input
    istringstream iss(user_input);
    string token;
    string msg;
    vector<string> parameters;
    //uses getline method to tokenize the user input and store the tokens in the parameters vector.
    //split the user input into tokens using ' ' as a delimiter
    while (getline(iss, token, ' ')) {
        parameters.push_back(token);
    }
    //checks if the number of parameters entered is 2, if not it writes "Expected 2 parameters" and returns.
    if (parameters.size() != 2) {
        this->getIO()->write("Expected 2 parameters");
        return;
    }
    // check if the first parameter is a valid integer. If it's not it appends "invalid value for K" to the msg variable.
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
    //assigns the second parameter from the user input to the distance variable
    distance = parameters[1];
    // checks if the distance variable is valid using the ValidDistance function, if it's not it appends "invalid value for metric" to the msg variable
    if (!ValidDistance(distance)){
    msg.append("invalid value for metric"); 
    }
    //calls the write function of the dio object to write the error messages if any.
    this->getIO()->write(msg);
    //calls the setSettings function of the data object to set the new values of k and distance.
    this->getData()->setSettings(k, distance);
    }
