/*
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the 
lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange to the lowest possible order 
(i.e., sorted in ascending order).
Input: Arr[] = {1,3,2}
Output: {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. 
So, the next permutation just after {1,3,2} is {2,1,3}.
Input : Arr[] = {3,2,1}
Output: {1,2,3}
Explanation : As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. 
So, we have to return the lowest permutation.*/

#include <bits/stdc++.h> 
#include <vector>
using namespace std;

/*
Time Complexity: O(N), we find the breaking point and reverse the subarray in linear time.
Space Complexity: O(1), constant additional space is used.
*/

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int breakpointindex = -1;

    // Find the first decreasing element from end (brk pt)
    for(int i = permutation.size()-2; i >=0 ; i--)
    {
        if(permutation[i] < permutation[i+1])
        {
            breakpointindex = i;
            break;
        }
            
    }

    if(breakpointindex == -1)
    {   //reverse entire arr if no brkpt
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }

    // Find element just greater than brkptnum
    for(int i = permutation.size()-1; i >=0; i--)
    {
        if(permutation[i] > permutation[breakpointindex])
        {
            swap(permutation[i],permutation[breakpointindex]);
            break;
        }
    }

    //reverse part ahead of brkpt
    reverse(permutation.begin()+breakpointindex+1, permutation.end());

    return permutation;
}

