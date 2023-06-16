//optimal approach (morris traversal)
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(!root)return NULL;
    TreeNode<int>* curr=root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode<int>* prev=curr->left;
                while(prev->right)
                {
                    prev=prev->right;

                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
            
        }
        return root;
    // Write your code here.
}

//recursive
class Solution {
    TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
       
        
        
            if(root==NULL)return;
            flatten(root->right);
            flatten(root->left);
            root->right=prev;
            root->left=NULL;
            prev=root;

        
    }
};


//iterative
void flatten(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
            if(!st.empty())
            {
                node->right=st.top();
            }
            node->left=NULL;
        }
    }
