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

#include<map>
vector<int> bottomView(TreeNode<int> * root){
    vector<int>ans;
    if(root == NULL)
    {
        return ans;
    }
    map<int,int> dist_val;
    queue<pair <TreeNode<int> *,int> > q;//node,HD
    q.push(make_pair(root,0)); //HD = 0 for root
    while(!q.empty())
    {
        pair<TreeNode<int> *,int> temp = q.front();
        q.pop();
        TreeNode<int> * frontnode = temp.first;
        int hd = temp.second;
    //if condition in top view of checking hd is used or not will be removed (or overwrite)
        {
            dist_val[hd] = frontnode->data;

        }
        if(frontnode->left)
        {
            q.push(make_pair(frontnode->left,hd-1));
        }
        if(frontnode->right)
        {
            q.push(make_pair(frontnode->right,hd+1));
        }        
    }
    for(auto i: dist_val)
    {
        ans.push_back(i.second);
    }
    return ans;
}
