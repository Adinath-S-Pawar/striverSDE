#include<iostream>
using namespace std;
//Problem Statement: Given the root of a Binary Tree, return the preorder, inorder and postorder 
//traversal sequence of the given tree by making just one traversal.

#include<stack>
#include<vector>
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
Time Complexity: O(3*N), we process each node thrice, once for every traversal.
Space Complexity: O(4*N), extra space used for storing postorder, inorder, preorder traversal and stack.
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> pre, inorder, post;

    if (root == NULL) 
    {
            return {};
    }

    stack<pair<TreeNode*,int>> st;

    st.push({root,1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();

        if(it.second == 1)
        {
            // Store the node's data in the preorder traversal
            pre.push_back(it.first->data);

            // Move to state 2 (inorder) for this node
            it.second = 2;
            
            // Push the updated state    
            st.push(it); 

            // Push left child onto the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2)
        {
            // Store the node's data in the inorder traversal
            inorder.push_back(it.first->data);

            // Move to state 3 (postorder) for this node
            it.second = 3;
            
            // Push the updated state    
            st.push(it); 

            // Push right child onto the stack for processing with val 1 because
            // it will also start from preorder
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
                // Store the node's data in the postorder traversal
                post.push_back(it.first->data);
            }

    }

    // Returning the traversals
        vector<vector<int>> result;
        result.push_back(inorder);
        result.push_back(pre);
        result.push_back(post);
        
        return result;

}

int main()
{
    return 0;
}