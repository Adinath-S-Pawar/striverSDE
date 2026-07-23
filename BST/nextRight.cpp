#include <bits/stdc++.h> 
using namespace std;

/*
Given a binary tree, connect the nodes that are at the same level. Given an addition nextRight pointer for the same. 
Initially, all the next right pointers point to garbage values, set these pointers to the point next right for each node.
*/
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *next;


        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
            next = NULL;
        }
    };

    //O(n) Time and O(n) Space

void connectNext(TreeNode<int> *root)
{
    if(root == NULL) return;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        //process level
        for(int i = 0; i<size; i++)
        {
            TreeNode<int>* front = q.front();
            q.pop();

            if(i == size - 1) //last node in level, its next will be null
                front->next = NULL;
            else
                front->next = q.front();    //assign next to next node in level
            
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);

        }
    }
}