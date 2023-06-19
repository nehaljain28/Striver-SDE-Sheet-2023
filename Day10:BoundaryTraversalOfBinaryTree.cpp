#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>* root){
    if(root->left==NULL&&root->right==NULL)return true;
    return false;
}
void left(TreeNode<int>* root,vector<int>&ans){
    TreeNode<int>* cur=root->left;
    while(cur)
    {
        if(!isleaf(cur))ans.push_back(cur->data);
        if(cur->left)cur=cur->left;
        else cur=cur->right;
    }
}
void leaf(TreeNode<int>* root,vector<int>&ans){
    if(isleaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)leaf(root->left,ans);
    if(root->right)leaf(root->right,ans);
}
void right(TreeNode<int>* root,vector<int>&ans){
    TreeNode<int>* cur=root->right;
    stack<int>st;
    while(cur)
    {
        if(!isleaf(cur))st.push(cur->data);
        if(cur->right)cur=cur->right;
        else cur=cur->left;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(!root)return ans;
    if(!isleaf(root))ans.push_back(root->data);
    left(root,ans);
    leaf(root,ans);
    right(root,ans);
    return ans; 
}
