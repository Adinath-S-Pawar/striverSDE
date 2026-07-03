#include<iostream>
using namespace std;
#include <bits/stdc++.h>

/*
Problem Statement: Given an integer array nums of size n containing values from [1, n] and each value appears 
exactly once in the array, except for A, which appears twice and B which is missing.*/

/*Time Complexity: O(2*N),  This is because we are iterating through the array once to build the 
hash array and then iterating through the hash array to find the repeating and missing numbers.
Space Complexity: O(N), as we are using an additional hash array of size N+1 to store the frequency of each element.*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// hash array to count occurence
	int hasharr[n+1] = {0};

	for(int i = 0; i < n; i++)
	{
		hasharr[arr[i]]++;
	}

	// find repeating and missing
	int repeating = -1, missing = -1;

	for(int i = 1; i<=n; i++)
	{
		if(hasharr[i] == 2)
		{
			repeating = i;
		}
		else if(hasharr[i] == 0)
		{
			missing = i;
		}
		//break if both found
		if(repeating != -1 && missing != -1)
		{
			break;
		}
	}

	return{missing,repeating};
}

//optimal 

#include <bits/stdc++.h>
using namespace std;
/*Time Complexity: O(N)
Space Complexity: O(1), */

class Solution {
public:
    // Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // Size of the array
        long long n = nums.size(); 

        // Sum of first n natural numbers
        long long SN = (n * (n + 1)) / 2;
        
        // Sum of squares of first n natural numbers
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        /*Calculate actual sum (S) and sum 
        of squares (S2) of array elements*/
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        //Compute the difference values
        long long val1 = S - SN; 
        
        // S2 - S2n = X^2 - Y^2
        long long val2 = S2 - S2N; 

        //Calculate X + Y using X + Y = (X^2 - Y^2) / (X - Y)
        val2 = val2 / val1;

        /* Calculate X and Y from X + Y and X - Y
         X = ((X + Y) + (X - Y)) / 2
         Y = X - (X - Y)*/
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        // Return the results as {repeating, missing}
        return {(int)x, (int)y};
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
