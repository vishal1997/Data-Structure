Node* SortedInsert(Node *head,int data)
{
    struct Node *current=head;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
        {
        head=newNode;
        return head;
    }

    if (data < head->data)
    {
        newNode->next=current;
        current->prev=newNode;
        head=newNode;
        return head;
    }

    while(current->data < data && current->next!=NULL) {
        current=current->next;
    }
    if(current->data > data) {
        newNode->next=current;
        newNode->prev=current->prev;
        current->prev->next=newNode;
        current->prev=newNode;

    }
    else if(current->next==NULL) {
    current->next=newNode;
    newNode->prev=current;
    }
    return head;


    // Complete this function
   // Do not write the main method.
}
