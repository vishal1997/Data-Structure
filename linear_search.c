void search(struct Node *head, int data)
{
	struct Node *ptr=head;
	int position=0;
	int flag=0;
	while(ptr!=NULL)
	{
	    if(ptr->data==data)
        {
            flag=1;
            break;
        }
        else
        {
            position++;
            ptr=ptr->next;
        }
	}

	if(flag)
	{
		printf("\nData found at %d",position);
	}
	else
		printf("\nData Not found");
    return;
}
