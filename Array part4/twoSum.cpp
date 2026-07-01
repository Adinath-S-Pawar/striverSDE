#include <algorithm>
#include<vector>
using namespace std;
//the question can be in multiple ways expecting different version of output
/*You are given an array of integers 'ARR' of length 'N' and an integer Target. 
Your task is to return all pairs of elements such that they add up to Target.

Note:
We cannot use the element at a given index twice.*/

//appraoch 1
/*
Time Complexity
Sorting: O(N log N)
Two-pointer traversal: O(N)
Total: O(NlogN)+O(N)=O(NlogN)

Space Complexity: O(N) because we store the array elements along with their original indices in a separate list or vector for sorting, maintaining original positions.


*/
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    vector<pair<int,int>> ans;

    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;

    while(left < right)
    {
        int sum = arr[left] + arr[right];

        if(sum < target)
        {
            left++;
        }
        else if(sum > target)
        {
            right--;
        }
        else
        {
            ans.push_back({arr[left], arr[right]});
            left++;
            right--;
        }
    }

    if(ans.empty())
    {
        ans.push_back({-1, -1});
    }

    return ans;
}

#include <vector>
#include <unordered_map>
using namespace std;

//approach2 TC - O(n)
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    vector<pair<int,int>> ans;
    unordered_map<int,int> freq;

    for(int i = 0; i < n; i++)
    {
        int complement = target - arr[i];

        if(freq.find(complement) != freq.end() && freq[complement] > 0)
        {
            ans.push_back({min(arr[i], complement),
                           max(arr[i], complement)});

            freq[complement]--;   // consume one occurrence
        }
        else
        {
            freq[arr[i]]++;
        }
    }

    if(ans.empty())
    {
        ans.push_back({-1, -1});
    }

    return ans;
}