#include<bits/stdc++.h>
#include<iostream>
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
        this->left = NULL;
        this->right = NULL;
    }
};

/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree.

Space Complexity: O(N) where N is the number of nodes in the Binary Tree to store the boundary nodes of the tree. 
O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the tree is skewed 
and the auxiliary recursion stack space would be stacked up to the maximum depth of the tree, 
resulting in an O(N) auxiliary space complexity.
*/
void traverseLeft(node* root,vector<int>&ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))//null or leaf node
    {
        return; //exit fn
    }

    ans.push_back(root->data);
    if(root->left)
    {
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans); 
        //in the left part there is node in right (direction changes of left part) (not right node of a node of left part)
        //therefore root->right , and the node at right is not leaf node because if condition alreaddy checked
    }
}

void traverseLeaf(node* root,vector<int>&ans)
{
    if(root == NULL)
    {
        return;
    }
    //push leaf nodes
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return; //push only leaf node
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

}

void traverseRight(node* root,vector<int>&ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))//null or leaf node
    {
        return;
    }

    if(root->right)
    {
        traverseRight(root->right,ans);
    }
    else
    {
        traverseRight(root->left,ans);
    }
        //push while returning
        ans.push_back(root->data);

}

vector<int> traverseBoundary(node* root)
{
	// Write your code here.
    vector<int> ans; //store ans data
    if(root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    //left part
    traverseLeft(root->left,ans);

    //leaf node
    //left subtree
    traverseLeaf(root->left,ans);
    //right subtree
    traverseLeaf(root->right,ans);

    //right part in opp direc
    traverseRight(root->right,ans);

    return ans;

}

int main()
{
    return 0;
}