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

//creation
node* buildtree(node* root)
{
    cout<<"enter the data "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1) //base condition, i.e no node to left
    {
        return NULL;
    }

    cout<<"enter the data to the left of "<<data<<endl; //recursion
    root->left = buildtree(root->left);

    cout<<"enter the data to the right of "<<data<<endl;
    root->right = buildtree(root->right);

}

/*
Time Complexity: O(n), where n is the number of nodes.
Auxiliary Space Complexity: O(h), where h is the height of the binary tree.
*/
void inorder(node* root)
{
    //base class
    if(root == NULL){
        return;
    }
    //recursion
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

/*
Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
Space Complexity: O(h), where h is the height of the binary tree. This is the space required for the stack to store the nodes during traversal.
*/
void inorder_iter(node* root)
{
    stack<node*>stk;
    node* current = root;
    vector<int> vec;

    while (true)
    {
        if(current != NULL)
        {
            stk.push(current);
            current = current->left;
        }
        else{

            if(stk.empty())
            {
                break;
            }

            current = stk.top();
            int val = current->data;
            cout<<val<<" ";
            vec.push_back(val);
            stk.pop();
            current = current->right;

        }
    }
    

}

int main()
{
    return 0;
}