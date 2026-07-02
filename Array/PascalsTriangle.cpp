#include <bits/stdc++.h>
#include<vector>
using namespace std;
/*
Problem Statement: Write a program to generate Pascal's triangle. In Pascal’s triangle, each number is the 
sum of the two numbers directly above it 
*/

/*
Time Complexity: O(N^2), we generate all the elements in first N rows sequentially one by one.
Space Complexity: O(N^2), additional space used for storing the entire pascal triangle.*/
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> triangle;

  for(int i = 0; i < n; i++)
  { //Create a row with size (i+1) and initialize all elements to 1
    vector<long long int>row(i+1,1);

    //fill middle values
    for(int j = 1; j < i; j++)  // inner loop doesnt exe for i = 0,1
    {
      row[j] = triangle[i-1][j-1] + triangle[i-1][j];
    }

    triangle.push_back(row);
  }
  return triangle;
}
