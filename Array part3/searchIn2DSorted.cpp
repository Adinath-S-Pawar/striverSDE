#include<iostream>
#include<vector>
using namespace std;
/*
Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the 
number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. 
Moreover, the first element of a row is greater than the last element of the previous row (if it exists). 
You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.*/
/*
Time Complexity: O(log(NxM)), where N = given row number, M = given column number.We are applying binary search on the imaginary 1D array of size NxM.
Space Complexity: O(1) as we are not using any extra space.
*/

bool searchElement(vector<vector<int>> &MATRIX, int target) {
    int n = MATRIX.size();  //rows
    int m = MATRIX[0].size();   //cols

    // Set initial binary search range over the imaginary 1D array
    int low = 0;
    int high = (n*m)-1;

    //binary search
    while(low <= high)
    {
        int mid = (low  + high)/2;

        // Convert mid index to corresponding 2D indices
        int row = mid/m;
        int col = mid%m;

        if(MATRIX[row][col] == target)
            return true;
        else if(MATRIX[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    }

    return false;
}

int main()
{
    return 0;
}
