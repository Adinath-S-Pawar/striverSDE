#include<iostream>
using namespace std; 

//using bfs
/*
https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/

#include<unordered_map>
#include<queue>
#include<list>
#include<vector>

/*
Time Complexity - O(V + E)
Each vertex is visited once.
Each edge is examined at most twice (once from each endpoint in an undirected graph).

Space Complexity - O(V)
Reason:
visited map: O(V)
parent map: O(V)
BFS queue: up to O(V)
*/

bool isCyclicBFS(int src,unordered_map<int,bool> &visited,
              unordered_map<int, list<int> > &adj )
{
    unordered_map<int,int> parent;

    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour  : adj[front])
        {
            if(visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

/*
Time Complexity - O(V + E)
Each vertex is visited exactly once.
Each edge is explored at most twice in an undirected graph (once from each endpoint).

Space Complexity - O(V)
visited map → O(V)
Recursive call stack → O(V) in the worst case (e.g., a chain-like graph)
*/
bool isCyclicDFS(int node, int parent,unordered_map<int,bool> &visited,
              unordered_map<int, list<int> > &adj)
{
    visited[node] = true;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool ans = isCyclicDFS(neighbour,node,visited,adj);
            if(ans)
            {
                return true;
            }
        }
        else if(neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // adjacency list
    unordered_map<int, list<int> > adj;

    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //disconnected component
    unordered_map<int,bool> visited;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            //bool ans = isCyclicBFS(i,visited,adj);
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";

}

int main(){
    
    return 0;
}