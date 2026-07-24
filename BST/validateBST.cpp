#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };
//tc - O(n) sc - O(logn)

bool solve(BinaryTreeNode<int>* root,int min, int max)
{
    if(root == NULL)return true;

    //chk range
    if(root->data <= min || root->data >= max) return false;

    return solve(root->left,min,root->data) &&
    solve(root->right,root->data,max);

}

bool validateBST(BinaryTreeNode<int>* root) 
{
    int min = INT_MIN;
    int max = INT_MAX;

    return solve(root,min,max);
}