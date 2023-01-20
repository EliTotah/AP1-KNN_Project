// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "Knn.h"

/**
 * The constructor for the Knn class.
 * @param v1 the main vector
 * @param k the number of Neighbors
 * @param DistanceType the Distance Type
 * @param file the path of the database file
 */
Knn::Knn(vector<double>& v1, int k, string& DistanceType, vector<string> file) {
    this->v1 = v1;
    this->k = k;
    this->DistanceType = DistanceType;
    this->file = file;
}

/******************
* Function Name: CreateVectorOfDistance
* Input: vector <double>, vector <double>.
* Output: vector<pair<double, string>> while the double is the distance and the string is the type of the object.
* Function Operation: the function generates a vector of distances from the vector that the user entered
and the vectors that we created from the received data.
the function enters the distances into a new vector of pairs where the value is the distance of type double
and the string is the type of the object according to the data.
******************/
vector<pair<double, string>> Knn::CreateVectorOfDistance(){
    // the string1 is an empty string for the data from the file
    string type, string1, word;
    double distance;
    //A vector of pairs that the first in the pair is the distance and the second is the string of the closest type.
    vector<pair<double, string>> outputs;
    //Reading lines by line from the file into string1
    // where each time the string will store the relevant line from the Excel file
    for (int i=0; i< this->file.size(); i++) {
        string1 = this->file[i];
        // put string1 to iss1 and iss2 for later use.
        stringstream iss1(string1);
        stringstream iss2(string1);
        vector<double> v2;
        double character;
        char comma;
        // put the first number to the character
        while (iss1 >> character) {
            // while the data is number we enter this to the vector as the first double
            v2.push_back(character);
            //move the comma between the number in iss1 to the string in order to skip to the next number.
            iss1 >> comma;
        }
        // put the last string that is the type of the object to the word by reading each line
        // while ignoring stops until it is a word that is not a number
        while (getline(iss2, word, ',')) {
            type = word;
        }
        //calling to the validation checks on the vectors.
        // validation check
        if(!ValidCharForTwoVectors(this->v1, v2) || !ValidateAll(this->v1,v2)) {
            outputs.clear();
            return outputs;
        }
        //calling to the function that calculate the distance according to the distance type that enter by the user
        distance = Knn::calculateDistance(v2);
        // if the Distance Type that inserted is invalid
        if (distance == -1) {
            outputs.clear();
            return outputs;
        }
        //add the distance of the current vector and his type to the vector of distances
        outputs.emplace_back(distance, type);
    }
    //return the vector of pairs
    return outputs;
}

/******************
* Function Name: SortDistancesVector
* Input: vector <double>.
* Output: vector<pair<double, string>> while the double is the distance and the string is the type of the object.
* Function Operation:sort the array of distance according to the double value of the distance.
******************/
vector<pair<double, string>> Knn::SortDistancesVector (vector<pair<double, string>> DistancesVector){
    //sort the vector of pairs according to the distance values.
    sort(DistancesVector.begin(), DistancesVector.end());
    return DistancesVector;
}

/******************
* Function Name: calculateDistance
* Input: vector <double>, vector <double>.
* Output: int -0 if false, 1 - true.
* Function Operation: calculate the distance between the input vector and the classified vectors
* according to the Metrica from the user.
******************/
double Knn::calculateDistance(vector <double>& v2) {
    //we define the function that we want to set in the pair of the map
    // so that we can call the appropriate metric according to the string that the user entered.
    using Function = function<double(vector<double>& v1, vector<double>& v2)>;
    // Create a map of cases and actions when the action is calling to the appropriate function.
    map<string, Function> actions;
    //the pair that we use to define the key in the map.
    using pairtype = pair<string, Function>;
    //A special case in which we call the function MinkowskiDistance which requires an additional argument
    // which in this case we define as the dipole value that the function can receive.
    if (this->DistanceType == "MIN") {
        double d = MinkowskiDistance(this->v1, v2);
        return d;
    }
    //the action that we want to add to the map according to the string that the user enter.
    actions.insert(pairtype("CHB", ChebyshevDistance));
    actions.insert(pairtype("AUC", EuclideanDistance));
    actions.insert(pairtype("MAN", ManhattanDistance));
    actions.insert(pairtype("CAN", CanberraDistance));
    //find the appropriate string in the map and call to the appropriate action.
    if (actions.find(this->DistanceType) != actions.end()) {
        double d = actions[this->DistanceType](this->v1, v2);
        return d;
    }
        //if the Distance Type that inserted is invalid
    else {
        //cout << "invalid Distance Type ";
        int flag = -1;
        return flag;
    }
}

/******************
* Function Name: DefineType
* Input: vector<pair<double, string>> , int.
* Output: void.
* Function Operation: The function receives the vector of pairs of distances and strings and the number K
* and returns the mostly type of the K nearest vectors that the user entered.
******************/
string Knn::DefineType (vector<pair<double, string>> DistancesVector){
    int i;
    //definition of a map that contains a string that expresses the type of the variable
    //and an int that expresses the number of repetitions of that string.
    map<string, int> map;
    for (i = 0; i <= this->k; ++i) {
        //for the K neighbors we will perform the count of the string for each of the vectors of the data.
        map[DistancesVector[i].second]++;
    }
    string mostFrequentString;
    int MaxCount = 0;
    //for each item in the map we will put the string that repeats the most times and update the return value
    //every time there is a need so that in the end we can return the type of most K neighbors in mostFrequentString.
    for (auto const& item: map) {
        if (item.second > MaxCount) {
            mostFrequentString = item.first;
            MaxCount = item.second;
        }
    }
    //print the type.
    return mostFrequentString;
}

/******************
* Function Name: KnnProcess
* Input: vector <double> , int , string, string.
* Output: void.
* Function Operation:The function summarizes all the Knn process and call to the function that take part in the process.
******************/
string Knn::KnnProcess() {
    //create the vector of distances.
    vector<pair<double, string>> DisVec = Knn::CreateVectorOfDistance();
    // check if there is some problem with the data (vectors in different length, empty file, etc.)
    if (DisVec.empty()) {
        return "invalid input";
    }
    //sort the vector.
    vector<pair<double, string>> SortedVec = Knn::SortDistancesVector(DisVec);
    // check if k is bigger than the size of database and return error
    if (this->k > SortedVec.size()) {
        return "invalid input";
    }
    //define the right type according to the most frequent String of the k neighbors vectors.
    return Knn::DefineType(SortedVec);
}
