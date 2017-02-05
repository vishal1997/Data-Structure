void traverse_forward(struct Node *head)
{
	struct Node *ptr=head;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}
