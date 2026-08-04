#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std; 

/*
Time Complexity	O(V + E)
Space Complexity (including graph storage)	O(V + E)
Auxiliary Space (excluding output)	O(V)
*/

//O(V)+O(E)=O(V+E)
void dfs(int node,unordered_map<int,bool>& visited,
unordered_map<int, list<int>> &adj,vector<int>& component)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
        }
    }
}
    
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // adjacency list
    /*  for adj list 
        Time Complexity: O(E)
        Space Complexity: O(V+E) for storing the adjacency list.
    */
    unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++) 
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dfsans;
    unordered_map<int,bool>visited;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(i,visited,adj,component);
            dfsans.push_back(component);
        }
    }

    return dfsans;

}

int main()
{
    
    return 0;
}