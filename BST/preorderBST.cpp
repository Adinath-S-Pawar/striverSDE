#include <bits/stdc++.h> 
using namespace std;
//Problem Statement: Given a preorder traversal of a binary search tree. Return the root of the Binary Search Tree
// constructed from the given preorder array.

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
/*
Time Complexity: O(N), Each node is processed once while constructing the BST.
Space Complexity: O(H), Stack space for recursion, where H is the height of the tree.
*/
TreeNode* solve(vector<int> &preOrder,int min,int max,int &i)
{
    //last element
    if(i >= preOrder.size()) return NULL;

    //out of range
    if(preOrder[i] < min || preOrder[i] > max)return NULL;

    //value in range
    TreeNode* root = new TreeNode(preOrder[i++]);
    root->left = solve(preOrder, min, root->data,i);
    root->right = solve(preOrder,root->data,max,i);

    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;

    return solve(preOrder,min,max,i);
}