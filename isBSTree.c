#define INT_MAX 4000000000
#define INT_MIN -4000000000
bool BSTutil(Node *root, long int min, long int max)
{
    if(!root)
        return true;
    if(root->data < min || root->data > max)
        return false;
    return BSTutil(root->left, min , root->data-1) && BSTutil(root->right, root->data+1, max);
}

   bool checkBST(Node* root) {
       return BSTutil(root, INT_MIN, INT_MAX);
   }

