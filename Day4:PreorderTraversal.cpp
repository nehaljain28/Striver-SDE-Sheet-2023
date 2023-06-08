//recursive
#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void preorder(TreeNode* node,vector<int> &ans)
{
    if(node==NULL)return;
    ans.push_back(node->data);
    preorder(node->left,ans);
    preorder(node->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    preorder(root, ans);
    return ans;
    // Write your code here.
}
//iterative
#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    if(root==NULL)return ans;
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode *node=s.top();
        ans.push_back(node->data);
        s.pop();

        if(node->right!=NULL)s.push(node->right);
        if(node->left!=NULL)s.push(node->left);
    }
    return ans;
    // Write your code here.
}
