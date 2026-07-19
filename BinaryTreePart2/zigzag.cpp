#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

/*Problem Statement: Given a Binary Tree, print the zigzag traversal of the Binary Tree. Zigzag traversal of a 
binary tree is a way of visiting the nodes of the tree in a zigzag pattern, alternating between left-to-right and 
right-to-left at each level.*/

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
Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued 
and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant 
time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold 
all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space 
complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes
level by level and hence contains all the nodes of the tree contributing to O(N) space as well.*/
vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }

    queue<node*>q;
    q.push(root);

    bool LeftToRight = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> levelvector(size);

        //process level
        for(int i=0; i<size;i++)
        {
            node* temp = q.front();
            q.pop();
            // if true go with normal flow else reverse flow
            int index = LeftToRight? i : size-1-i;
            levelvector[index] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
        //change direc
        LeftToRight = !LeftToRight;

        for(auto i : levelvector){
            result.push_back(i);
        }

    }
    return result;
}
