#include<iostream>
#include<unordered_map>
using namespace std;

/*
Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
Space Complexity: O(1), since we use a fixed-size map for Roman numerals.
*/

int romanToInt(string s) {
    int res = 0;

        // Map of Roman numerals to their integer values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        // Iterate through the string, except the last character
        for (int i = 0; i < s.size() - 1; i++) {
            // Subtract if current numeral is less than the next
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                // Otherwise, add the current value
                res += roman[s[i]];
            }
        }

        // Add the value of the last character
        return res + roman[s.back()];
}
int main()
{
    return 0;
}