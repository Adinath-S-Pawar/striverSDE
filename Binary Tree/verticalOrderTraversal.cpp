#include <bits/stdc++.h> 
using namespace std;
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

/*
Time Complexity: O(N · log²N), where N is the number of nodes in the binary tree.
The tree is traversed once using BFS, and each node is visited exactly once, contributing O(N).
For every node, an insertion is performed into the nested map structure:
Accessing/inserting into the outer map<int, ...> using hd takes O(log N).
Accessing/inserting into the inner map<int, vector<int>> using level also takes O(log N).

Space Complexity: O(N)
The queue used for BFS stores at most O(N) nodes.
The nested maps and vectors collectively store all N nodes exactly once.
Hence, the auxiliary space required is O(N).
*/
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;

    if(root == NULL) return ans;

    //hd , (level,list of node values)
    map<int,map<int,vector<int>>> nodes;

    //node , (hd, level)
    queue<pair<TreeNode<int>*,pair<int,int>>> q;

    q.push({root,{0,0}});
    //bfs
    while(!q.empty())
    {
        pair<TreeNode<int>*, pair<int,int>> front = q.front();
        q.pop();

        TreeNode<int>* frontnode = front.first;
        int level = front.second.second;
        int hd = front.second.first;

        //push nodeval in map
        nodes[hd][level].push_back(frontnode->data);

        if(frontnode->left)
        {
            q.push({frontnode->left,{hd-1,level+1}});
        }
        if(frontnode->right)
        {
            q.push({frontnode->right,{hd+1,level+1}});
        }
    }

    for(auto it : nodes)    // hd, map<lvl, vector<nodeval> >
    {
        for(auto j : it.second)     // <lvl, vector<nodeval>
        {
            for(auto k : j.second)  // vals in vec
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}