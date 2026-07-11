#include <bits/stdc++.h> 
using namespace std;

/*
Given an array/list of integers of length ‘N’, there is a sliding window of size ‘K’ which moves from the beginning 
of the array, to the very end. You can only see the ‘K’ numbers in a particular window at a time. For each of the 
'N'-'K'+1 different windows thus formed, you are supposed to return the maximum element in each of them, from the 
given array/list.
*/

/*
Time Complexity: O(n) Each element is pushed and popped from the deque at most once, so overall traversal is linear.
Space Complexity: O(k) Deque stores at most k elements at any time, one for each index in the window.
*/
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i< n; i++)
    {
        //remove elem out of window range from front
        if(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        // Remove all elements from the back that are smaller than current element
        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);

        // Once the first window is completed, add front element to result
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
    }

    return ans;
}