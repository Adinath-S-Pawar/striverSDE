#include<iostream>
using namespace std;
#include <bits/stdc++.h> 

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
    
/*
TC - O(n)
SC - O(1)

Morris Traversal:
- Each edge is traversed at most twice.
- No recursion stack.
- No explicit stack.
- Uses temporary threading and restores the tree.
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> vec;
    TreeNode* current = root;

    while(current != NULL)
    {
        if(current->left == NULL)
        {
            vec.push_back(current->data);
            current = current->right;
        }
        else
        {
            // predecessor
            TreeNode* pred = current->left;

            while(pred->right && pred->right != current)
            {
                pred = pred->right;
            }

            if(pred->right == NULL)
            {   //for preorder push curr
                vec.push_back(current->data); // visit before going left
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                //for inorder curr was pushed here
                current = current->right;
            }
        }
    }

    return vec;
}
int main()
{
    return 0;
}