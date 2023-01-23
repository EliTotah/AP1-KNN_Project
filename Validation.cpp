// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#include "Validation.h"

using namespace std;
/******************
* Function Name: OverSize
* Input: vector <double>, vector <double>.
* Output: int -0 if false, 1 - true.
* Function Operation:The function checks if the vector length is not over 300 numbers,
 * if it is the function return false - 0.
******************/
int OverSize(vector<double>& v1, vector<double>& v2) {
    if (v1.size() > 300 || v2.size() > 300) {
        return false;
    }
    return true;
}

/******************
* Function Name: len
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the two vectors have the same length,
 * otherwise we cannot calculate the distance between them.
******************/
int len(vector<double>& v1, vector<double>& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    return true;
}

/******************
* Function Name: ValidCharForTwoVectors
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the vectors contain only digits without except for special characters,
 * which are valid. for example: "." , "+" , "-" , " " .
******************/
int ValidCharForTwoVectors(vector<double>& vector1, vector<double>& vector2) {
    if (ValidChar(vector1) && ValidChar(vector2)) {
        return true;
    }
    return false;
}

/******************
* Function Name: ValidCharForString
* Input: string vector1
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the vectors contain only digits without except for special characters,
 * which are valid. for example: "." , "+" , "-" , " " .
******************/
int ValidCharForString(string vector1) {
    int i;
    //checks for vector number1
    for (i = 0; i < vector1.size(); i++) {
        // the valid characters
        if ((vector1[i] >= '0' && vector1[i] <= '9') ||
            (vector1[i] == '.') || (vector1[i] == ' ') ||
            (vector1[i] == '+') || (vector1[i] == ',') || 
            (vector1[i] == '-') || (vector1[i] =='e') || (vector1[i] == 'E')) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

/******************
* Function Name: ValidChar
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the vectors contain only digits without except for special characters,
 * which are valid. for example: "." , "+" , "-" , " " .
******************/
int ValidChar(vector<double>& vector1) {
    bool only_digits_and_spaces = true;
    for (double c : vector1) {
        if (std::isnan(c) && c != ' ' && c != '.' && c != '+' && c != '-') {
            only_digits_and_spaces = false;
            break;
        }
    }
    return only_digits_and_spaces;
}

/******************
* Function Name: ValidateAll
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation: This function is the function that generalizes all the correctness checks regarding the vectors
* and performs a check on the correctness of the input.
******************/
int ValidateAll(vector<double>& v1, vector<double>& v2) {
    if (OverSize(v1,v2) && len(v1,v2)) {
        return true;
    }
    return false;
}

/******************
* Function Name: stringToVector
* Input: string string1.
* Output: int - 0 if false, 1 - true.
* Function Operation: This function takes a string as an input and converts it into a vector of doubles, 
* and check if this vector is valid, i.e. check that all the elements in the vector are numbers.
******************/

int stringToVector (string string1) {
    int result=0, flag = 0;
    double number1;
    string word1;
    vector<double> v1;
    stringstream iss1(string1);
    //read number by number from the vector that entered by the user.
    while (getline(iss1, word1, ',')) {
        //correctness check in order to check that correct numbers have indeed been inserted into the vector.
        //An attempt to convert the string from the user into numbers as long as it is a valid number.
        //In case it is a normal number, insertion of a number into a vector
        try {
                number1 = stod(word1);
                v1.push_back(number1);
            }
        catch (exception e) {
            break;
        }
    }
    // verify that the vector is valid and not empty
    if (ValidChar(v1) == 1 && !(v1.empty())) {
        return true;
    }
    return false;     
}


