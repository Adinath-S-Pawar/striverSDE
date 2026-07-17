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
SC - O(n + h)
for recur n = vec, h = auxilary stack space
for iterative n = vec, h = stack
*/
void postorderHelper(node* root, vector<int>& result)
{
    if(root == NULL)
        return;

    postorderHelper(root->left, result);    // Left
    postorderHelper(root->right, result);   // Right
    result.push_back(root->data);           // Root
}

vector<int> postorder(node* root)
{
    vector<int> result;
    postorderHelper(root, result);
    return result;
}

vector<int> postorder_iter(node* root)
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

        // Push left first so right is processed first
        if(current->left)
            stk.push(current->left);

        if(current->right)
            stk.push(current->right);
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    return 0;
}