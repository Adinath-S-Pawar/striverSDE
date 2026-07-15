#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an array ‘arr’ of ‘n’ positive integers.
You are also given a positive integer ‘target’.
Your task is to find all unique combinations of elements of array ‘arr’ whose sum is equal to ‘target’. 
Each number in ‘arr’ may only be used once in the combination.
Elements in each combination must be in non-decreasing order and you need to print all unique combinations in 
lexicographical order.
*/

/*
Time Complexity:
Sorting: O(N log N)

Backtracking: O(2^N) in the worst case.
At each index, we can either include or exclude an element,
so the recursion explores a subset tree of size 2^N.

Overall: O(N log N + 2^N)

Space Complexity:
O(N) recursion stack depth in the worst case.

If output storage is included:
O(X * K), where X = number of valid combinations
and K = average length of a combination.
*/

/*
Combination Sum I: recursion depth depends on the target (B/min(arr)) because an element can be chosen unlimited times.
Combination Sum II: each element is used at most once, so recursion depth is at most N, giving a worst-case complexity of O(2^N).
*/
void f(int index, int target,vector<int> &arr,vector<int> &current,
        vector<vector<int>> &result)
{
	//base case
	if(target == 0)
	{
		result.push_back(current);
		return;
	}

	for(int i = index; i < arr.size(); i++)
	{
		//skip duplicate
		if(i > index && arr[i-1] == arr[i]) continue;

		// If the current element is greater than the remaining target, break the loop
        if (arr[i] > target) break;

		//include current elem
		current.push_back(arr[i]);

		//recursive call
		f(i+1,target-arr[i],arr,current,result);

		//pop while returning
        current.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	
	//sort
	sort(arr.begin(),arr.end());

	//valid subsets
    vector<vector<int>>result;

    //current subset
    vector<int> current;

    //index,target,arr,curr,res
    f(0,target,arr, current, result);

    return result;
}
