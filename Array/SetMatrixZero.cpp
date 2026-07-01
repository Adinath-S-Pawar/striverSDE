/*Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and 
row to 0 and then return the matrix..
*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

/*Time Complexity: O(m × n),We iterate over the entire matrix a constant number of times 
Space Complexity: O(1),No extra space is used apart from a few boolean flags; 
*/
void setZeros(vector<vector<int>> &matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	bool firstRowZero = false;
	bool firstColZero = false;

	//chk if 1st row has zero
	for(int i = 0; i < col; i++)
	{
		if(matrix[0][i] == 0)
			firstRowZero = true;
	}
	// chk if 1st col has zero
	for(int i = 0; i < row; i++)
	{
		if(matrix[i][0] == 0)
			firstColZero = true;
	}
	//marks rows and cols in 1st row and col
	for(int i = 1; i < row; i++)	
	{	// i and j from 1 for inner part of matrix
		for(int j = 1; j < col; j++)
		{
			if(matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	//set matrix cell 0 based on marker
	for(int i = 1; i < row; i++)	
	{	
		for(int j = 1; j < col; j++)
		{
			if(matrix[0][j] == 0 || matrix[i][0] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}

	//handle first row
	if(firstRowZero)
	{
		for(int i = 0; i < col; i++)
		{
			matrix[0][i] = 0;
		}
	}

	//handle first col
	if(firstColZero)
	{
		for(int i = 0; i < row; i++)
		{
			matrix[i][0] = 0;
		}
	}
}