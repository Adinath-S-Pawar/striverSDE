#include<vector>
using namespace std;
#include<algorithm>

/*
Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. 
In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, 
and their sum is equal to zero.
*/

/*
Time Complexity: O(NlogN)+O(N2), as The pointer i, is running for approximately N times. 
And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates.
So the total time complexity will be O(N2). 

Space Complexity: O(no. of quadruplets), This space is only used to store the answer. 
We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Sort the array
    sort(arr.begin(), arr.end());

    // Store final result
    vector<vector<int>> ans;

    // First loop for first element
    for (int i = 0; i < n; i++) {
        // Skip duplicates for first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        // Two pointers
        int left = i + 1, right = n - 1;

        // Find pairs for current arr[i]
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == 0) 
            {
                ans.push_back({arr[i], arr[left], arr[right]});
                left++, right--;

                // Skip duplicates for left
                while (left < right && arr[left] == arr[left - 1]) left++;
                
                // Skip duplicates for right
                while (left < right && arr[right] == arr[right + 1]) right--;
            }
            else if (sum < 0) left++;
            else right--;
        }
    }
    return ans;
}
