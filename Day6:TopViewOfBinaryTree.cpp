#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,int>mp;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(root)
    {
        if(q.empty())break;
        TreeNode<int>* node=q.front().first;
        int dist=q.front().second;
        q.pop();
        if(mp.find(dist)==mp.end())mp[dist]=node->val;
        if(node->left)q.push({node->left,dist-1});
        if(node->right)q.push({node->right,dist+1});
    }
    vector<int>ans;
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
