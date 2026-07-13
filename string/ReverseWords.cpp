#include<iostream>
#include<algorithm>
using namespace std;

/*
Problem Statement: Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ).
 A word is defined as a sequence of non-space characters. The words in s are separated by at least one space. 
 Return a string with the words in reverse order, concatenated by a single space.

 Input: s = "welcome to the jungle"
Output: "jungle the to welcome"
*/

//appraoch 1 
string reverseString(string &str){
	
	 reverse(str.begin(),str.end());
        string ans = "";

        for(int i = 0; i < str.length(); i++)
        {
            string word = "";
            while(i<str.length() && str[i] != ' ')
            {
                word += str[i];
                i++;
            }

            reverse(word.begin(),word.end());
            if(word.length() > 0)
            {
                ans += " " + word;
            }
        }
        if(ans.length() == 0)
        {
            return "";
        }
        return ans.substr(1); //leave 1st white space

}

//method2 without creating temporary words

/*
Time Complexity: O(N), We traverse the string once from right to left and construct the result directly without 
extra passes.
Space Complexity: O(1),Ignoring the output string, no additional data structures proportional to input size are used.
*/
 string reverseWords(string s) {
        // Result string to store final output
        string result = "";
        
        // Pointer starting from the last character
        int i = s.size() - 1;
        
        // Traverse string from right to left
        while (i >= 0) {
            // Skip spaces at the current position
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            
            // If pointer is out of bounds, break
            if (i < 0) break;
            
            // Mark the end of the current word
            int end = i;
            
            // Move left until a space or start of string is found
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            // Extract the current word
            string word = s.substr(i + 1, end - i);
            
            // Add space before appending next word if result is not empty
            if (!result.empty()) {
                result += " ";
            }
            
            // Append the word to the result
            result += word;
        }
        
        return result;
    }

int main()
{
    return 0;
}