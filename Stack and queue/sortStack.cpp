#include <bits/stdc++.h> 
using namespace std;

/*
Time Complexity: O(n2), where n is the number of elements in the stack.
Space Complexity: O(n), due to the recursion stack.
*/
void insertsorted(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() <= num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    insertsorted(stack, num);
    
    stack.push(n);
}


void sortStack(stack<int> &stack)
{  // base case
	if(stack.empty())
	{
		return;
	}

     	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	insertsorted(stack, num);

}