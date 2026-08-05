#include<unordered_map>
#include<list>
#include<vector>
#include<iostream>
using namespace std;

/*
https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
*/

//TC - O(n + e)
/*Complexity	Value
Time	O(V + E)
Space	O(V)*/
bool checkCycleDFS(int node,unordered_map<int,bool> &visited,
  unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>>&adj )
{
  //Has this node ever been visited before in any DFS call? Prevents reprocessing nodes.
    visited[node] = true;
    //Is this node currently in the recursion stack (current DFS path)?
    dfsvisited[node] = true;

    for(auto neighbour : adj[node])
    {
      if(!visited[neighbour])
      {
        bool cycleDetected = checkCycleDFS(neighbour,visited,dfsvisited,adj);
        if(cycleDetected)
        {
          return true;
        }
      }
      else if(dfsvisited[neighbour])
      {
        return true;
      }

    }

    dfsvisited[node] = false; //Remove node from recursion stack.
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
{
    // create adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }  

     //call dfs for all components
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool cyclefound =checkCycleDFS(i,visited,dfsvisited,adj);
            if(cyclefound)
            {
              return true;
            }
                
        }
    }
    return false;
}

int main()
{
    return 0;
}