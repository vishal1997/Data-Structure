void postOrder(node *root)
    {
    if(!root)
        return;
    postOrder(root->left);
    printf("%d ",root->data);
}

void preOrder(node *root)
    {
    if(!root)
        return ;
    printf("%d ",root->data);
    preOrder(root->right);
}


void top_view(node * root)
{
    postOrder(root);
    preOrder(root->right);
}
