#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

/*
You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among 
all these strings. If there is no common prefix, you have to return an empty string.
A prefix of a string can be defined as a substring obtained after removing some or all characters from the 
end of the string.
For Example:
Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. 
Hence, the answer is “cod”.
*/

/*
Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. 
The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.
Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).
*/
string longestCommonPrefix(vector<string> &arr, int n)
{
    if(arr.empty()) return "";

    //sort alphabetically
    sort(arr.begin(),arr.end());

    //store first and last elem to compare
    string first = arr[0];
    string last = arr[n-1];

    string ans = "";

    //min of len for traversal
    int minLen = min(first.length(),last.length());

    for(int i = 0; i<minLen; i++)
    {
        if(first[i] != last[i])break;
        
        ans += first[i];
    }

    return ans;
}


int main()
{
    return 0;
}