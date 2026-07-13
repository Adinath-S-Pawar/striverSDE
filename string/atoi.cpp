#include<iostream>
using namespace std;

/*
Problem Statement: Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:
1. Whitespace: Ignore any leading whitespace (" ").
2. Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3. Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the 
string is reached. If no digits were read, then the result is 0.
4. Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain 
in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should 
be rounded to 231 - 1.*/

/*
Time Complexity: O(N), where N is the length of the string.
Space Complexity: O(1), as constant space is used.
*/

int createAtoi(string s) {
     int i = 0, sign = 1;
         // Use long to handle overflow
        long res = 0;

        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') i++;

        // Return 0 if only spaces are found
        if (i == s.size()) return 0;

        // Check for optional '+' or '-' sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // Convert characters to integer while valid digits
        while (i < s.size() && isdigit(s[i])) {
            //Shift the current number one digit to the left and append the new digit
            //characters are stored as ascii
            //s[i] - '0' -> '5' - '0' = 53 - 48 = 5
            res = res * 10 + (s[i] - '0');

            // Clamp to INT_MAX if overflow occurs
            if (sign * res > INT_MAX) return INT_MAX;

            // Clamp to INT_MIN if underflow occurs
            if (sign * res < INT_MIN) return INT_MIN;

            i++;
        }

        // Return final result after applying sign
        return (int)(sign * res);
}
int main()
{
    return 0;
}