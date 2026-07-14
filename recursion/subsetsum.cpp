#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}
/*You are given an array 'nums' of ‘n’ integers.
Return all subset sums of 'nums' in a non-decreasing order.*/

/*
Time Complexity: O(2n),Each element has two choices: include or exclude, leading to 2n subsets. 
We directly compute sums without iterating over subsets, so complexity is O(2n). 
Sorting the sums adds O(2n log(2n)), making the total O(2n log(2n)).

Space Complexity: O(2n),The result array holds all subset sums, requiring O(2n) space. 
Recursion uses an additional O(n) stack space due to function calls, so total auxiliary space is O(2n + n).
*/
void findSum(int index, int currsum, vector<int>& arr, vector<int>& sums)
{
	if(index == arr.size())
	{
		sums.push_back(currsum);
		return;
	}

	//include curr sum
	findSum(index+1,currsum + arr[index] ,arr,sums);

	//do not pick curr elem
	findSum(index+1,currsum ,arr,sums);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;

	findSum(0,0,num,ans);
	
	sort(ans.begin(),ans.end());
	return ans;
}