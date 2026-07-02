#include<iostream>
using namespace std;
#include <bits/stdc++.h>

/*Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. 
Assuming there is only one duplicate number, your task is to find the duplicate number.
*/

/*
Time Complexity: O(N), This is because we traverse the array at most twice 
(once to find the intersection and once to find the duplicate).

Space Complexity: O(1), */

int findDuplicate(vector<int> &arr, int n){
	int slow = arr[0];
	int fast = arr[0];
	//move slow by 1 fast by 2
	do
	{	//when slow = fast -> loop guaranteed
		slow = arr[slow];
		fast = arr[arr[fast]];
	}while(slow != fast);

	//reset fast
	fast = arr[0];

	//move by 1 when they meet it is duplicate elem
	while(slow != fast)
	{
		slow = arr[slow];
		fast = arr[fast];
	}

	//duplicate
	return slow;

}

int main()
{
    return 0;
}