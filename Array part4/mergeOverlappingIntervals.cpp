#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping 
intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]

Input : [[1,4],[4,5]]
Output :  [[1,5]]
*/

/*
Time Complexity: O(N*logN) + O(N), we sort the entire array and then merge them in a single pass.
Space Complexity: ON), additonal space used to store the non-overlapping intervals.*/

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>> merged;

	//sort intervals
	sort(arr.begin(),arr.end());	//based on 1st elem of pair

	for(auto interval : arr)
	{
		//if not overlapping add in merged
		if(merged.empty() || merged.back()[1] < interval[0])
		{
			merged.push_back(interval);
		}
		else
		{
			//overlapping
			merged.back()[1] = max(merged.back()[1], interval[1]);
		}
	}

	return merged;
	
}

int main()
{
    return 0;
}