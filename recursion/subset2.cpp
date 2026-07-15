#include<iostream>
using namespace std;
#include <bits/stdc++.h> 

/*
Problem Statement: Given an integer array nums, which can have duplicate entries, provide the power set. 
Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.
*/

/*
Time Complexity: O(2^N),In the worst case (all unique elements), we generate all possible subsets, which is 2^N. 
Sorting takes O(N log N), so total complexity is O(2^N + N log N) ≈ O(2^N).

Space Complexity: O(N) ,Due to recursion depth and storage of the current subset in the call stack. 
The output storage is O(2^N) for all subsets.
*/
void backtrack(int index,vector<int> &arr, vector<int>&current,
vector<vector<int>> &result  )
 {
     //add current subset
     result.push_back(current);

    for(int i = index; i< arr.size(); i++)
    {
        //skip duplicate
        if(i > index && arr[i] == arr[i-1]) continue;

        //include curr elem in curr subset
        current.push_back(arr[i]);

        //recurse for next elem
        backtrack(i+1,arr, current,result );

        //pop last elem while going from curr (backtrack)
        current.pop_back();
    }
 }

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    //sort so duplicates are adjacent
    sort(arr.begin(),arr.end());

    //all valid subsets
    vector<vector<int>>result;

    //current subset
    vector<int> current;
    //index,arr,curr,res
    backtrack(0,arr,current,result);

    return result;
}

int main()
{
    return 0;
}