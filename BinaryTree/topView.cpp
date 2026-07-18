#include<vector>
#include<queue>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

#include<map>
/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each 
node exactly once during the BFS traversal.

Space Complexity: O(N/2 + N/2) where N represents the number of nodes in the Binary Tree. The main space consuming 
data structure is the queue used for BFS traversal. It acquires space proportional to the number of nodes in the 
level it is exploring hence in the worst case of a balanced binary tree, the queue will have at most N/2 nodes 
which is the maximum width.Additionally, the map is used to store the top view nodes based on their vertical 
positions hence its complexity will also be proportional to the greatest width level. In the worst case, 
it may have N/2 entries as well.
*/
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int>ans;
    if(root == NULL)
    {
        return ans;
    }

    map<int,int> dist_val;  // horizontal dist , node val
    queue<pair <TreeNode<int> *,int> > q;   //node,HD , queue for bfs/lvl order
    q.push(make_pair(root,0)); //HD = 0 for root

    while(!q.empty())
    {
        pair<TreeNode<int> *,int> temp = q.front();
        q.pop();

        TreeNode<int> * frontnode = temp.first;
        int hd = temp.second;

        // if hd dist not mapped i.e we can map
        if(dist_val.find(hd) == dist_val.end() ) //.end If the key is not found, it returns an iterator to the end of the map. 
        {
            dist_val[hd] = frontnode->data;
            //we are popping qfront so it will never happen that last elem in map has same
            // hd as searching elem

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
