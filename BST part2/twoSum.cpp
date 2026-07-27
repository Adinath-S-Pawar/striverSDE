#include <bits/stdc++.h> 
using namespace std;

template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

/*
Time Complexity: O(n)
Space Complexity: O(n) (or more precisely O(n + h))
*/
void inordervec(BinaryTreeNode<int>* root,vector<int> &vec)
{
    if(root == NULL)
        return;

    inordervec(root->left,vec);
    vec.push_back(root->data);
    inordervec(root->right,vec);    
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> vec;
    inordervec(root,vec);
    int i = 0;
    int j = vec.size()-1;
    while(i<j)
    {
        int sum = vec[i] + vec[j];
        if(sum == target)
            return true;
        else if(sum > target)
        {
            j--;
        } 
        else  
            i++;   
    }
    return false;

}
