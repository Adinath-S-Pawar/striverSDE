#include<iostream>
using namespace std;
#include <bits/stdc++.h> 
/*
Problem Statement: Given a string, S. Find the length of the longest substring without repeating characters.
*/

/*
Time Complexity: O(n), where n is the length of the string. This is because we are using a single pass through the string with two pointers, leading to linear time complexity.

Space Complexity: O(1), as we are using a fixed-size hash array of size 256 (for ASCII characters) and not using any additional data structures that grow with input size.*/
int lengthOfLongestSubstring(string &s) {
 unordered_set<char> st;
    int left = 0, ans = 0;

    for (int right = 0; right < s.size(); right++) {
        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main()
{
    return 0;
}