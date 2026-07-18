#include <bits/stdc++.h> 
using namespace std;

    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};

/*
Time Complexity: O(N), where N is the number of nodes in the binary tree as each node of the binary tree is 
visited exactly once in the inorder traversal.
Space Complexity: O(N), additional stack space used for recursion and space for storing the path.
*/
bool findPath(TreeNode<int> *root,vector<int> &ans,int x)
{
	 // If current node is NULL, return false
	if (!root) {
		return false;
	}

	// Add current node's value to the path
    ans.push_back(root->data);

	// If current node's value is equal to x, return true
	if (root->data == x) {
		return true;
	}

	//Recursively search in left or right subtree
	if(findPath(root->left,ans,x) || findPath(root->right,ans,x))
	{
		return true;
	}

	// If not found, backtrack and remove current node
	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;

	if(root == NULL) return ans;

	findPath(root,ans,x);

	return ans;
}
