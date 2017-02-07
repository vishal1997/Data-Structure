struct Node *del_at_end(struct Node *head)
{
	struct Node *ptr=head, *temp=NULL;
	while(ptr->next!=NULL)
	{
	    temp=ptr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	free(ptr);
	return head;
}
