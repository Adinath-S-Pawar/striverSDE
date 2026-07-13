#include<iostream>
using namespace std;

/*
You are given a string ('STR') of length 'N'. Find the longest palindromic substring. If there is more than one 
palindromic substring with the maximum length, return the one with the smaller start index.
Note:
A substring is a contiguous segment of a string.
For example : The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the 
longest substring of length 3 which is a palindrome, there is another palindromic substring of length 3 is "bab" 
since "aba" starting index is less than "bab", so "aba" is the answer.
*/

#include <bits/stdc++.h> 

//helper
int expandFromCenter(const string& str, int left, int right) {
        // Expand while characters match and within bounds
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }

/*
Time Complexity: O(N²) For each character, expanding could take up to O(N)
Space Complexity: O(1) No extra space used.
*/
string longestPalinSubstring(string &str)
{
    int start = 0;
    int end = 0;

    //iterate thr each character as center
    for(int center = 0; center<str.length(); center++)
    {
        //expand aroun odd len palindrome
        int oddlen = expandFromCenter(str,center,center);

        //expand aroun even len palindrome
        int evenlen = expandFromCenter(str,center,center + 1);

        int maxlen = max(evenlen,oddlen);

        /*end - start + 1 -> len, ( If there is more than one palindromic substring with the maximum length, return the one with the smaller start index.)
        if we want plaindrome with high start-> maxlen>end-start*/
        if(maxlen > end - start +1)
        {
            start = center - ( (maxlen-1) /2 ); //handles even odd both
            end = center + (maxlen/2);
        }

    }

    return str.substr(start, end-start+1);
}

int main()
{
    return 0;
}