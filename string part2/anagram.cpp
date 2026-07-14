#include<iostream>
using namespace std;

/*
You are given two strings 'str1' and 'str1'.
You have to tell whether these strings form an anagram pair or not.
The strings form an anagram pair if the letters of one string can be rearranged to form another string.
Pre-requisites:
Anagrams are defined as words or names that can be formed by rearranging the letters of another word.
 Such as "spar" can be formed by rearranging letters of "rasp". Hence, "spar" and "rasp" are anagrams. 
*/

/*
Time Complexity: O(N), where N is the length of the strings. Each string is traversed once, and the frequency array is checked in constant time (26 iterations).
Space Complexity: O(1), as a fixed-size array of 26 elements is used regardless of the input size.
*/
//the input str has only lower case
bool isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length()) 
        return false;

    // Initialize a frequency array to store character counts
    int freq[26] = {0};

    // Count frequency of each character in str1
    for (int i = 0; i < str1.length(); i++) {
        freq[str1[i] - 'a']++;  // Increment frequency for each character in str1
        freq[str2[i] - 'a']--;  // Decrement frequency for each character in str2

    }

    // Check if all frequencies are zero, meaning both strings have the same characters
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0)  // If any frequency is non-zero, they are not anagrams
            return false;
    }

    return true;  // The strings are anagrams
}

int main()
{
    return 0;
}