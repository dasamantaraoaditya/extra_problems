//3.Add a node to the circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node * create_circular_linkedlist();
struct node *insert_at_end(struct node * start,struct node *end,int item);
struct node * insert_at_front(struct node * start,int item);
struct node * insert_at_middle(struct node * start,int item);
void insert_at_rare(struct node * start,int item);
void display(struct node *front); 
struct node
{
	int data;
	struct node * next;
};
int main()
{
	int choise,item;
	struct node *front;
	front=create_circular_linkedlist();
	printf("\nLIST ELEMENTS:\n");
	display(front);
	while(1)
	{
	printf("\nENTER UR CHOISE:\n1.insert at front 2.insert at middle 3.insert at end 4.exit\n");
	scanf("%d",&choise);
		printf("\nENter data: ");
		scanf("%d",&item);
		switch(choise)
		{
			case 1:front=insert_at_front(front,item);
			break;
			case 2:front=insert_at_middle(front,item);
			break;
			case 3:insert_at_rare(front,item);
			break;
			case 4:exit(0);
			default:printf("\nEnter a valied Option");
		}
		display(front);
	}
	return 0;
}
struct node * create_circular_linkedlist()
{
	int length,i=0,item;
	struct node *start,*end=NULL;
	printf("\nenter no of nodes u want ot insert :");
	scanf("%d",&length);
	if(length--)
	{
		end=(struct node *)malloc(sizeof(struct node));
		printf("\nEnter data of %d node",++i);
		scanf("%d",&end->data);
		end->next=end;
	}
	start=end;
	while(length--)
	{
		printf("\nEnter data of %d node:",++i);
		scanf("%d",&item);
		end=insert_at_end(start,end,item);
	}
	return start;
}

struct node *insert_at_end(struct node * start,struct node *end,int item)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=start;
	end->next=temp;
	return temp;
}
struct node * insert_at_front(struct node *start,int item)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node)),*begin=start;
	temp->data=item;
	temp->next=start;
	do
	{
		begin=begin->next;
	}while(begin->next!=start);
	begin->next=temp;
	return temp;
}

struct node * insert_at_middle(struct node * start,int item)
{
	int position,pos;
	struct node * begin=start,*temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter position to insert : ");
	scanf("%d",&position);
	pos=position;
	if(position==1)
	{
		begin=insert_at_front(begin,item);
		return begin;
	}
	else
	{		
		position-=2;
		while(position--)
		begin=begin->next;
		if(begin==start&&pos!=2)
		{
			insert_at_rare(begin,item);
			return start;
		}
		temp->data=item;
		temp->next=begin->next;
		begin->next=temp;
	}
	return start;
}

void insert_at_rare(struct node * start,int item)
{
	struct node *begin=start,*temp=(struct node *)malloc(sizeof(struct node));
	do
	{
	begin=begin->next;
	}while(start!=begin->next);
	temp->data=item;
	temp->next=start;
	begin->next=temp;
}
void display(struct node *front)
{
	struct node *begin=front;
	do
	{
		printf("->%d",begin->data);
		begin=begin->next;
	}while(front!=begin);
	printf("\n");
}


