struct Node *del_at_beg(struct Node *head)
{
	struct Node *ptr=head;
	if(head==NULL)
    {
        printf("List is empty");
        return head;
    }
	head=ptr->next;
	free(ptr);
	return head;
}
