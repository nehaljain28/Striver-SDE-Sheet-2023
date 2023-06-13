#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

int cal(BinaryTreeNode<int>*root,bool &ans)
{
    if(root==NULL)return 0;
    int lh=cal(root->left,ans);
    int rh=cal(root->right,ans);
    if(abs(lh-rh)>1)
    {
        ans=false;
        return 0;
    }
    return 1+max(lh,rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool ans=true;
    cal(root,ans);
    return ans;
}
