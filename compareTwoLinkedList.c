int CompareLists(Node *headA, Node* headB)
{
    struct Node *pa=headA;
    struct Node *pb=headB;
    while(pa!=NULL && pb!=NULL) {
        if(pa->data!=pb->data)
            return 0;
        pa=pa->next;
        pb=pb->next;
    }
    if(pa==NULL && pb==NULL)
        return 1;
    else
        return 0;
  // This is a "method-only" submission.
  // You only need to complete this method
}
