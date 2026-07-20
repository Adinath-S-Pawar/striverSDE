#include<bits/stdc++.h>
using namespace std;

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

/*
Time Complexity: O(N + M) where N is the number of nodes in the first Binary Tree and M is the number of nodes 
in the second Binary Tree. This complexity arises from visiting each node of both trees during their comparison.

Space Complexity: O(1) as no additional space or data structures are created that are proportional to the 
input size of the tree.
*/
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 

    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if(root1 == NULL && root2 != NULL)
    {
        return false;
    }

    if(root1 != NULL && root2 == NULL)
    {
        return false;
    }
    
    bool left = identicalTrees(root1->left,root2->left);
    bool right = identicalTrees(root1->right,root2->right);

    bool value = root1->data == root2->data;

    if(left && right && value)
    {
        return true;
    }
    else{
        return false;
    }