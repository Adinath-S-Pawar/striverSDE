#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
/*
Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. 
Return all such palindromic partitions of string s. A palindrome string is a string that reads the same backward 
as forward.
*/

/*
Time Complexity: O(2^N * N), we create all possible partitions and check whether they are palindrome or not.
Space Complexity: O(2^N * N) + O(N), additional space used to store all possible results and auxiliary stack space.
In the worst case, every substring is a palindrome. -> O(2^N). Each partition can contain up to N strings.
*/
bool isPalindrome(string &s, int start, int end) {
    
    while (start < end) {
        // If mismatch, not a palindrome
        if (s[start] != s[end]) return false;
        // Move pointers inward
        start++;
        end--;
    }
    // All characters matched
    return true;
}

void f(int index, string &s, vector<string>&valid,vector<vector<string>>&result)
{
    if(index == s.length())
    {
        result.push_back(valid);
        return;
    }

    for(int i = index; i<s.length();i++)
    {   //if str is palindrome add in valid
        if(isPalindrome(s,index,i))
        {
            valid.push_back(s.substr(index,i-index+1)); //from index, how much len

            //recur rem str
            f(i+1,s,valid,result);

            //pop while returning
            valid.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> result;
    vector<string> valid;
    f(0,s,valid,result);

    return result;
}

int main()
{
    return 0;
}