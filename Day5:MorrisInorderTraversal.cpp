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
    TreeNode* s=root;
    vector<int>ans;
    while(s!=NULL)
    {
        if(s->left==NULL)
        {
            ans.push_back(s->data);
            s=s->right;
        }
        else
        {
            TreeNode* prev=s->left;
            while(prev->right&&prev->right!=s)prev=prev->right;
            if(prev->right==NULL)
            {
                prev->right=s;
                s=s->left;
            }
            else
            {
                prev->right=NULL;
                ans.push_back(s->data);
                s=s->right;
            }
        }
    }
    
    return ans;

    // Write your code here.
}
