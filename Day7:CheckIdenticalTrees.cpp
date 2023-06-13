#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    temroot1late <tyroot1ename T>

    class BinaryTreeNode {
    root1ublic :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(root1==NULL&&root2==NULL)return true;
        else if(root1==NULL||root2==NULL)return false;
        else return (root1->data==root2->data&&identicalTrees(root1->left,root2->left)&&identicalTrees(root1->right,root2->right));
    // Write your code here. 	 
}
