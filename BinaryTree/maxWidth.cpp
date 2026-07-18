#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
/*
Given a Binary Tree, return its maximum width. The maximum width of a Binary Tree is the maximum diameter 
among all its levels. The width or diameter of a level is the number of nodes between the leftmost and rightmost nodes.
*/

/*
Time Complexity: O(N), each node is processed once in level order traversal.
Space Complexity: O(N), in worst case, the queue holds all the nodes of the last level i.e. N/2 nodes.*/
int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;

    int maxwidth = 0;
    queue<pair<TreeNode<int>*,int>>q; //node,index(hd)

    q.push({root,0});

    while(!q.empty())
    {
        int size = q.size();

        //store minindex to change indexing of next level to avoid overflow
        int minindex = q.front().second;

        int first = 0;
        int last = 0;

        //traverse nodes of curr level
        for(int i = 0; i< size; i++)
        {
            TreeNode<int>* node = q.front().first;
            //relative index
            int currindex = q.front().second - minindex;

            q.pop();

            if(i == 0) first = currindex;

            if(i == size-1) last = currindex;

            if(node->left)
            {
                q.push({node->left,2 * currindex + 1});
            }

             if(node->right)
            {
                q.push({node->right,2 * currindex + 2});
            }
            
        }
        maxwidth = max(maxwidth,(last-first+1));
    }
    return maxwidth;
}