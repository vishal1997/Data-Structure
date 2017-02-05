struct Node *del_at_beg(struct Node *head)
{
	struct Node *ptr=head;
	head=ptr->next;
	free(ptr);
	return head;
}
