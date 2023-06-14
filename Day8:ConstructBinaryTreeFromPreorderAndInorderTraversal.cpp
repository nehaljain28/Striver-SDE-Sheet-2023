#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/
TreeNode<int>* build(vector<int>&inorder,int instart,int inend,vector<int>&preorder,int prestart,int preend,map<int,int>&mp)
{
    if(prestart>preend||instart>inend)return NULL;
    int a=preorder[prestart];
    TreeNode<int>* node= new TreeNode<int>(a);
    
    int elem=mp[node->data];
    int num=elem-instart;
    node->left = build(inorder,instart,elem-1,preorder,prestart+1,prestart+num,mp);
    node->right = build(inorder,elem+1,inend,preorder,prestart+num+1,preend,mp);
    return node;
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++)
    {
        mp[inorder[i]]=i;
    }
    return build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);

	//    Write your code here
}
