#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise. 
The rotation must be done in place, meaning the input 2D matrix must be modified directly.

*/

/*Time Complexity: O(N²),We traverse every element once during transposition and again during reversal of each row, 
resulting in a total of O(N²) time.
Space Complexity: O(1),All operations are done in-place using only temporary variables. No extra matrix is used.
*/
void rotateMatrix(vector<vector<int>> &mat){
	int n = mat.size();

	//transpose the matrix
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n;j++)
		{
			swap(mat[i][j],mat[j][i]);
		}
	}

	//reverse each row 
	for(int i = 0; i<n; i++)
	{
		reverse(mat[i].begin(),mat[i].end());
	}
	
}

int main()
{
    return 0;
}