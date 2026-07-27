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


string serializeTree(TreeNode<int> *root)
{
    string s = "";

    if(root == NULL) return s;

    queue<TreeNode<int> *>q;

    q.push(root);

    while(!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();

        if(front == NULL)
        { 
            s += "#,";
        }
        else
        {
            s += to_string(front->data) + ",";

             // Push left child into queue
            q.push(front->left);

            // Push right child into queue
            q.push(front->right);
        }

    }

    return s;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.empty()) return NULL;

    // Use stringstream to parse the input data
    stringstream s(serialized);
    string str;

    // Read the root value from the stream
    getline(s, str, ','); 
    /*
    eg- s "10,20,30" str = "10"
    */

    TreeNode<int>* root = new TreeNode<int>(stoi(str));

    queue<TreeNode<int>*>q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* front = q.front();
        q.pop();

        //left child
        getline(s, str, ','); 

        if(str != "#")
        {
            TreeNode<int>* leftNode = new TreeNode<int>(stoi(str));
            front->left = leftNode;
            q.push(leftNode);
        }

        //right child
        getline(s, str, ','); 

        if(str != "#")
        {
            TreeNode<int>* rightNode = new TreeNode<int>(stoi(str));
            front->right = rightNode;
            q.push(rightNode);
        }

    }
    return root;
}