#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

/*
Time Complexity: O(log N),Each step eliminates half of the tree, just like binary search. However, 
in the worst case (unbalanced tree), it could be O(N).

Space Complexity:O(1),Iterative solution uses constant space as no recursion stack is involved.    
*/
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> * temp = root;
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            return true;
        }
        if(temp->data > x)
        {
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return false;
}