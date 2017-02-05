int tree_height(node *root)
    {
    if(!root)
        return 0;
    int left_height=tree_height(root->left);
    int right_height=tree_height(root->right);
    if(left_height>right_height)
        return left_height+1;
    return right_height+1;
}

void print_level(node *root, int level)
    {
        if(!root)
            return ;
        if(level==1)
            printf("%d ",root->data);
        print_level(root->left,level-1);
        print_level(root->right, level-1);
}

void LevelOrder(node * root)
{
    int height=tree_height(root);
    for(int depth=1; depth<=height ;depth++)
        {
            print_level(root, depth);
    }

}
