#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an integer array nums, sorted in ascending order (with distinct values) 
and a target value k. The array is rotated at some pivot point that is unknown. Find the index at 
which k is present and if k is not present return -1.*/

/*
Time Complexity: O(log N),We eliminate half of the search space in each iteration using binary search.
Space Complexity: O(1),We use only a few variables (low, high, mid) no extra space used.
*/
int search(vector<int>& arr, int n, int k)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // If the target is found at mid, return mid
        if (arr[mid] == k)
            return mid;

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {

            // If target lies in the sorted left half, search there
            if (arr[low] <= k && k < arr[mid]) {
                high = mid - 1;
            }
            // Else search in the right half
            else {
                low = mid + 1;
            }
        }

        // Otherwise, right half is sorted
        else {

            // If target lies in the sorted right half, search there
            if (arr[mid] < k && k <= arr[high]) {
                low = mid + 1;
            }
            // Else search in the left half
            else {
                high = mid - 1;
            }
        }
    }

    // If not found, return -1
    return -1;
}


int main()
{
    return 0;
}