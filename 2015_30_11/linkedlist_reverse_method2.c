//4.Reverse an Linked list , using recursion method 2
#include<stdio.h>
#include<stdlib.h>
void verify_testcases();
struct node * create_linkedlist(int items[]);
struct node * insert_at_end(struct node *end,int item);
int verify_output(struct node * ,int * );
struct node * reverse_linkedlist_method1(struct node * start,struct node *before);
struct node
{
	int data;
	struct node * next;
};
struct testcases
{
	int input[20];
	int output[20];
}testcases[8]={
{{1,2,3,4,5,6,7},{7,6,5,4,3,2,1}},
{{1,3,4,5,6,9},{9,6,5,4,3,1}},
{{50,51},{51,50}},
{{-50,-3,-2,-1,2,3,4,5,6},{6,5,4,3,2,-1,-2,-3,-50}},
{{1,1,1,1,1,1,1},{1,1,1,1,1,1,1}},
{{101,56,965,-52,-3,2,1,6},{6,1,2,-3,-52,965,56,101}},
{{1},{1}},
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
	
	struct node *head1,*result,*before=NULL;
	struct node * hhead=NULL,*var;
	for(i=0;i<8;i++)
	{
		head1=create_linkedlist(testcases[i].input);
		
		
		result=reverse_linkedlist_method1(head1,before);
	
		if(verify_output(result,testcases[i].output))
		printf("1PASSED\n");
		else
		printf("1FAILED\n");
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




struct node * reverse_linkedlist_method1(struct node *list,struct node *before)
{
	if(list==NULL)
	{
		return before;
	}
	else
	{
		struct node * NEXT;
		NEXT=list->next;
		list->next=before;
		reverse_linkedlist_method1(NEXT,list);
	}
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
