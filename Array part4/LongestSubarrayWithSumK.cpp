/*Problem statement
You are given an array 'a' of size 'n' and an integer 'k'.
Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]
Output: 3*/

#include<iostream>
#include<vector>
using namespace std;
//Time Complexity: O(N), where N is the size of the array. The algorithm traverses the array once with two pointers,
//making it linear in time complexity.

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;
    int maxLength = 0;
    long long sum = a[0];

    while(right < a.size())
    {
        //if sum exceeds k shrink window
        while(left<= right && sum > k)
        {
            sum -= a[left];
            left ++;
        }

        if(sum == k)
        {
            maxLength = max(maxLength,right-left+1);
        }

        right++;
        sum += a[right];
    }

    return maxLength;
}