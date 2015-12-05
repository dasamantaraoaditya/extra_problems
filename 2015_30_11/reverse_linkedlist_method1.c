//4.a.Reverse an Linked list , using recursion 1st approaches 
#include<stdio.h>
#include<stdlib.h>
void verify_testcases();
struct node * create_linkedlist(int items[]);
struct node * insert_at_end(struct node *end,int item);
int verify_output(struct node * ,int * );
struct node * reverse_linkedlist_method2(struct node * start,struct node * hhead);
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
	
	struct node *head2,*hhead=NULL;
	for(i=0;i<8;i++)
	{
		head2=create_linkedlist(testcases[i].input);
		reverse_linkedlist_method2(head2,hhead);

	
		if(verify_output(hhead,testcases[i].output))
		printf("\n2PASSED,");
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



struct node * reverse_linkedlist_method2(struct node *list1,struct node * hhead)
{
	struct node * end;
	if(list1==NULL)
	return NULL;
	if(list1->next==NULL)
	{
		hhead=list1;
		return ;
	}
	reverse_linkedlist_method2(list1->next,hhead);
	end=list1->next;
	end->next=list1;
	list1->next=NULL;
	
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
