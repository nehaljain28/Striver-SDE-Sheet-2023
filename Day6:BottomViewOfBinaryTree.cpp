#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
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

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    
    // Write your code here.
    map<int,int>mp;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(root)
    {
        if(q.empty())break;
        BinaryTreeNode<int>* node=q.front().first;
        int dist=q.front().second;
        q.pop();
        mp[dist]=node->data;
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
