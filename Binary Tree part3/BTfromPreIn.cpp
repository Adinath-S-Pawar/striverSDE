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
TC - O(N) + O(N) = O(N)
Creating the hashmap from inorder traversal: O(N)
Each node is created and processed exactly once during recursion: O(N)
Hashmap lookup for inorder position is O(1) on average.

Space Complexity: O(N) hash map and recursion stack
*/
void createmap(const vector<int>& inorder, unordered_map<int, int>& nodevalToIndex)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        nodevalToIndex[inorder[i]] = i;
    }
}

// Optimized recursive tree construction
TreeNode<int>* solve(const vector<int>& preorder, int& preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int>& nodevalToIndex)
{
    // base case
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }

    // Get the current element from preorder and increment the preorderIndex
    int element = preorder[preorderIndex++];
    TreeNode<int>* root = new TreeNode<int>(element);

    // Get the position of the element in the inorder traversal
    int position = nodevalToIndex[element];

    // Recursively build the left and right subtrees
    root->left = solve(preorder, preorderIndex, inorderStart, position - 1, nodevalToIndex);
    root->right = solve(preorder, preorderIndex, position + 1, inorderEnd, nodevalToIndex);

    return root;
}
TreeNode<int>* buildBinaryTree(const vector<int>& inorder, const vector<int>& preorder)
{
    unordered_map<int, int> nodevalToIndex;
    createmap(inorder, nodevalToIndex); // Creating map only once

    int preorderIndex = 0;
    return solve(preorder, preorderIndex, 0, inorder.size() - 1, nodevalToIndex);
}
int main()
{
    return 0;
}