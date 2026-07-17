#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left= NULL;
        this->right= NULL;
    }

};

/*
TC - O(n)
Traversal visits each node once → O(n)
reverse() on a vector of size n → O(n)
SC - O(n + h) 
for recur n = vec, h = auxilary stack space
for iterative n = vec, h = stack
*/
void preorderHelper(node* root, vector<int>& result)
{
    if(root == NULL)
        return;

    result.push_back(root->data);  // Root
    preorderHelper(root->left, result);   // Left
    preorderHelper(root->right, result);  // Right
}

vector<int> preorder(node* root)
{
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

vector<int> preorder_iter(node* root)
{
    vector<int> result;

    if(root == NULL)
        return result;

    stack<node*> stk;
    stk.push(root);

    while(!stk.empty())
    {
        node* current = stk.top();
        stk.pop();

        result.push_back(current->data);

        // Push right first so left is processed first
        if(current->right)
            stk.push(current->right);

        if(current->left)
            stk.push(current->left);
    }

    return result;
}