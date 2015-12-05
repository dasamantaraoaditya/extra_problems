//8.Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
//Note : min of descending part is greater than max of ascending 
//Ex: Input 1->2->7->20->15->10
//Output 1->2->7->10->15->20
#include<stdio.h>
#include<stdlib.h>
void verify_testcases();
struct node * create_linkedlist(int items[]);
struct node * insert_at_end(struct node *end,int item);
int verify_output(struct node * ,int * );
struct node * reverse_linkedlist(struct node * list,struct node * before);
struct node * rearrange_linkedlist(struct node *);
struct node
{
	int data;
	struct node * next;
};
struct testcase
{
	int input[20];
	int output[20];
}testcases[6]={
{{1,2,6,5,4,3},{1,2,3,4,5,6}},
{{1,4,3,2},{1,2,3,4}},
{{-1,5,3,2,1},{-1,1,2,3,5}},
{{2,3,4,6,5},{2,3,4,5,6}},
{{2,5,4},{2,4,5}},
{{-100,-20,1,-1,-2,-11},{-100,-20,-11,-2,-1,1}},
};
int main()
{
	verify_testcases();
	return 0;
}
void verify_testcases()
{
	int i;
	
	struct node *head2;
	for(i=0;i<6;i++)
	{
		head2=create_linkedlist(testcases[i].input);
		head2=rearrange_linkedlist(head2);
		if(verify_output(head2,testcases[i].output))
		printf("\nPASSED,");
		else
		printf("FAILED,");
	}
}
int verify_output(struct node *output1,int *output2)
{
	int i=0;
	while(output1!=NULL)
	{		
		if(output1->data!=output2[i++])	
		return 0;
		output1=output1->next;
	}
	return 1;
}

struct node * create_linkedlist(int items[])
{
	int i;
	struct node *start,*end=NULL;
	if(items[0]!='\0')
	{
			end=(struct node *)malloc(sizeof(struct node));
		end->data=items[0];
		end->next=NULL;
	}
	start=end;
	if(items[0]!='\0')
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
struct node * rearrange_linkedlist(struct node *list)
{
	struct node *list1=list,*inter_list=NULL;
	if(list==NULL&&list->next==NULL&&list->next->next==NULL)
	return list;
	while(list1->next->data<list1->next->next->data)
	list1=list1->next;
	inter_list=list1;
	list1=reverse_linkedlist(list1->next,NULL);
	inter_list->next=list1;
	return list;
}

struct node * reverse_linkedlist(struct node * list,struct node * before)
{
	if(list==NULL)
	return before;
	struct node * next_node=list->next;
	list->next=before;
	reverse_linkedlist(next_node,list);
}
