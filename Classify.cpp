
#include "Classify.h"

Classify:: Classify (DefaultIO *dio, ClientData *data) : Command (dio, data){
    this->description = "classify data";
}

void Classify:: execute(){
    if (this->getData()->getFlag() !=1){
        this->getIO()->write("please upload data");
        return;
    }
    string string1;
    //stringstream iss(string1);
    vector<string> test = this->getData()->getNonClassified();
    vector <string> classi1;
    double number1;
    string word, type;
    //Reading lines by line from the file into string1
    // where each time the string will store the relevant line from the Excel file
    //read number by number from the vector that entered by the user.
        //correctness check in order to check that correct numbers have indeed been inserted.
    for (int i=0; i < test.size(); i++){
        vector<double> v1;
        string word = test[i];
        stringstream iss(word);
        string num;
        //if (ValidCharForString(word)) {
            while(getline(iss, num, ',')) {
            try {
                //An attempt to convert the string from the user into numbers as long as it is a valid number.
                //In case it is a normal number, insertion of a number into a vector.
                number1 = stod(num);
                v1.push_back(number1);
                } catch (exception e) {
                    this->getIO()->write("Invalid data-1");
                    return;
                }
            } /*} else {
                this->getIO()->write("Invalid data-2---valid");
                return;
                }*/
        //A call to the KNN algorithm whose function is to classify the vector entered by the user
        // using the K nearest neighbors algorithm.
        vector<string> dataBase = this->getData()->getDataBase();
        int k = this->getData()->getK();
        string type = this->getData()->getMetrica();
        Knn knn1(v1, k, type,dataBase);
        string result = knn1.KnnProcess();
        //if (result == "invalid input"){
          //  this->getIO()->write("Invalid data-3");
            //return;
        //}
        classi1.push_back(result);
    }
    this->getData()->setClassified(classi1);
    this->getIO()->write("classifying data complete");
}