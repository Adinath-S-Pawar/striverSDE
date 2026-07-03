#include<iostream>
using namespace std;
#include<vector>
/*
Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
Inversion of an array: for all i & j < size of array, if i < j then you have to find pair 
(A[i],A[j]) such that A[j] < A[i].*/

/*
Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 7
Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1)
 and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition.
*/

//brute force TC- O(n2) SC-O(1)
int numberOfInversions(vector<int>& a, int n) {
    int cnt = 0; // Initialize inversion count
    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++; // Increment count if inversion found
        }
    }
    return cnt; // Return total inversions
}

//using mergesort 
#include <bits/stdc++.h> 
#include<vector>

long long merge(long long *arr,int low, int mid, int high)
{
    //temp to store merged elem
    vector<int> temp;

    int left = low;
    int right = mid+1;

    int cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // All remaining left elements are inversions
            right++;
        }
    }

    // If left half still has elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If right half still has elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return inversion count
    return cnt;
}

long long mergesort(long long *arr,int low, int high)
{
    long long cnt = 0;

    //base case
    if(low >= high) return cnt;

    int mid = (low + high)/2;
    //count inversion in left
    cnt += mergesort(arr,low,mid);
    //right
    cnt += mergesort(arr,mid+1,high);
    //count inversion during merge
    cnt += merge(arr,low,mid,high);

    return cnt;
}

long long getInversions(long long *arr, int n){
    return mergesort(arr,0,n-1);
}


int main()
{
    return 0;
}