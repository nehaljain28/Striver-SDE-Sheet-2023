#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>ans;
        if(root==NULL)return ans;
        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        bool fl=true;//true:left to right
        while(!q.empty())
        {
            int size=q.size();
            vector<int>r(size);
            for(int i=0;i<size;i++)
            {
                BinaryTreeNode<int>* node=q.front();
                if(fl)
                {
                    r[i]=node->data;
                    
                }
                else
                {
                    r[size-i-1]=node->data;
                    
                }
                
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            fl=!fl;
            for(auto i:r)ans.push_back(i);
        }
        return ans;
    // Write your code here!
}
