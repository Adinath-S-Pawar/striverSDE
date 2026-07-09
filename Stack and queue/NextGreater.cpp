#include<iostream>
using namespace std;
#include<stack>
#include<vector>
/*
Time Complexity: O(N), we traverse the entire array once and find next greater element in linear time.
Space Complexity: O(N), additional space used for resultant array and stack.
*/
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	stack<int>stk;
	vector<int>res(n);

	//traverse from right to left
	for(int i = n-1; i>=0; i--)
	{
		//pop smaller or equal elems from stack 
		while(!stk.empty() && (stk.top() <= arr[i]))
		{
			stk.pop();
		}

		//if stk empty no greater elem at right
		if(stk.empty())
		{
			res[i] = -1;
		}
		else 
		{
			//greater elem at stack top
			res[i] = stk.top();
		}

		//push curr elem in stk
		stk.push(arr[i]);
		
	}
	return res;
}

int main()
{
    return 0;
}