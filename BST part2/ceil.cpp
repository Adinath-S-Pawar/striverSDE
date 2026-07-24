#include <bits/stdc++.h> 
using namespace std;

    template<typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1;

    while(node != NULL)
    {
        if(x == node->data)
        {
            ceil = node->data;
            break;
        }
        else if(x > node->data)
        {
            node = node->right;
        }
        else if(x < node->data)
        {
            ceil = node->data;
            node = node->left;
        }

    }
    return ceil;
  
}