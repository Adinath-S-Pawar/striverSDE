#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given a Binary Tree, determine whether the given tree is symmetric or not. 
A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. 
If we were to draw a vertical line through the centre of the tree, the nodes on the left and right side would 
be mirror images of each other.
*/

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };
/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each 
node exactly once during the traversal and the function compares the nodes in a symmetric manner.

Space Complexity: O(1) as no additional data structures or memory is allocated.
*/
bool isMirror(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if(root1 == NULL && root2 == NULL)return true;

    //if only 1 null -> mismatch
    if(root1 == NULL || root2 == NULL) return false;

    return((root2->data == root1->data) &&
            isMirror(root1->left,root2->right) &&
            isMirror(root1->right,root2->left));
}


bool isSymmetric(TreeNode<int> *root)
{
    if(root == NULL) return true;

    return isMirror(root->left, root->right);

}