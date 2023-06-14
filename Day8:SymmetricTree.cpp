/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool sym(BinaryTreeNode<int>* l,BinaryTreeNode<int>* r)
{
    if(l==NULL||r==NULL)return l==r;
    return (l->data==r->data)&&sym(l->left,r->right)&&sym(l->right,r->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root)return true;
    return sym(root->left,root->right);
    
    // Write your code here.    
}
