#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node,int visited[],
stack<int> &st, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    for(auto it : adj[node])
    {
        if(!visited[it])
        {
            dfs(it,visited,st,adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    // adjacency list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int vv=edges[i][1];
        adj[u].push_back(vv);
    } 
    
    int vis[v] = {0};
    stack<int> st;

    for(int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,st,adj);
        }
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

// kahns algo 
// SC - O(n) queue  TC - O(e + v)
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int vv=edges[i][1];
        adj[u].push_back(vv);
    } 

    int Indegree[v] = {0};
    for(int i = 0; i < v; i++)
    {
        for(auto it : adj[i])
        {
            Indegree[it]++;
        }
    }

    queue<int> q;

    for(int i = 0; i<v; i++)
    {
        if(Indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node])
        {
            Indegree[it]--;
            if(Indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{
    return 0;
}