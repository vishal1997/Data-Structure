struct Node *insert_at_beg(struct Node *head, int data)
{
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	struct Node *ptr=head;
	new_node->data=data;
	new_node->next=ptr;
	head=new_node;
	return head;
}
