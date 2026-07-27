#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 };
 
 /*
 Time Complexity: O(N), where N is the number of nodes in the BST. Because the code performs an in-order traversal 
 of the BST,  which requires O(N) time.
Space Complexity: O(N), since the code stores all the node values in a list.
 */
class Solution {
public:
    
    void inorderTraversal(TreeNode* node, vector<int>& values) {
        if (node) {
            inorderTraversal(node->left, values);
            values.push_back(node->data);
            inorderTraversal(node->right, values);
        }
    }
    
    vector<int> kLargesSmall(TreeNode* root, int k) {
        // Vector to store the node values
        vector<int> values;
        // Perform in-order traversal and collect values
        inorderTraversal(root, values);
        
        // Find the kth smallest and kth largest values
        int kth_smallest = values[k - 1];
        int kth_largest = values[values.size() - k];
        
        return {kth_smallest, kth_largest};
    }
};

// Main method to demonstrate the function
int main() {
    // Constructing the tree: [3, 1, 4, null, 2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    
    Solution solution;
    int k = 1;
    vector<int> result = solution.kLargesSmall(root, k);
    
    cout << "[" << result[0] << ", " << result[1] << "]" << endl; // Output: [1, 4]
    
    return 0;
}