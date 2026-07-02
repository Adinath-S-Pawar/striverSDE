#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1 and it should be done in-place.
Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.*/

/*Time Complexity: O(N+M), we traverse both the arrays exactly once.
Space Complexity: O(1), constant extra space is used to store pointers.*/
class Solution {
public:
    // Merges nums2 into nums1 in-place in sorted order.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // i points to last valid element in nums1
        int i = m - 1;

        // j points to last element in nums2
        int j = n - 1;

        // k is the last index of nums1 (including 0 placeholders)
        int k = m + n - 1;

        // Fill nums1 from the end by comparing nums1[i] and nums2[j]
        while (i >= 0 && j >= 0) {
            // Place larger of the two at nums1[k]
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 has remaining elements, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to copy remaining nums1 elements, as they are already in place
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;

    Solution().merge(nums1, m, nums2, n);

    // Print merged array
    for (int num : nums1) cout << num << " ";
    return 0;
}
