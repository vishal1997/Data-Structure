void preOrder(node *root) {
    if(root==NULL)
        return ;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
    return ;
}