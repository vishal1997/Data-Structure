Node* MergeLists(Node *headA, Node* headB)
{
    struct Node *merge=NULL, *result=NULL;
    if(headA==NULL)
        return headB;
    else if(headB==NULL)
        return headA;
    if(headA->data <= headB->data) {
        result=headA;
        result->next=MergeLists(headA->next,headB);

    }
    else {
        result=headB;
        result->next=MergeLists(headA,headB->next);
    }
    return result;
  // This is a "method-only" submission.
  // You only need to complete this method
}
