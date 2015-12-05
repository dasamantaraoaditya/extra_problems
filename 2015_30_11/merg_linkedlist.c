//2.Merge two linked list which are in sorted order
#include<stdio.h>
#include<stdlib.h>
void verify_testcases();
struct node * create_linkedlist(int items[]);
struct node * insert_at_end(struct node *end,int item);
int verify_output(struct node * ,int * );
struct node * merg_linkedlist_method1(struct node * ,struct node * );
struct node * merg_linkedlist_method2(struct node * ,struct node * );
struct node
{
	int data;
	struct node * next;
};
struct testcases
{
	int input1[10];
	int input2[10];
	int output[20];
}testcases[10]={
{{1,2,3,4,5,6,7},{4},{1,2,3,4,4,5,6,7}},
{{1,3,4,5,6,9},{2,5,6,11,13,20},{1,2,3,4,5,5,6,6,9,11,13,20}},
{{50,51},{3,8},{3,8,50,51}},
{{-50,-3,-2,-1,2,3,4,5,6},{-101},{-101,-50,-3,-2,-1,2,3,4,5,6}},
{{90,100},{101,102},{90,100,101,102}},
{{1,1,1,1,1,1,1},{-1,1,2,3,4},{-1,1,1,1,1,1,1,1,1,2,3,4}},
{{-5,-2,-1,5,9,11},{-3,3,100},{-5,-3,-2,-1,3,5,9,11,100}},
{{1},{},{1}},
{{},{1,2,3,},{1,2,3}},
{{},{},{}},
};
int main()
{
	verify_testcases();
	return 0;
}
void verify_testcases()
{
	int i;
	struct node *head1,*head2,*result;
	for(i=0;i<10;i++)
	{
		head1=create_linkedlist(testcases[i].input1);
		head2=create_linkedlist(testcases[i].input2);
		
		result=merg_linkedlist_method1(head1,head2);
	
		if(verify_output(result,testcases[i].output))
		printf("1PASSED,");
		else
		printf("1FAILED,");
		
		result=merg_linkedlist_method2(head1,head2);
	
		if(verify_output(result,testcases[i].output))
		printf("2PASSED\n");
		else
		printf("2FAILED\n");
		
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



struct node * merg_linkedlist_method2(struct node *list1,struct node *list2)
{
	struct node *result1,*result2=NULL;
	
	if(list1==NULL&&list2!=NULL)
	return list2;
	if(list2==NULL&&list1!=NULL)
	return list1;
	if(list1==NULL&&list2==NULL)
	return NULL;
	
	if(list1!=NULL&&list2!=NULL)
	{
		if(list1->data<list2->data)
		{
			result1=list1;
			list1=list1->next;
		}
		else
		{
		
			result1=list2;
			list2=list2->next;
		}
	}
	result2=result1;
	while(list1!=NULL&&list2!=NULL)
	{
		if(list1->data<list2->data)
		{
			result2->next=list1;
			list1=list1->next;
		}
		else
		{
			result2->next=list2;
			list2=list2->next;
		}
		result2=result2->next;
	}
	if(list1!=NULL)
	result2->next=list1;
	if(list2!=NULL)
	result2=list2;
	return result1;
}

struct node * merg_linkedlist_method1(struct node *list1,struct node *list2)
{
	struct node *result1,*result2=NULL;
	
	if(list1==NULL&&list2!=NULL)
	return list2;
	if(list2==NULL&&list1!=NULL)
	return list1;
	if(list1==NULL&&list2==NULL)
	return NULL;
	
	if(list1!=NULL&&list2!=NULL)
	{
		result2=(struct node *)malloc(sizeof(struct node));
		if(list1->data<list2->data)
		{
			result2->data=list1->data;
			list1=list1->next;
		}
		else
		{
		
			result2->data=list2->data;
			list2=list2->next;
		}
		result2->next=NULL;
	}
	result1=result2;
	while(list1!=NULL&&list2!=NULL)
	{
		if(list1->data<=list2->data)
		{
			result2=insert_at_end(result2,list1->data);
			list1=list1->next;
		}
		else
		{
			result2=insert_at_end(result2,list2->data);
			list2=list2->next;
		}
	}
	while(list1!=NULL)
	{
		result2=insert_at_end(result2,list1->data);
			list1=list1->next;
	}
	while(list2!=NULL)
	{
		result2=insert_at_end(result2,list2->data);
			list2=list2->next;
	}
	
	return result1;
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
