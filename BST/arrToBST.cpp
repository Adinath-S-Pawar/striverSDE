#include <bits/stdc++.h> 
using namespace std;

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

//creating height balanced instead of skew

/*
Time Complexity - O(n)
Space Complexity - O(log n) (auxiliary space)
*/
TreeNode<int>* buildBST(vector<int>& arr, int start, int end)
{
    if(start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    buildBST(arr,0,n-1);
}