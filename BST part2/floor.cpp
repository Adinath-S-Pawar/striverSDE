#include<iostream>
using namespace std;
/*
Problem Statement: Given a Binary Search Tree and a key, return the floor of the given key in the Binary 
Search Tree.
Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or 
equal to the given key. If the floor node does not exist, return nullptr.
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
Time Complexity: O(log2N), where N is the number of nodes in the Binary Search Tree. 
The complexity is equivalent to the height of the tree.

Space Complexity: O(1), since the algorithm does not use any additional space or data structures.
*/
int floorInBST(TreeNode<int> * root, int X)
{
            int floor = -1;
            while(root != NULL)
            {
                if(X == root->val)
                {
                    floor = root->val;
                    break;
                }
                else if(X > root->val)
                {
                    floor = root->val;
                    root = root->right;
                }
                else if(X < root->val)
                {
                    root = root->left;
                }
    
            }
     
        return floor;
}