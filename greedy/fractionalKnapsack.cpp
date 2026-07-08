#include<iostream>
using namespace std;
/*
You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.
Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.
Note:
You are allowed to break the items.
Example:
If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. 
The total value of knapsack = 3 + 6 + 4 = 13.00   
*/

//Time Complexity: O(N log N) + O(N) = O(N log N)
// SC - O(1) (or O(log N) if counting the stack used internally by std::sort)

#include <bits/stdc++.h> 

static bool comparator(const pair<int,int>&a, const pair<int,int>&b)
{
    //val to wt ratio
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;

    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.

    //sort based on value/wt ratio max->min
    sort(items.begin(),items.end(),comparator);

    double ansValue = 0.0;

    for(int i = 0; i<n && w>0; i++)
    {
        int weight = items[i].first;
        int value = items[i].second;

        //if wt less than capacity add to ans
        if(weight <= w)
        {
            ansValue += value;
            w -= weight;
        }
        else
        {
            //fractional part
            ansValue += (double)value/weight * w;
            break;
        }
    }

    return ansValue;
}

int main()
{
    return 0;
}