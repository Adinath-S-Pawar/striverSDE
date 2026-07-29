#include<bits/stdc++.h>
using namespace std;

/*
You are given a row-wise sorted matrix 'mat' of size m x n where 'm' and 'n' are the numbers of rows and 
columns of the matrix, respectively.
Your task is to find and return the median of the matrix.
Note: 'm' and 'n' will always be odd.
*/

/*
total time complexity - O(mlogn⋅log(maxValue−minValue))
*/
int countLess(vector<int>row,int mid) //O(mlogn)
{
    //returns an iterator to the first element greater than mid -> sub from  iterator to 1st
    return upper_bound(row.begin(), row.end(), mid) - row.begin(); //log(n) for each iteration
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = matrix[0][0];
    int high = matrix[0][n-1];

    //find lowest and highest from first and last col
    for(int i = 0; i<m; i++)
    {
        low = min(low,matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }

    while(low < high) //O(log(high−low))
    {
        int mid = (low + high)/2;

        //count elems smaller than mid in entire matrix row by row
        int count = 0;
        for(int i = 0; i<m; i++)
        {
            count += countLess(matrix[i],mid); //row,mid
        }

        if(count < ( (m * n + 1 )/2 ) ) low = mid + 1;
        else high = mid;
    }
    return low;
}