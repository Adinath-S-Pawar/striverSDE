#include<bits/stdc++.h>
using namespace std;

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

class info {
public:
    int max;
    int min;
    int size;
    bool isBST;
};
/*
Time	O(n)
Space	O(h)
*/

// Helper function to find the largest BST
info solve(TreeNode *root, int &ans) {
    if (root == NULL) {
        return {INT_MIN, INT_MAX, 0, true};
    }

    // Recursive calls for left and right subtrees
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    // Creating a current node info object
    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.max = max(root->data, right.max);
    currnode.min = min(root->data, left.min);

    // Check if the current tree is a BST
    if (left.isBST && right.isBST && (root->data > left.max && root->data < right.min)) {
        currnode.isBST = true;
        // Update the largest BST size found so far
        ans = max(ans, currnode.size);
    } else {
        currnode.isBST = false;
    }

    return currnode;
}

// Function to find the largest BST
int largestBST(TreeNode *root) {
    int maxsize = 0;
        solve(root, maxsize); // We only need to run the recursion, maxsize will be updated during the recursion.
    return maxsize;
}
