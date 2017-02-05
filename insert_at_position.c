struct Node *insert_at_position(struct Node *head, int position, int data)
{
	struct Node *ptr=head, *prev=NULL;
	struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
	new_node->data=data;
	new_node->next=NULL;
	int count=0;
	if(position==1)
	{
		new_node->next=ptr;
		head=new_node;
		return head;
	}
	while(ptr!=NULL && count<position) {
		prev=ptr;
		ptr=ptr->next;
		count++;
	}
	if(ptr==NULL)
	{
		printf("\nPosition Not found");
		return head;
	}
	prev->next=new_node;
	new_node->next=ptr;
	return head;
}
