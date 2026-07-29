#include<bits/stdc++.h>
using namespace std;
/*
You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, 
which appears only once. Return the number that appears once.*/

/*
Time Complexity: O(logN), N = size of the given array ,as we are basically using the Binary Search algorithm.
Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();

	if(n == 1) return arr[0];

	//edge cases for first and last elem
	if(arr[0] != arr[1])return arr[0];
	if(arr[n-1] != arr[n-2])return arr[n-1];

	int low = 1;
	int high = n-2;

	while(low <= high)
	{
		int mid = (low + high)/2;

		//chk if mid is unique
		if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) 
		{
            return arr[mid];
        }

		 // If mid is in the left half (pairing is valid)
		if( (mid % 2 == 0 && arr[mid] == arr[mid + 1]) || 
			(mid % 2 == 1 && arr[mid] == arr[mid - 1])	)
		{
			low = mid + 1;
		}
		// If mid is in the right half (pairing broken earlier)
        else {
            // Move to the left half
            high = mid - 1;
        }
	}
	return -1;
}

int main()
{
    return 0;
}