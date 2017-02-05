int GetNode(Node *head,int positionFromTail)
{
    struct Node *current=head;
    int i=0;
    while (current!=NULL)
        {
        i++;
        current=current->next;
    }
    current=head;
    i-=1;
    int pos=i-positionFromTail;
    i=0;
    while(i<pos) {
        current=current->next;
        i++;
    }
    return current->data;
  // This is a "method-only" submission.
  // You only need to complete this method.
}
