#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node *insert_at_beg(struct Node *head, int data);
struct Node *insert_at_end(struct Node *head, int data);
struct Node *insert_at_position(struct Node *head, int position, int data);
struct Node *del_at_beg(struct Node *head);
struct Node *del_at_end(struct Node *head);
void traverse_forward(struct Node *head);
struct Node *traverse_backward(struct Node *head);
void search(struct Node *head, int data);
struct Node *del_at_position(struct Node *head, int position);
int input();


int
main()
{
	int ch,
	ch2,
	data,
	n;
	char repeat;
	struct Node *head=NULL;
	do {
	printf("\n1. Insert \n2. Delete \n3. Traverse \n4. Search\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			ch2=input();
			if(ch2==1) {
				printf("Enter the data\n");
				scanf("%d", &data);
				head=insert_at_beg(head,data);
			}
			else if(ch2==2) {
				printf("\nEnter the data\n");
				scanf("%d", &data);
				head=insert_at_end(head,data);
			}
			else if(ch2==3) {
				printf("\nEnter a position\n");
				scanf("%d", &n);
				printf("\nEnter data\n");
				scanf("%d",&data);
				head=insert_at_position(head, n, data);
			}
			break;
		case 2:
			ch2=input();
			if(ch2==1)
				head=del_at_beg(head);
			else if(ch2==2)
				head=del_at_end(head);
			else if(ch2==3) {
				printf("\nEnter a position\n");
				scanf("%d", &n);
				head=del_at_position(head,n);
			}
			break;
		case 3:
			do {
			printf("\n1. Traverse forward\n2. Traverse backward\n");
			scanf("%d", &ch2);
			} while(ch2>2 || ch2<1);
			if(ch2==1)
				traverse_forward(head);
			else if(ch2==2)
				head=traverse_backward(head);
			break;
		case 4:
			printf("\nEnter the data to search\n");
			scanf("%d",&ch2);
			search(head, ch2);
			break;
        default:
            printf("Invalid Input");
	}
	printf("Press 'Y' or 'y' for the menu\n");
	scanf(" %c", &repeat);
	} while (repeat=='Y' || repeat=='y');
}

int input()
{
	int ch2;
	do {
		printf("1. At beginning\n2. At end \n3. At any specified position");
		scanf("%d",&ch2);
	} while(ch2<=0 || ch2 >3);
	return ch2;
}

void traverse_forward(struct Node *head)
{
	struct Node *ptr=head;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}
struct Node *traverse_backward(struct Node *head)
{
	if(head==NULL)
        return head;
	traverse_backward(head->next);
	printf("%d ",head->data);
	return head;
}
void search(struct Node *head, int data)
{
	struct Node *ptr=head;
	int position=1;
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



struct Node *insert_at_beg(struct Node *head, int data)
{
	struct Node *cur=head;
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	if(!newNode)
	{
		printf("Memory not allocated");
		return head;
	}
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(cur==NULL)
	{
		head=newNode;
		return head;
	}
	newNode->next=cur;
	cur->prev=newNode;
	head=newNode;
	return head;
}

struct Node *insert_at_end(struct Node *head, int data)
{
	struct Node *cur=head;
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(head==NULL)
    {
        head=newNode;
        return head;
    }
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=newNode;
	newNode->prev=cur;
	return head;
}
struct Node *insert_at_position(struct Node *head, int position, int data)
{
	struct Node *cur=head;
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->next=NULL;
	newNode->prev=NULL;
	newNode->data=data;
	int count=1;
	while(cur!=NULL && count<position)
	{
		count++;
		cur=cur->next;
	}
	if(count==1)
    {
        head=insert_at_beg(head, data);
        return head;
    }
    if(cur->next==NULL)
    {
        head=insert_at_end(head, data);
        return head;
    }
	if(count==position)
	{
		newNode->next=cur->next;
		cur->next->prev=newNode;
		cur->next=newNode;
		newNode->prev=cur;
	}
	else if(cur==NULL)
	{
		printf("Position not found");
	}
	return head;
}
struct Node *del_at_beg(struct Node *head)
{
	struct Node *cur=head;
	if(cur==NULL)
	{
		printf("List is empty");
		return head;
	}
	if(head->next==NULL)
    {
        head=NULL;
        return head;
    }
	head=head->next;
	head->prev=NULL;
	free(cur);
	return head;
}
struct Node *del_at_end(struct Node *head)
{
	struct Node *cur=head;
	if(cur==NULL)
	{
		printf("List not found");
		return head;
	}
	if(cur->next==NULL)
    {
        head=NULL;
        return head;
    }
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->prev->next=NULL;
	free(cur);
	return head;
}

struct Node *del_at_position(struct Node *head, int position)
{
	struct Node *cur=head;
	if(cur==NULL)
	{
		printf("List is empty");
		return head;
	}
	int count=1;

	while(cur!=NULL && count<position)
	{
		cur=cur->next;
		count++;
	}
	if(count==1)
    {
        head=del_at_beg(head);
        return head;
    }
    if(cur->next==NULL)
    {
        head=del_at_end(head);
        return head;
    }
	if(cur==NULL)
	{
		printf("Position not found");
		return head;
	}
	if(count==position)
	{
		cur->prev->next=cur->next;
		cur->next->prev=cur->prev;
		free(cur);
	}
	return head;
}
