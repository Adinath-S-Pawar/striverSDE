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
//tc - O(n) sc - O(1)
node *LCAinaBST_iterative(node *root, node *P, node *Q)
{
   while(root != NULL)
   {
        if(root->data < P->data && root->data < Q->data)
        {
            root = root->right;
        }
        else if(root->data > P->data && root->data > Q->data)
        {
            root= root->left;
        }    
        else 
            return root;
   }

}

int main()
{
    return 0;
}