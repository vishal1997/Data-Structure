struct Node *traverse_backward(struct Node *head)
{
	struct Node *ptr=head,*cur=NULL;
	if(head==NULL)
        return head;
	cur=traverse_backward(ptr->next);
	printf("%d",cur->data);
	return head;
}
