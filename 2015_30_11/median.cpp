//1.Find median of a given linked list (Sorted Linked List) 
#include<stdio.h>
#include<stdlib.h>
void verify_testcases();
struct node * create_linkedlist(int items[]);
struct node * insert_at_end(struct node *end,int item);
int find_median(struct node *head);
int find_median_2(struct node *head);
int find_median_3(struct node *head);
struct node
{
	int data;
	struct node * next;
};
struct testcases
{
	int input[10];
	int output[2];
}testcases[7]={
{{1,2,3,4,5,6},{3,4}},
{{1,2,3,4},{2,3}},
{{1,2,},{1,2}},
{{1,2,3,4,5,6,7},{4}},
{{1},{1}},
{{1,2,8,9,111},{3,8}},
{{-50,-3,-2,-1,2,3,4,5,6},{-1,2}},
};
int main()
{
	verify_testcases();
	return 0;
}
void verify_testcases()
{
	int i,median;
	struct node *head;
	for(i=0;i<7;i++)
	{
		head=create_linkedlist(testcases[i].input);
		median=find_median(head);
		if(median==testcases[i].output[0]||median==testcases[i].output[1])
		printf("1PASSED,");
		else
		printf("1FAILED,");
		median=find_median_2(head);
		if(median==testcases[i].output[0]||median==testcases[i].output[1])
		printf("2PASSED,");
		else
		printf("2FAILED,");
		median=find_median_3(head);
		if(median==testcases[i].output[0]||median==testcases[i].output[1])
		printf("3PASSED\n");
		else
		printf("3FAILED\n");
	}
}
	
struct node * create_linkedlist(int items[])
{
	int i;
	struct node *start,*end=NULL;
	end=(struct node *)malloc(sizeof(struct node));
	if(items[0]!='\0')
	{
		end->data=items[0];
		end->next=NULL;
	}
	start=end;
	for(i=1;items[i]!='\0';i++)
	end=insert_at_end(end,items[i]);
	return start;
}
struct node * insert_at_end(struct node *end,int item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;
	end->next=temp;
	return temp;
}
int find_median(struct node *head)
{
	int length=-1,length2=0;
	struct node *head2=head;
	while(head2!=NULL)
	{
		head2=head2->next;
		length++;
	}
	length2=length/2;
	while(length2--)
	head=head->next;
	return (head->data);
}
int find_median_2(struct node *head)
{
	struct node *head2=head;
	while(head2!=NULL&&head2->next!=NULL)
	{
		head2=head2->next->next;
		head=head->next;
	}
	return head->data;
}
int find_median_3(struct node *head)
{
	int i=0;
	struct node *head2=head;
	while(head!=NULL)
	{
		head=head->next;
		if(i%2)
		head2=head2->next;
		i++;
	}
	
	return head2->data;
}
