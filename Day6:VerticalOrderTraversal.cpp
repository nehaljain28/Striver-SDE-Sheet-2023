#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    map<int,map<int,vector<int>>>mp;
    q.push({root, {0, 0}});
    while(root!=NULL)
    {
        if(q.empty())break;
        TreeNode<int>* node=q.front().first;
        int level=q.front().second.first;
        int dist=q.front().second.second;
        q.pop();
        mp[dist][level].push_back(node->data);
        if(node->left)q.push({node->left,{level+1,dist-1}});
        if(node->right)q.push({node->right,{level+1,dist+1}});
    }
    vector<int>ans;
    for(auto i:mp)
    {
        for(auto j:i.second)
        {
            ans.insert(ans.end(),j.second.begin(),j.second.end());
        }
    }
    return ans;
    //    Write your code here.
}
