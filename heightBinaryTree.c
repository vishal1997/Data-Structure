int height(Node* root) {
        // Write your code here.
        if(root==NULL)
        return -1;
    int left_height=height(root->left);
    int right_height=height(root->right);
    if(left_height>right_height)
        return left_height+1;
    return right_height+1;
    }
