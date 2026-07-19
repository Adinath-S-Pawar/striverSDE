#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

/*
TC - O(n)
SC  - O(h)
*/
int heightOfBinaryTree(TreeNode<int> *root, int &diameter) {
    // Base case: if the node is NULL, return height 0
    if (root == NULL) {
        return 0;
    }

    // Recursively compute the height of the left and right subtrees
    int leftHeight = heightOfBinaryTree(root->left, diameter);
    int rightHeight = heightOfBinaryTree(root->right, diameter);

    // The diameter at the current node is the sum of the left and right subtree heights
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current node
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root) {
    int diameter = 0;  // To store the largest diameter found
    heightOfBinaryTree(root, diameter);  // Compute the diameter using heightOfBinaryTree
    return diameter;
}
