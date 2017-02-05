struct Node *del_at_position(struct Node *head, int position)
{
	int count=0;
	struct Node *ptr=head, *prev=NULL;
	if(position==1)
	{
		head=ptr->next;
		free(ptr);
		return head;
	}
	while(ptr!=NULL && count<position)
	{
		prev=ptr;
		ptr=ptr->next;
		count++;
 	}
	if(ptr==NULL)
	{
		printf("\nPosition Not found");
		return head;
	}
	prev->next=ptr->next;
	free(ptr);
	return head;
}
