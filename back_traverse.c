struct Node *traverse_backward(struct Node *head)
{
	if(head==NULL)
        return head;
	traverse_backward(head->next);
	printf("%d",head->data);
	return head;
}
