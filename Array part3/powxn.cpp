#include<iostream>
using namespace std;

//Problem Statement: Implement the power function pow(x, n) , which calculates the x raised to n i.e. xn.

/*
Time Complexity: O(log n)
Space Complexity: O(1)
*/
double myPow(double x, int n) {
     // handle INT_MIN safely

    long long power = n;  
    if (power < 0) {
        x = 1.0 / x;
        //make power positive
        power = -power; 
    }

    double result = 1.0;

    while (power > 0) {
        if (power & 1) {    
            //and with 1 chks if last bit is ON->odd num
            result *= x;
        }
        //square num
        x *= x; 

        //half the power because number squared
        power= power/2;    
    }

    return result;
}