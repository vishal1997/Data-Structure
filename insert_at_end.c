struct Node *insert_at_end(struct Node *head, int data)
{
	struct Node *ptr=head;
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=data;
	new_node->next=NULL;
	while(ptr->next!=NULL) {
		ptr=ptr->next;
	}
	ptr->next=new_node;
	return head;
}
