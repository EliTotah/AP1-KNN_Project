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


