#include<iostream>
using namespace std;
#include <bits/stdc++.h> 

/*
You are given a binary tree with ‘N’ nodes.
Your task is to find the “Maximum Path Sum” for any path.
Note :
1. A ‘path’ is a sequence of adjacent pair nodes with an edge between them in the binary tree.
2. The ‘path’ doesn’t need to pass through the root.
3. The ‘path sum’ is the sum of the node’s data in that path. 
*/
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
/*
Time Complexity: O(N), each node is processed once in DFS Traversal.
Space Complexity: O(H), auxiliary stack space, where H is height of Binary Tree.
*/
int solve(TreeNode<int>* root,int &ans)
{
    if(root == NULL) return 0;

    //ignore negative to reduce path sum
    int left = max(0,solve(root->left,ans) );
    int right = max(0, solve(root->right,ans) );

    ans = max(ans,left + right + root->val );

    return root->val + max(left,right);
}

int maxPathSum(TreeNode<int>* root)
{
	int ans = INT_MIN; //negative val pr
    solve(root,ans);
    return ans;
}

int main()
{
    return 0;
}