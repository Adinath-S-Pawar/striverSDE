#include <bits/stdc++.h>
#include<vector>
using namespace std;

/*
Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of 
the elements present in that subarray.
*/

/*Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.
Space Complexity: O(1). We use a constant amount of space for variables.*/
long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long maxi = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum > maxi)
            maxi = sum;
        
        //reinitialize
        if(sum < 0)
            sum = 0;
        
    }
    return maxi;
}

//followup - print subarray

class Solution {
public:
    // Function to find maximum sum of subarrays and print the subarray having maximum sum
    int maxSubArray(vector<int>& nums) {
        
        // maximum sum
        long long maxi = LLONG_MIN; 
        
        // current sum of subarray
        long long sum = 0;
        
        // starting index of current subarray
        int start = 0; 
        
        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1; 
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            
            // update starting index if sum is reset
            if (sum == 0) {
                start = i;
            }
            
            // add current element to the sum
            sum += nums[i]; 
            
            /* Update maxi and subarray indice
            s if current sum is greater*/
            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            
            // Reset sum to 0 if it becomes negative
            if (sum < 0) {
                sum = 0;
            }
        }
        
        // Printing the subarray
        cout << "The subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        
        // Return the maximum subarray sum found
        return maxi;
    }
};

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    // Create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubArray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;

    return 0;
}