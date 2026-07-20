#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


/*
Time Complexity: O(N), where N is the number of nodes in the Binary Tree. Each node is visited a constant 
number of times while rearranging pointers, so the total work across the entire tree is linear.

Space Complexity: O(1), as the tree is flattened in-place using only a few pointer variables and 
no extra data structures or recursion stack.
*/


//flatten bt to ll
void flattenBinaryTree(node* root)
{
node* curr = root;

        // Iterate until 'curr' becomes NULL
        while (curr)
         {
            // Check if the current node has a left child
            if (curr->left)
            {
                // If yes, find the rightmost node in the left subtree ->predecessor
                node* pre = curr->left;
                while (pre->right)
                {
                    pre = pre->right;
                }

                // Connect currents right subtree to right of predecessor
                //because in preorder left subtree is printed first
                pre->right = curr->right;   //LR

                // Move the entire left subtree to the right child of the current node
                curr->right = curr->left;   //NL

                // Set the left child of the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node on the right side
            curr = curr->right;
        }
}

int main()
{
    return 0;
}