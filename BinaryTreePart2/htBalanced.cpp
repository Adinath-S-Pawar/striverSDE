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
Time Complexity: O(N), where N is the number of nodes in the Binary Tree. Each node is visited exactly once during the postorder traversal.

Space Complexity: O(1), since no extra data structures are used that grow with input size. However, O(H) auxiliary space is used by the recursion stack, where H is the height of the tree. In the best case (balanced tree), H = log₂N; in the worst case (skewed tree), H = N.
*/
int abs_diff_ht(TreeNode<int>* root)
{
    //base case
    if(root == NULL)
    {
        return 0;
    }

    int left = abs_diff_ht(root->left);
    // If the left subtree is unbalanced, propagate the unbalance status
    if(left == -1)
    {
        return -1;
    }

    int right = abs_diff_ht(root->right);
    if(right == -1)
    {
        return -1;
    }
    // If it's greater, the tree is unbalanced, return -1 to propagate the unbalance status
    if(abs(left - right) > 1)
    {
        return -1;
    }
     // Return the maximum height of left and right subtrees
    return max(left,right) + 1;

}



bool isBalancedBT(TreeNode<int>* root){

    if(abs_diff_ht(root) != -1) 
    {
        return true;
    }
    else{
        return false;
    }

    
}