#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long path(TreeNode<int>* root,long long &ans,int &num)
{
  if (root == NULL) {
    //num++;
    return 0;
  }
  if(root->left==NULL&&root->right==NULL)num++;
    long long left=path(root->left,ans,num);
    long long right=path(root->right,ans,num);
    ans=max(ans,root->val+left+right);
    return max(left,right)+root->val;

}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root)return -1;
    long long ans=INT_MIN;
    int num=0;
    path(root,ans,num);
    if(num<=1)return -1;
    return ans;
    // Write your code here.
}
