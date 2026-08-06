#include<queue>
#include<bits/stdc++.h>
using namespace std;

/*
You are given a 2-dimensional array/list having N rows and M columns, which is filled with 
ones(1) and zeroes(0). 1 signifies land, and 0 signifies water.
A cell is said to be connected to another cell, if one cell lies immediately next to the other cell, 
in any of the eight directions (two vertical, two horizontal, and four diagonals).
A group of connected cells having value 1 is called an island. Your task is to find the number of 
such islands present in the matrix.
*/

/*
   TC - O(n*m)
   SC - O(n*m)  Visited array,Queue
*/

void bfs(int row, int col,int totalrow, int totalcol,
         int** arr, vector<vector<int>> &vis )
{
   int n = totalrow;
   int m = totalcol;

   vis[row][col] = 1;

   queue<pair<int,int>>q;
   q.push({row,col});

   while(!q.empty())
   {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      //mark neighbours vis if it is land
      //neighbours -> 1 row,col up,down,left,right,diagonals -> -1 to 1 += r,c index
      for(int delrow = -1; delrow <= 1; delrow++)
      {
         for(int delcol = -1; delcol <= 1; delcol++)
         {
            int newrow = row + delrow;
            int newcol = col + delcol;

            if(newrow >= 0 && newrow < n && 
               newcol >=0 && newcol < m &&
               arr[newrow][newcol] == 1 && !vis[newrow][newcol]
            )
            {
               vis[newrow][newcol] = 1;
               q.push({newrow,newcol});
            }
         }
      }
   }

}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>> vis(n, vector<int>(m,0));
   int cnt = 0;

   for(int row = 0; row < n; row++)
   {
      for(int col = 0; col <m; col++)
      {
         // if not visited and is land
         if(!vis[row][col] && arr[row][col] == 1)
         {
            cnt++;
            bfs(row,col,n,m,arr,vis);
         }
      }
   }
   return cnt;
}
