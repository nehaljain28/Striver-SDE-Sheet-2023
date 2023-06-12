#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void traverse(BinaryTreeNode<int> *root,vector<vector<int>> &ans)
{
    
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans(3);
    if(root==NULL)return ans;
    stack<pair<BinaryTreeNode<int> *,int>>st;
    st.push({root,1});
    while(!st.empty())
    {
        
        BinaryTreeNode<int> * node=st.top().first;
        int level=st.top().second;
        st.pop();
        if(level==1)
        {
            ans[1].push_back(node->data);
            level++;
            st.push({node,level});
            if(node->left)
            {
                st.push({node->left,1});
            }
        }
        else if(level==2)
        {
            ans[0].push_back(node->data);
            level++;
            st.push({node,level});
            if(node->right)
            {
                st.push({node->right,1});
            }
        }
        else
        {
            ans[2].push_back(node->data);
        }
    }
    return ans;
}
