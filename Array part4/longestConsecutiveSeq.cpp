#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#include <unordered_set>

/*
Problem Statement: Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
Input:
 nums = [100, 4, 200, 1, 3, 2]  
Output:
 4  
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. 
*/

/*
Time Complexity: O(n), where n is the number of elements in the array. 
This is because we traverse each element once to build the set and then again to find the longest consecutive sequence.

Space Complexity: O(n), as we use a set to store the unique elements of the array, 
which in the worst case can be equal to the size of the input array.
*/
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> myset;

    // add arr elem to set
    for(int i = 0; i < n; i++)
    {
        myset.insert(arr[i]);
    }

    int longest = 1;
    //traverse set
    for(auto it : myset)
    {
        //is it first num of new sequence
        if(myset.find(it-1) == myset.end())
        {
            //starting of sequence
            int x = it;
            int cnt = 1;

            //find sequence
            while(myset.find(x+1) != myset.end())
            {
                cnt++;
                x = x +1;
            }

            longest = max(longest,cnt);
        }
        
    }

    return longest;
}
int main()
{
    return 0;
}