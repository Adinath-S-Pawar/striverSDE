#include <bits/stdc++.h> 
#include<vector>
using namespace std;

/*Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day. 
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the 
future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve 
any profit, return 0.*/

// TC - O(n)  SC-O(1)
int maximumProfit(vector<int> &prices){
    int minPrice = INT_MAX;
    int maxprofit = 0;

    for(int price : prices)
    {
        if(price < minPrice)
            minPrice = price;
        else
            maxprofit = max(maxprofit, price - minPrice);

    }
    return maxprofit;
}