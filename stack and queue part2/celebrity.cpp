#include <bits/stdc++.h> 
using namespace std;
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/

/*
int findCelebrity(int n) {
 	int candidate = 0;

    // Step 1: Find potential celebrity
    for(int i = 1; i < n; i++)
    {
        if(knows(candidate, i))
        {
            // candidate knows i,
            // so candidate cannot be celebrity
            candidate = i;
        }
    }

    // Step 2: Verify candidate

    for(int i = 0; i < n; i++)
    {
        if(i == candidate)
            continue;

        // Celebrity should know nobody
        if(knows(candidate, i))
            return -1;

        // Everybody should know celebrity
        if(!knows(i, candidate))
            return -1;
    }

    return candidate;
}

*/

//when grid given 
/*
Problem Statement: A celebrity is a person who is known by everyone else at the party but does not know 
anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, 
and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 
if no such person exists.
Note that M[i][i] is always 0.
*/

//TC,SC - O(n)

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    // Push all people
    for(int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Find potential celebrity
    while(st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(M[a][b] == 1)
        {
            // a knows b, so a can't be celebrity
            st.push(b);
        }
        else
        {
            // a doesn't know b, so b can't be celebrity
            st.push(a);
        }
    }

    int candidate = st.top();

    // Verify candidate

    // Row check: celebrity knows nobody
    for(int j = 0; j < n; j++)
    {
        if(M[candidate][j] == 1)
        {
            return -1;
        }
    }

    // Column check: everyone knows celebrity
    for(int i = 0; i < n; i++)
    {
        if(i != candidate && M[i][candidate] == 0)
        {
            return -1;
        }
    }

    return candidate;
}
