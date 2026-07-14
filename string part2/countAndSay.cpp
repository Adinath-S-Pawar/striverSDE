#include <bits/stdc++.h> 
using namespace std;

/*
Problem Statement: The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters 
(repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters 
(length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", 
replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
*/

//Time Complexity: O(n * length of nth term) ≈ O(n * 2^n)
//Space Complexity: O(length of nth term) ≈ O(2^n)
string writeAsYouSpeak(int n) 
{
	string result = "1";

    // Generate the sequence up to the nth term
    for (int i = 1; i < n; ++i) {
        string current = "";
        int count = 1;

        // Traverse the previous result
        for (int j = 1; j < result.size(); ++j) {
            // If current character matches previous, increment count
            if (result[j] == result[j - 1]) {
                count++;
            } else {
                // Append count and character to current result
                current += to_string(count) + result[j - 1];
                count = 1;
            }
        }

        // Append the last group
        current += to_string(count) + result.back();

        // Update result for next iteration
        result = current;
    }

    // Return the final result
    return result;	
}