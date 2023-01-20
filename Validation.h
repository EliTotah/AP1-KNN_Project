// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef PROJECT1___OFIR_AND_ELI_VALIDATION_H
#define PROJECT1___OFIR_AND_ELI_VALIDATION_H

#include <vector>
#include <cmath>
#include <cctype>
#include <type_traits>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/******************
* Function Name: OverSize
* Input: vector <double>, vector <double>.
* Output: int -0 if false, 1 - true.
* Function Operation:The function checks if the vector length is not over 300 numbers,
 * if it is the function return false - 0.
******************/
int OverSize(vector<double>& v1, vector<double>& v2);

/******************
* Function Name: len
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the two vectors have the same length,
 * otherwise we cannot calculate the distance between them.
******************/
int len(vector<double>& v1, vector<double>& v2);

/******************
* Function Name: ValidCharForTwoVectors
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the vectors contain only digits without except for special characters,
 * which are valid. for example: "." , "+" , "-" , " " .
******************/
int ValidCharForTwoVectors(vector<double>& vector1, vector<double>& vector2);

/******************
* Function Name: ValidChar
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the vectors contain only digits without except for special characters,
 * which are valid. for example: "." , "+" , "-" , " " .
******************/
int ValidChar(vector<double>& vector1);

/******************
* Function Name: ValidCharForString
* Input: string vector1
* Output: int - 0 if false, 1 - true.
* Function Operation:The function checks if the vectors contain only digits without except for special characters,
 * which are valid. for example: "." , "+" , "-" , " " .
******************/
int ValidCharForString(string vector1);

/******************
* Function Name: ValidateAll
* Input: vector <double>, vector <double>.
* Output: int - 0 if false, 1 - true.
* Function Operation: This function is the function that generalizes all the correctness checks regarding the vectors
* and performs a check on the correctness of the input.
******************/
int ValidateAll(vector<double>& v1, vector<double>& v2);

#endif
