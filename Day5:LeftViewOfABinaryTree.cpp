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
void left(TreeNode<int>*root,vector<int>&ans,int level)
{
    if(root==NULL)return ;
    if(level==ans.size())
    {
        ans.push_back(root->data);

    }
    left(root->left,ans,level+1);
    left(root->right,ans,level+1);

}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    left(root,ans,0);
    return ans;

    //    Write your code here
}
