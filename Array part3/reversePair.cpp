#include<iostream>
using namespace std;
/*Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. 
Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
*/

//brute
#include <bits/stdc++.h> 
int reversePairs(vector<int> &arr, int n){
	int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > 2 * arr[j]) cnt++;
        }
    }
    return cnt;	
}

#include <bits/stdc++.h> 
/*
Time Complexity: O(2N*logN), Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. 
Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half 
once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.*/
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;   

    //storing elements in the temporary array in a sorted manner

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr,int low,int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for(int i = low; i<= mid; i++)
    {
        while(right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        cnt += ( right - (mid + 1) );
    }
    return cnt;
}

int mergesort(vector<int> &arr,int low, int high)
{
    int cnt = 0;
    if(low >= high) return cnt;

    int mid = (low + high)/2;
    cnt += mergesort(arr,low,mid); //left
    cnt += mergesort(arr,mid + 1,high); //right
    cnt += countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

int reversePairs(vector<int> &arr, int n){
	return mergesort(arr,0,n-1);
}

int main()
{
    return 0;
}