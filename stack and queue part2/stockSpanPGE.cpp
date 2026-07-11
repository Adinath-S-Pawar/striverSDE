#include<iostream>
using namespace std;
#include<stack>

/*
Problem Statement: Given an array arr of size n, where each element arr[i] represents the stock price on day i. 
Calculate the span of stock prices for each day.
The span Sᵢ for a specific day i is defined as the maximum number of consecutive previous days 
(including the current day) for which the stock price was less than or equal to the price on day i.
*/

/*
Time Complexity: O(n)
At first glance, it looks like the while loop could make it O(n²), but it doesn't.
Total pushes = n
Total pops   = n

Space Complexity: O(n)
In the worst case, the stack can contain all indices.
*/
//previous greater elem question
void calculateSpan(int prices[], int n, int spans[]) {
    stack<int> stk;

    for(int i = 0; i<n; i++)
    {
        //remove all prev smaller elem
        while(!stk.empty() && (prices[stk.top()] < prices[i]) )
        {
            stk.pop();
        }

        //prev greater elem index
        int pge = stk.empty()? -1 : stk.top();

        //streak
        spans[i] = i - pge;

        stk.push(i);
    }
    
}

int main()
{
    return 0;
}