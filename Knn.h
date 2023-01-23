// Eli Totah - 209186014
// Ofir Rothchild - 207434960

#ifndef UNTITLED_KNN_H
#define UNTITLED_KNN_H

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <functional>
#include "Validation.h"
#include "Distance.h"
#include <bits/stdc++.h>
using namespace std;
//Distance.cpp Knn.cpp Validation.cpp TCPServer.cpp TCPclient.cpp Command.cpp DownloadCommand.cpp DisplayCommand.cpp Upload.cpp Setting.cpp DefaultIO.cpp StandardIO.cpp ClientData.cpp CLI.cpp Classify.cpp
class Knn {
public:
    Knn(vector<double>& v1, int k, string& DistanceType, vector<string> file);
    ~Knn() = default;
    string KnnProcess();

private:
    int k;
    vector<double> v1;
    string DistanceType;
    vector<string> file;
    /******************
    * Function Name: calculateDistance
    * Input: vector <double>, vector <double>.
    * Output: int -0 if false, 1 - true.
    * Function Operation: calculate the distance between the input vector and the classified vectors
    * according to the Metrica from the user.
    ******************/
    double calculateDistance (vector <double>& v2);
    /******************
    * Function Name: CreateVectorOfDistance
    * Input: vector <double>, vector <double>.
    * Output: vector<pair<double, string>> while the double is the distance and the string is the type of the object.
    * Function Operation: the function generates a vector of distances from the vector that the user entered
    and the vectors that we created from the received data.
    the function enters the distances into a new vector of pairs where the value is the distance of type double
    and the string is the type of the object according to the data.
    ******************/
    vector<pair<double, string>> CreateVectorOfDistance ();
    /******************
    * Function Name: calculateDistance
    * Input: vector <double>, vector <double>.
    * Output: int -0 if false, 1 - true.
    * Function Operation: calculate the distance between the input vector and the classified vectors
    * according to the Metrica from the user.
    ******************/
    vector<pair<double, string>> SortDistancesVector (vector<pair<double, string>> DistancesVector);
    /******************
    * Function Name: DefineType
    * Input: vector<pair<double, string>> , int.
    * Output: void.
    * Function Operation: The function receives the vector of pairs of distances and strings and the number K
    * and returns the mostly type of the K nearest vectors that the user entered.
    ******************/
    string DefineType (vector<pair<double, string>> DistancesVector);
};

#endif //UNTITLED_KNN_H
