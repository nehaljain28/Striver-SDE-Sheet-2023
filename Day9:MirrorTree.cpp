 void mirror(Node* node) {
        // code here
        if(!node)return;
    queue<Node*>st;
    st.push(node);
    while(!st.empty())
    {
         Node* root=st.front();
         Node* left=root->left;
         Node* right=root->right;
        st.pop();
        if(left)st.push(left);
        if(right)st.push(right);
        root->left=right;
        root->right=left;
    }
    }
