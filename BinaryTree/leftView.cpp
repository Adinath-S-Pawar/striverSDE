#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
Time Complexity: O(N) In the worst case, we may visit every node in the binary tree exactly once. 
This happens when the tree is skewed (i.e., every node has only one child), effectively forming a linear structure. 
Hence, the time complexity becomes O(N), where N is the total number of nodes in the tree.

Space Complexity: O(H),The space complexity depends on the height (H) of the binary tree due to the recursion 
stack in depth-first traversal (like preorder, inorder, postorder). In a balanced binary tree, 
the height is log₂N, leading to O(log N) space. However, in the worst case (a skewed tree), 
the height is N, resulting in O(N) space. So the space complexity is O(H), where H is the height of the tree.
*/
void solve(BinaryTreeNode<int>*root,vector<int>&ans,int level)
{
   if(root == NULL)
    {
        return;
    }  
    //every level stores only one node ans
    // new level entered 
     if(level == ans.size() )
    {
        ans.push_back(root->data);
        
    }
    solve( root->left,ans,level+1);
    solve( root->right,ans,level+1);

}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    vector<int>ans;
   solve(root,ans,0);

    return ans;

}