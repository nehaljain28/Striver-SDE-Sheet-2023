class Solution {
public:
    TreeNode* build(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int prostart,int proend,map<int,int>&mp)
    {
        if(instart>inend||proend>prostart)return NULL;
        TreeNode* node=new TreeNode(postorder[prostart]);
        int elem=mp[node->val];
        int numright=inend-elem;
        node->left=build(inorder,instart,elem-1,postorder,prostart-numright-1,proend,mp);
        node->right=build(inorder,elem+1,inend,postorder,prostart-1,prostart-numright,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i; 
        return build(inorder,0,inorder.size()-1,postorder,postorder.size()-1,0,mp);
    }
};
