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
int cal(TreeNode<int>* node,int &ans)
    {
        if(node==NULL)return 0;
        int lh=cal(node->left,ans);
        int rh=cal(node->right,ans);
        ans=max(ans,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode<int>* root) {
        if(!root)return 0;
        int ans=0;
        cal(root,ans);
        return ans;
    }

