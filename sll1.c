#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;
void createLL();
void display();
void reverse();
void sort();
int main()
{
	char ch;
	do{
	int choice;
	printf("MENU\n1. Create Linked List\n2. display\n3. reverse\n4. sort\n5. Exit\n");
	printf("Enter UR choice (1/2/3/4/5) : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			createLL();
			break;
		case 2:
			printf("The elements are : \n");
			display();
			printf("\n");
			break;
		case 3:
			reverse();
			break;
		case 4:
			sort();
			break;
		case 5:
			exit(0);
		default:
			printf("Invalid choice.\n");
	}
	printf("Do U want to view the MENU once again ? ");
	scanf(" %c",&ch);
}while(ch=='Y'||ch=='y');
}
void createLL()
{	char ch;
	struct node *new,*p;
	do{
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Insufficient memory.\n");
		return;
	}
	printf("Enter info : ");
	scanf("%d",&new->info);
	new->next=NULL;
	if(start==NULL)
	{
		start=new;
		p=new;
	}
	else
	{
		p->next=new;
		p=new;
	}
	printf("Do U want 2 add more nodes : ");
	scanf(" %c",&ch);
}while(ch=='Y'||ch=='y');

}
void display()
{
	if(start==NULL)
	{	printf("Linked List does not exist");
	return;
	}
	struct node *p=start;
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->next;
	}
}


void reverse()
{
	struct node *ptr=start,*prev=NULL,*save=NULL;
	while(ptr!=NULL)
	{
		save=ptr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=save;
	}
	start=prev;

}




void sort()
{
	struct node *q,*p;
	int data;
	q=start;
	while(q!=NULL)
	{
		p=q->next;
		while(p!=NULL)
		{
			if(q->info>p->info)
			{
				data=q->info;
				q->info=p->info;
				p->info=data;
			}
			p=p->next;
		}
		q=q->next;
	}
}
