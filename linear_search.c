void search(struct Node *head, int data)
{
	struct Node *ptr=head;
	int position=0;
	while(ptr!=NULL && ptr->data!=data)
	{
		position++;
		ptr=ptr->next;
	}
	if(ptr->data==data)
	{
		printf("\nData found at %d",position);
	}
	else if(ptr==NULL)
		printf("\nData Not found");
    return;
}
