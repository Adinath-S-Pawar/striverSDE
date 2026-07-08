#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
There are ‘N’ children and ‘M’ cookies.
You are given two arrays, ‘SIZE’, and ‘GREED’, where ‘GREED[i]’ is the greed of ‘ith’ children and 
‘SIZE[j]’ is the size of the ‘jth’ cookie.
You must assign ‘jth’ cookie to ‘ith’ child such that the greed of maximum children is satisfied. 
A child's greed is satisfied if the size of the cookie assigned to him is greater than or equal to his greed.
You must return the maximum number of children whose greed can be satisfied.
*/

/*
Time Complexity: O(n*logn + m*logm), Both the arrays are sorted in increasing order.
Space Complexity: O(1), No extra space is used.
*/

int assignCookie(vector<int> &greed, vector<int> &size) {
	//sort 
	sort(greed.begin(),greed.end());
	sort(size.begin(),size.end());

	int greedIndex = 0;
	int sizeIndex = 0;

	while(greedIndex < greed.size() && sizeIndex < size.size())
	{
		if(greed[greedIndex] <= size[sizeIndex])
		{
			greedIndex++;
		}
		sizeIndex++;
	}

	return greedIndex;
}

int main()
{
    return 0;
}