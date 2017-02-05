int FindMergeNode(Node *headA, Node *headB)
{
    struct Node *curA=headA, *curB=headB;
    if(curA==NULL || curB==NULL) {
        return 0;
    }
    while(curA!=NULL) {
            while(curA!=curB && curB!=NULL) {
                curB=curB->next;
            }
            if (curA==curB) {
                return curA->data;
            }
        curB=headB;
        curA=curA->next;
    }
    return 0;
    // Complete this function
    // Do not write the main method.
}
