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
TreeNode<int>* CommonAncestor(TreeNode<int>* root, int p, int q) {
        if(root==NULL||root->data==p||root->data==q)return root;
        TreeNode<int>* left=CommonAncestor(root->left,p,q);
        TreeNode<int>* right=CommonAncestor(root->right,p,q);
        if(left==NULL)return right;
        else if(right==NULL)return left;
        else return root;
    }
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int> *node = CommonAncestor(root, x, y);
    return node->data;
	//    Write your code here
}
