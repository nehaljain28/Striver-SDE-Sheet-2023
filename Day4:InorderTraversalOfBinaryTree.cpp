//recursive:
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
void inorder(TreeNode *node,vector<int>&ans)
{
    if(node==NULL)return;
    inorder(node->left,ans);
    ans.push_back(node->data);
    inorder(node->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    inorder(root,ans);
    return ans;

    // Write your code here.
}

//iterative:
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

vector<int> getInOrderTraversal(TreeNode *root)
{
    stack<TreeNode*>s;
    vector<int>ans;
    while(true)
    {
        if(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            if(s.empty())break;
            root=s.top();
            ans.push_back(root->data);
            s.pop();
            root=root->right;

        }
    }
    
    return ans;

    // Write your code here.
}
