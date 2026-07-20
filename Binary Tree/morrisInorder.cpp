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
        this->left = NULL;
        this->right = NULL;
    }
};

/*
Time Complexity: O(2N), the time complexity is linear, as each node is visited at most twice (once for establishing the temporary link and once for reverting it).
Space Complexity: O(1), the space complexity is constant, as the algorithm uses only a constant amount of extra space irrespective of the input size.
*/
vector<int> getInOrderTraversal(node *root)
{
    vector<int> vec;
    node* current = root;
    while(current != NULL)
    {
        if(current->left == NULL)
        {
            vec.push_back(current->data);
            current = current->right;

        }
        else
        {
            // predecessor
            node* pred = current->left;
            while(pred->right && pred->right != current )// != curr is for temp link
            {
                pred = pred->right;

            }

            if(pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else{
                  pred->right = NULL;
                    vec.push_back(current->data);
                    current = current->right;
            }

        }
    }

    return vec;
}

int main()
{
    return 0;
}