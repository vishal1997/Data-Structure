void inOrder(node *root) {
    if(root==NULL)
        return ;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
    return ;

}
