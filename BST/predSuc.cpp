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

//tc - O(h) sc - O(1)
node* minval(node* root)
{
    node* temp = root;
    while(temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* maxval(node* root)
{
    node* temp = root;
    while(temp != NULL && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

pair<int, int> predecessorSuccessor(node *root, int key)
{
    // Write your code here.
    int pred = -1;
    int suc = -1;


    node *temp = root;

while(temp != NULL) {
        if(temp->data == key) {
            
            if(temp->left != NULL) {
                node* leftSubtree = temp->left;
                pred = maxval(leftSubtree)->data;
            }

            // Successor: Minimum value in right subtree
            if(temp->right != NULL) {
                node* rightSubtree = temp->right;
                suc = minval(rightSubtree)->data;
            }
            break;
        }
        else if(temp->data > key) {
            suc = temp->data;  // Current node is a potential successor
            temp = temp->left;
        }
        else {
            pred = temp->data;  // Current node is a potential predecessor
            temp = temp->right;
        }
    }

    pair<int,int> ans = make_pair(pred,suc);
    return ans;
}

int main()
{
    return 0;
}