#include<iostream>
#include<vector>
using namespace std;

/*Problem Statement: Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. 
The sorting must be done in-place, without making a copy of the original array.
*/

/*
Time Complexity: O(n) The array is traversed only once using the `mid` pointer. Each element is checked at most once, 
and swaps are done in constant time.

Space Complexity: O(1) Only a few integer pointers (`low`, `mid`, `high`) are used. Sorting is done in-place, 
requiring no additional space.*/

//dutch national flag algorithm
vector<int> Sort0s1s2s(vector<int> &arr){
	int low = 0, mid = 0, high = arr.size()-1;

	while(mid <= high)
	{
		if(arr[mid] == 0)
		{
			swap(arr[mid],arr[low]);
			low++;
			mid++;
		}
		else if(arr[mid] == 1)
		{
			mid++;
		}
		else// 2
		{
			swap(arr[mid],arr[high]);
			high--;
		}
	}
	return arr;
}