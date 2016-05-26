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
void insert_beg();
void insert_end();
void insert_after_value();
void reverse();
void sort();
int main()
{
	char ch;
	do{
	int choice;
	printf("MENU\n1. Create Linked List\n2. display\n3. Insert at the beginning\n4. Insert at the end\n5. Insert after a value in the list\n6. reverse\n7. sort\n8. Exit\n");
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
		    insert_beg();
		    break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_after_value();
            break;
        case 6:
			reverse();
			break;
		case 7:
			sort();
			break;
		case 8:
			exit(0);
		default:
			printf("Invalid choice.\n");
	}
	printf("Do U want to view the MENU once again ? ");
	scanf(" %c",&ch);
}while(ch=='Y'||ch=='y');
}
void insert_beg()
{
    char ch;
    do
    {
        struct node *new;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
            printf("Insufficient memory\n");
            return ;
        }
        new->next=NULL;
        printf("Enter the number in the node:\n");
        scanf("%d",&new->info);
        new->next=start;
        start=new;
        printf("Do you want to add more elements in the node.\nPress Y or N:\n");
        scanf(" %c",&ch);
    }while(ch=='Y'||ch=='y');
}
void insert_end()
{
    char ch;
    do
    {
        struct node *new,*p;
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
            printf("insufficient memory.\n");
            return;
        }
        printf("Enter the number in the node:\n");
        scanf("%d",&new->info);
        new->next=NULL;
        if(start==NULL)
        {
            start=new;
        }
        else
        {
            p=start;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=new;
        }
        printf("Do you want to insert more elements in the end\n");
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

void insert_after_value()
{
    char ch;
    do
    {
        struct node *new,*p;
        if(start==NULL)
        {
            printf("No linked list found\n");
            return;
        }
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL)
        {
            printf("Insufficient memory\n");
            return;
        }
        int x;
        p=start;
        printf("Enter the value after which you want to insert a node");
        scanf("%d",&x);
        while(p->info!=x && p!=NULL)
        {
            p=p->next;
        }
        if(p==NULL)
        {
            printf("Value not found:\n");
            return;
        }
        printf("Enter the number in the new node:\n");
        scanf("%d",&new->info);
        new->next=NULL;
        new->next=p->next;
        p->next=new;
        printf("Do you want to insert more elements:\nPress Y or N:");
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
