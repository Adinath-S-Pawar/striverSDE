#include <bits/stdc++.h> 
using namespace std;

/*
Problem Statement: Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. 
The Children Sum Property in a binary tree states that for every node, the sum of its children's values 
(if they exist) should be equal to the node's value. If a child is missing, it is considered as having a value of 0.
Note:
The node values can be increased by any positive integer any number of times, but decrementing any node 
value is not allowed.
A value for a NULL node can be assumed as 0.
We cannot change the structure of the given binary tree.
*/

template<typename T>
    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

    /*
Time Complexity: O(N), where N is the number of nodes in the binary tree. This is because the algorithm 
traverses each node exactly once, performing constant-time operations at each node.
Space Complexity: O(N), where N is the number of nodes in the Binary Tree.
    */
void changeTree(BinaryTreeNode < int > * root) {
    
    if(root == NULL) return;

    //sum of child
    int childSum = 0;

    if(root->left)
        childSum += root->left->data;
    if(root->right)
        childSum += root->right->data;
    
    //if childsum more than parent update parent
    if(childSum >= root->data)
    {
        root->data = childSum;
    }
    else
    {
        //childsum less than parent , assign parents value of any one child
        if(root->left)
            root->left->data = root->data;
        else if(root->right)
            root->right->data = root->data;
    }

    //Recursively process left and right subtrees.
    changeTree(root->left);
    changeTree(root->right);

    //calculate sum of children while going back
    int total = 0;
    if (root->left) 
        total += root->left->data;
    if (root->right) 
        total += root->right->data;

    //assign that value to parent if child exist
    if(root->left || root->right)
        root->data = total;
        
}  