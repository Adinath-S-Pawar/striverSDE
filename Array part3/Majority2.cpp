#include<iostream>
using namespace std;
#include <bits/stdc++.h>

/*
Time Complexity: O(N * logN), where N is the size of the given array. For using a map data structure,
where insertion in the map takes logN time, and we are doing it for N elements.
Space Complexity: O(N) for using a map data structure.
*/
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size(); 
        
    // list of answers
    vector<int> result; 
    
    unordered_map<int, int> mpp;
    
    // least occurrence of the majority element
    int mini = int(n / 3) + 1;
    
    // storing the elements with its occurrence
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        
        // checking if nums[i] is the majority element
        if (mpp[arr[i]] == mini) {
            result.push_back(arr[i]);
        }
        
        // if result size is equal to 2 break out of loop
        if (result.size() == 2) {
            break;
        }
    }
        
        // return the majority elements
        return result;

}

//TC- O(n) SC- O(1)
vector<int> majorityElementII(vector<int> &arr)
{
// Size of the array
        int n = arr.size(); 

        // Counts for elements el1 and el2
        int cnt1 = 0, cnt2 = 0;
        
        int el1 = INT_MIN, el2 = INT_MIN;

        /*Boyer Moore's Voting Algorithm*/
        for (int i = 0; i < n; i++) {
            
            if (cnt1 == 0 && el2 != arr[i]) {
                cnt1 = 1;
                // Initialize el1 as nums[i]
                el1 = arr[i]; 
            }
            else if (cnt2 == 0 && el1 != arr[i]) {
                cnt2 = 1;
                // Initialize el2 as nums[i]
                el2 = arr[i]; 
            } 
            else if (arr[i] == el1) {
                cnt1++;
            } 
            else if (arr[i] == el2) {
                cnt2++; 
            } 
            else {
                cnt1--; 
                cnt2--;
            }
        }

        //Validate the candidates by counting occurrences in nums
        //Reset counts for el1 and el2
        cnt1 = 0, cnt2 = 0; 
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == el1) {
                cnt1++; 
            }
            if (arr[i] == el2) {
                cnt2++;
            }
        }

        int mini = n / 3 + 1;
        
        // List of answers
        vector<int> result; 

        if (cnt1 >= mini) {
            result.push_back(el1);
        }
        if (cnt2 >= mini && el1 != el2) {
            result.push_back(el2); 
        }


        return result;

}

int main()
{
    return 0;
}