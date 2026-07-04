#include<iostream>
using namespace std;
/*
Problem Statement: Given two integers m and n, representing the number of rows and columns of a 2d array named matrix. 
Return the number of unique ways to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]).
*/

//tabulation method 
#include <bits/stdc++.h> 

//TC - O(mn) SC- O(mn)
int uniquePaths(int m, int n) {
    
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    
}

//space optimised 
// TC - O(mn) SC - O(n)
  int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
                /*
                dp[j] = value from the row above
                dp[j-1] = value from the left in the current row
                */
            }
        }

        return dp[n - 1];
    }
/*
Start:      [1 1 1 1]
Row 2:      [1 2 3 4]
Row 3:      [1 3 6 10]
*/
int main()
{
    return 0;
}