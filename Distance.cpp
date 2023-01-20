// Eli Totah - 209186014
// Ofir Rothchild - 207434960
#include <vector>
#include <cmath>
#include <string>
#include "Distance.h"

using namespace std;

/******************
* Function Name: MinkowskiDistance
* Input: vector <double>, vector <double> , double p - while this is a default value.
* Output: double - the Minkowski Distance between the two vector.
* Function Operation:The function calculates the Minkowski distance between two vectors using the above calculation:
 * Minkowski distance (x,y) = (sum from {i=1}^n (the vector size) |x_i-y_i|^p)^{1/p} while the default p value is 2.
******************/
double MinkowskiDistance(vector <double>& v1, vector <double>& v2, double p)
{
    double answer = 0, temp;
    int i;
    // this loop calculates the sum from 1 to the vector size
    for(i = 0; i < v1.size(); i++){
        temp = pow(fabs(v1[i]-v2[i]),p);
        answer += temp;
    }
    // the sum is power by 1/p
    return pow(answer,(1/p));
}

/******************
* Function Name: ChebyshevDistance
* Input: vector <double>, vector <double>.
* Output: double - the Chebyshev Distance between the two vector.
* Function Operation:The function calculates the Chebyshev distance between two vector using the above calculation:
 * Chebyshev distance (x,y) = the maximum value of |x_i-y_i|.
******************/
double ChebyshevDistance(vector <double>& v1, vector <double>& v2) {
    double MaxVal = 0;
    int i;
    // two loop for two vector
    for(i = 0; i < v1.size(); i++){
        if (fabs(v1[i]-v2[i]) > MaxVal) {
            MaxVal = fabs(v1[i]-v2[i]);
        }
    }
    return MaxVal;
}
/******************
* Function Name: EuclideanDistance
* Input: vector <double>, vector <double>.
* Output: double - the Euclidean Distance between the two vector.
* Function Operation:The function calculates the Euclidean distance between two vector using the MinkowskiDistance,
 * while the p value is 2. hte calculation is the same.
******************/
double EuclideanDistance(vector <double>& v1, vector <double>& v2) {
    //the p value is 2
    return MinkowskiDistance(v1, v2,2);

}
/******************
* Function Name: ManhattanDistance
* Input: vector <double>, vector <double>.
* Output: double - the  Manhattan Distance between the two vector.
* Function Operation:The function calculates the  Manhattan distance between two vector using the MinkowskiDistance,
 * while the p value is 1. hte calculation is the same except of the p value that have change.
******************/
double ManhattanDistance(vector <double>& v1, vector <double>& v2) {
    //the p value is 1
    return MinkowskiDistance(v1, v2,1);
}

/******************
* Function Name: CanberraDistance
* Input: vector <double>, vector <double>.
* Output: double - the Canberra Distance between the two vector.
* Function Operation:The function calculates the Canberra distance between two vector using the above calculation:
 * Canberra distance = Σ |Ai-Bi| / (|Ai| + |Bi|)
******************/
double CanberraDistance(vector <double>& v1, vector <double>& v2) {
    double sum = 0, temp;
    int i;
    for(i = 0; i < v1.size();i++){
        temp = (fabs(v1[i]-v2[i]))/(fabs(v1[i])+ fabs(v2[i]));
        sum += temp;
    }
    return sum;
}
/******************
* Function Name: ValidDistance
* Input: string- metrica type
* Output: int - true if it valid metrica name, false if it is un-valid metrica.
* Function Operation: The function goes through an array and checks whether the string the user entered
  is indeed a valid name of one of the metrics for calculating the distance.
  If so, the function will return true otherwise, it will return false
******************/
int ValidDistance (string word){
    vector<string> distances = {"MIN", "CAN", "CHB", "MAN", "AUC"};
    for (auto & distance : distances) {
        if (word == distance){
            return 1;
        }
    }
    return 0;
}

