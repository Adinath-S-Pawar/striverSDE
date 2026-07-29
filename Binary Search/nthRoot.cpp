#include<iostream>
using namespace std;

/*
You are given two positive integers 'n' and 'm'. You have to return the 'nth' root of 'm', i.e. 'm(1/n)'. 
If the 'nth root is not an integer, return -1.
*/

/*
Time Complexity: O(logM), we search for every possible number from 1 to M to check if it is the Nth root.
Space Complexity: O(1), constant additional space is used.

*/
int NthRoot(int n, int m) {
  int low = 1;
  int high = m;

  while(low <= high)
  {
    int mid = (low + high)/2;
    long long ans = 1;

    for(int i = 0; i<n; i++)
    {
      ans *= mid; 
      if(ans > m)break;
    }

    if(ans == m)return mid;

    if(ans < m) low = mid + 1;
    if(ans > m) high = mid - 1;
  }
  return -1;
}

int main()
{
    return 0;
}