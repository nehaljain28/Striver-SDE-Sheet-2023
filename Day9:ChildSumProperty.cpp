#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void reorder(BinaryTreeNode < int > * root)
{
    if(!root)return ;
    int child=0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;
    if(child>=root->data)root->data=child;
    else{
        if(root->left)root->left->data=root->data;
         if(root->right)root->right->data=root->data;
    }
    reorder(root->left);
    reorder(root->right);
    int tot=0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    if(root->left||root->right)root->data=tot;
}
void changeTree(BinaryTreeNode < int > * root) {

    // Write your code here.
    reorder(root);

}  
