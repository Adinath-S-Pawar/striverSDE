#include <bits/stdc++.h> 
using namespace std;
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

1. Push(num): Push the given number in the stack.
2. Pop: Remove and return the top element from the stack if present, else return -1.
3. Top: return the top element of the stack if present, else return -1.
4. getMin: Returns minimum element of the stack if present, else return -1.
*/
// Implement class for minStack.

class minStack
{
	stack<int> st;
	stack<int> mn; // for min values to handle even after pop
	
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			st.push(num);

			if (mn.empty() || num <= mn.top())
				mn.push(num);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if (st.empty())
            	return -1;

			int x = st.top();
			st.pop();

			if (x == mn.top())
				mn.pop();

			return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if (st.empty())
            	return -1;

        	return st.top();
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if (mn.empty())
            	return -1;

        	return mn.top();
		}
};