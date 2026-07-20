#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

/*
TC - O(n)
SC  - O(h)
*/

int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if (root == NULL) //base case
    {
        return 0;
    }

    int left = heightOfBinaryTree(root->left); //executes until it gets null
    //then while returning , execute right
    int right = heightOfBinaryTree(root -> right);

    int ans = max(left, right) + 1;

    return ans;
}
