Node* Reverse(Node *head)
{
    struct Node *current=head,*save=NULL, *prev=NULL;
    while(current!=NULL) {
        save=current->next;
        current->next=prev;
        prev=current;
        current=save;
    }
    return prev;
  // Complete this method
}
