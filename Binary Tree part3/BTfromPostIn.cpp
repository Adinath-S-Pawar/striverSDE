#include<bits/stdc++.h>
using namespace std;
   
   template <typename T>
   class TreeNode
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
#include<unordered_map>

void createmap(vector<int>inOrder,unordered_map<int,int> &nodevalToIndex)
{

    for(int i = 0 ;i<inOrder.size();++i)
    {
        nodevalToIndex[inOrder[i]] = i;
    }
}

TreeNode<int> * solve(vector<int>inOrder, vector<int> postOrder,int &postorderIndex,
int inorderStart,int inorderEnd,unordered_map<int,int>nodevalToIndex)
{   
    //base case
    if(inorderStart > inorderEnd || postorderIndex <0 )
    {
        return NULL;
    }
//element = preorder[index] and then increment index++
    int element = postOrder[postorderIndex--];
    TreeNode<int> * root = new TreeNode<int>(element);

    int position =nodevalToIndex.at(element);

    root->right = solve(inOrder,postOrder,postorderIndex,position+1,inorderEnd,nodevalToIndex);
    root->left = solve(inOrder,postOrder,postorderIndex,inorderStart,position-1,nodevalToIndex);

    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	int n = inOrder.size();
    int postorderIndex = n-1;

        if (inOrder.size() != postOrder.size()) {
            return NULL;
        }

    unordered_map<int,int> nodevalToIndex;
    createmap(inOrder,nodevalToIndex);
    return solve(inOrder,postOrder,postorderIndex ,0,n-1,nodevalToIndex);

}

int main()
{
    return 0;
}