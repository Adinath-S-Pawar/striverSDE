#include <bits/stdc++.h> 
using namespace std;

/*
Problem statement
You are given a reference/address of a node in a connected undirected graph containing N nodes and M edges. 
You are supposed to return a clone of the given graph which is nothing but a deep copy. 
Each node in the graph contains an integer “data” and an array/list of its neighbours.

The structure of the graphNode class is as follows:
class graphNode 
{  
    public:
        int data;
        vector<graphNode*> neighbours;
}
Note :
1. Nodes are numbered from 1 to N.
2. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
*/

/*
DFS + HashMap
TC - O(V + E) dfs traversal
SC - O(V) map and auxiliary space
*/
	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

graphNode* dfs(graphNode* node,unordered_map<graphNode*, graphNode*>&copies)
{
	// if node present in copies return its clone
	if(copies.find(node) != copies.end())
	{
		return copies[node];
	}

	//create clone
	graphNode* clone = new graphNode(node->data);

	// add in copies, store mapping
	copies[node]=clone;

	//clone all neighbours
	for(auto neighbour : node->neighbours)
	{
		clone->neighbours.push_back(dfs(neighbour,copies) );
	}

	return clone;
}

graphNode *cloneGraph(graphNode *node)
{
    if(node == NULL)return NULL;

	unordered_map<graphNode *,graphNode *>copies;
	return dfs(node,copies);
}