#include<queue>
#include<vector>
using namespace std;

/*
Problem statement
You have been given a grid containing some oranges. Each cell of this grid has one of the three integers values:
Value 0 - representing an empty cell.
Value 1 - representing a fresh orange.
Value 2 - representing a rotten orange.
Every second, any fresh orange that is adjacent(4-directionally) to a rotten orange becomes rotten.
Your task is to find out the minimum time after which no cell has a fresh orange. 
If it's impossible to rot all the fresh oranges then print -1.
*/

/*
Time Complexity: O(n × n × 4) In the worst case, every cell in the grid may contain an orange, 
and for each rotten orange we explore 4 directions (up, down, left, right). So we iterate through 
all cells (n × n) and perform 4 operations per orange. Hence, the complexity becomes O(n × n × 4), w
hich simplifies to O(n²).

Space Complexity: O(n × n) In the worst case, all the oranges might be rotten and will be stored in 
the queue simultaneously. The maximum size of the queue can be equal to the total number of oranges in the 
grid, i.e., n × n. Therefore, the space complexity is O(n²).
*/
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // If the grid is empty, return 0 as no oranges exist
    if (grid.empty()) return 0;

    // Variable to store the number of minutes passed
    int days = 0;

    // Variable to store total number of oranges (fresh + rotten)
    int tot = 0;

    // Variable to count how many oranges became rotten during the process
    int cnt = 0;

    // Queue to store positions of currently rotten oranges
    queue<pair<int, int>> rotten; //i,j

     // Traverse the grid to count total oranges and push rotten ones to the queue
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            
            // If the cell is not empty (has fresh or rotten orange)
            if (grid[i][j] != 0)
                tot++; // Count it as a valid orange

            // If it's a rotten orange, add its position to the queue
            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    // Arrays to explore the 4 directions: right, left, down, up
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    //bfs
    while(!rotten.empty())
    {
        // Number of rotten oranges to process at this minute
        int k = rotten.size();

        // Add these many oranges to the count of rotted oranges
        cnt += k;

        // Process all rotten oranges at this time step
        while(k--)
        {
            // Get the front orange from the queue
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            //chk 4 directions
            for(int i = 0; i<4; i++)
            {
                int nx = x + dx[i]; // New x-coordinate
                int ny = y + dy[i]; // New y-coordinate

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                {
                    continue; //if out of bound or not fresh
                }

                // Mark the fresh orange as rotten
                grid[nx][ny] = 2;

                // Add its position to the queue to process in the next minute
                rotten.push({nx, ny});
            }
            
        }

        // If new oranges were added to the queue,fresh->rotten transition
        //occurred so add the transition time
        if (!rotten.empty())
            days++;
    
    }

    // If all oranges are rotted, return total minutes passed
    // Otherwise, some fresh oranges are left unreachable, return -1
    return tot == cnt ? days : -1;
}
