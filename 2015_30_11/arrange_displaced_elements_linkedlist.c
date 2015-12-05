//7.Sorted a linked list which is in ascending order but two numbers are changed ,i mean not in the usual order they need to be
//Ex: 1->2->3->15->10->4->20; O/p:1-2-3-4-10-15-20
#include<stdio.h>
#include<stdlib.h>
void verify_testcases();
struct node * create_linkedlist(int items[]);
struct node * insert_at_end(struct node *end,int item);
int verify_output(struct node * ,int * );
struct node * arrange_displaced_lists(struct node *list_org);
struct node
{
	int data;
	struct node * next;
};
struct testcases
{
	int input[20];
	int output[20];
}testcases[11]={
{{1,2,4,3,5,6},{1,2,3,4,5,6}},
{{1,4,3,2,5},{1,2,3,4,5}},
{{1,5,3,4,2,6},{1,2,3,4,5,6}},
{{6,2,3,4,5,1},{1,2,3,4,5,6}},
{{1,2,3,4,6,5},{1,2,3,4,5,6}},
{{2,1,3,4,5},{1,2,3,4,5}},
{{1,7,3,4,5,6,2},{1,2,3,4,5,6,7}},
{{4,2,3,1,5,6,7},{1,2,3,4,5,6,7}},
{{2,1},{1,2}},
{{2},{2}},
{{},{}},
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
	for(i=0;i<11;i++)
	{
		head2=create_linkedlist(testcases[i].input);
		head2=arrange_displaced_lists(head2);
		if(verify_output(head2,testcases[i].output))
		printf("\nPASSED,");
		else
		printf("2FAILED,");
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

struct node * arrange_displaced_lists(struct node *list_org)
{
	struct node * list=list_org,*fault_list1=NULL,*fault_list2=NULL;
	if(list==NULL||list->next==NULL)
	return list;
	while(1)
	{
		if(list->data>list->next->data)
		{
			fault_list1=list;
			break;
		}
		list=list->next;
	}
	list=list->next;
	while(list->next!=NULL)
	{
		if(list->data>list->next->data)
		{
			fault_list2=list->next;
			break;
		}
		list=list->next;
	}
	int temp=fault_list1->data;
	if(fault_list2==NULL)
	{
		fault_list1->data=fault_list1->next->data;
		fault_list1->next->data=temp;
	}
	else
	{
		fault_list1->data=fault_list2->data;
		fault_list2->data=temp;
	}
	return list_org;
}
