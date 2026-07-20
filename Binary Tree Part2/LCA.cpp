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
Time Complexity: O(N), where N is the number of nodes in the binary tree. 
In the worst case, we may need to traverse all nodes to find the LCA.

Space Complexity: O(H), where H is the height of the binary tree. This is due to the recursive stack space 
used during the traversal. In the worst case, for a skewed tree, H can be equal to N, but for a balanced tree,
H will be log(N).
*/
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root == NULL)
    {
        return -1;
    }
    if(root->data == x || root->data == y )
    {
        return root->data;
    }

    int leftans = lowestCommonAncestor(root->left,x,y);
    int rightans = lowestCommonAncestor(root->right,x,y);

    if(leftans != -1 && rightans != -1)
    {
        return root->data;
    }
    else if(leftans != -1 && rightans == -1)
    {
        return leftans;
    }
    else if(leftans == -1 && rightans != -1)
    {
        return rightans;
    }
    return -1;

}





