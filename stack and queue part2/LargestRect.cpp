#include <vector>
#include <stack>
using namespace std;
/*
Problem Statement: Given an array of integers heights representing the histogram's bar height where the width 
of each bar is 1 return the area of the largest rectangle in histogram. .
*/

//optimal
int largestRectangle(vector<int>& heights)
{
    int n = heights.size();

    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] >= currHeight)
        {
            int currIndex = st.top();
            int height = heights[currIndex];
            st.pop();

            int nse = i;                    // Next Smaller Element index
            int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element index

            int width = nse - pse - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    return maxArea;
}

//brute

#include<vector>
#include<stack>

vector < int > next_smaller_elem_index(vector<int> & heights, int n) //TC-O(n)
{
    // Write your code here.
    stack <int> stk;
    stk.push(-1);
    vector<int>ans(n);
    for(int i = n-1 ; i>=0; i--)
    {  int curr = heights[i];
        while(stk.top() != -1 && heights[stk.top()] >= curr)
        {
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(i);
    }
    return ans;
}

vector<int> prev_smaller_elem_index(vector<int> &heights, int n) //TC-O(n)
{
    // Write your code here.
    stack <int> stk;
    stk.push(-1);
    vector<int>ans(n);
    for(int i = 0 ; i<n; i++)
    {  int curr = heights[i];
        while(stk.top() != -1 && heights[stk.top()] >= curr)
        {
            stk.pop();
        }
        ans[i] = stk.top();
        stk.push(i);

    }
    return ans;
}


int largestRectangle(vector<int>& heights) {
    // Write your code here.
        int area = 0;
        int n = heights.size();

        vector<int> next(n);
        vector<int> prev(n);

        next = next_smaller_elem_index(heights,n);
        prev = prev_smaller_elem_index(heights,n);

        for(int i = 0; i<n; i++)
        {
            int l = heights[i];
         
            if(next[i] == -1) //height of all bars same
            {
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
}


