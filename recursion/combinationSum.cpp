#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.
Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.
Elements in each combination must be in non-decreasing order.
*/

/*
Time Complexity:
Sorting: O(N log N)
Backtracking: Exponential, approximately O(2^(B/m) in the worst case. m-> min elem of arr. (B/m)->The maximum depth of recursion
The number of recursive calls is exponential in the worst case

Space Complexity: O(k * x) to store all valid combinations, where x is the number of combinations and k is their average length.
*/
void f(int index, int target,vector<int> &ARR,vector<int> &current,
        vector<vector<int>> &result )
{
    if(index == ARR.size())
    {
        if(target == 0)
        {
            result.push_back(current);
        }
        return;
    }

    //pick the element
    if(ARR[index] <= target)
    {
        current.push_back(ARR[index]);

        //recursive call for same index since one elem can be taken mul times
        f(index,target - ARR[index], ARR, current, result);

        //pop while returning
        current.pop_back();
    }

    //not pick
    f(index + 1, target, ARR, current, result);

}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    //Elements in each combination must be in non-decreasing order.
    sort(ARR.begin(),ARR.end());

    //valid subsets
    vector<vector<int>>result;

    //current subset
    vector<int> current;

    //index,target,arr,curr,res
    f(0,B,ARR, current, result);

    return result;
}
int main()
{
    return 0;
}