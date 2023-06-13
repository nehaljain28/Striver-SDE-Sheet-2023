#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(root==0)return 0;
    map<int,int>mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        TreeNode<int>*node=q.front().first;
        int level=q.front().second;
        q.pop();
        mp[level]++;
        if(node->left)q.push({node->left,level+1});
        if(node->right)q.push({node->right,level+1});
    }
    int ans=0;
    for(auto i:mp)
    {
        ans=max(ans,i.second);
    }
    return ans;

        return ans;

}
