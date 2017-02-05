struct Node *del_at_end(struct Node *head)
{
	struct Node *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	free(ptr);
	return head;
}
