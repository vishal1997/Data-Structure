node *new_node(int key)
    {
    node *temp=(node *)malloc(sizeof(node *));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node * insert(node * root, int value)
{
    if(!root)
        return new_node(value);
    if(root->data<value)
        root->right=insert(root->right, value);
    else if(root->data>value)
        root->left=insert(root->left, value);
   return root;
}
