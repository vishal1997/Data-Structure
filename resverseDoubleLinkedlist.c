Node* Reverse(Node* head)
{
    struct Node *current=head, *save=NULL;
    while(current!=NULL) {
        save=current->prev;
        current->prev=current->next;
        current->next=save;
        current=current->prev;
    }
    if(save != NULL )
        head = save->prev;

    return head;
    // Complete this function
    // Do not write the main method.
}
