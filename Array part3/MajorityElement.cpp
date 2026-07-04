/*
Problem Statement: Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. 
The array is guaranteed to have a majority element.
*/

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// TC - O(n) SC - O(n)
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int>numFreq;

	//occurence of each element
	 for (int i = 0; i < n; i++) {
        numFreq[arr[i]]++;
    }

	for(auto pair: numFreq)
	{
		if(pair.second > n/2)
			return pair.first;
	}
	return -1;
}

//approach 2  The Boyer–Moore Majority Vote Algorithm finds the majority element in O(n) time and O(1) extra space.
//If an element appears more than n/2 times, it cannot be completely canceled out by all other elements combined.

int findMajorityElement(int arr[], int n) {
	int elem = -1;
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(count == 0)
		{
			elem = arr[i];
			count = 1;
		}
		else if(arr[i] == elem)
		{
			count++;
		}
		else    //opposition
		{
			count--;
		}
	}

	//verify
	count = 0;
	for (int i = 0; i < n; i++) {
        if (arr[i] == elem)
            count++;
    }

	return (count > n / 2) ? elem : -1;
}