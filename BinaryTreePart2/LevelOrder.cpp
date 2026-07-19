#include<iostream>
using namespace std;
#include <bits/stdc++.h> 


    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

    /*
Time Complexity: O(n)
Space Complexity: O(n) (queue in the worst case)
    */
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int>ans;

    if(root == NULL) return ans;

    queue<BinaryTreeNode<int> *>q;

    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int> * frontnode = q.front();
        q.pop();

        ans.push_back(frontnode->val);

        if(frontnode->left)
        {
            q.push(frontnode->left);
        }
        if(frontnode->right)
        {
            q.push(frontnode->right);   
        }
    }
    return ans;
}
int main()
{
    return 0;
}