//6.Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
//Ex: Input 1->2->3->4 and 1->2->3->4
//Output 2->4->6->8
#include<stdio.h>
#include<stdlib.h>
struct node *create_linkedlist(int * item);
struct node * add_list(struct node *list1,struct node * list2);
void equalize_linkedlist(struct node *list1,struct node *list2);
struct node * reverse_linkedlist(struct node * list,struct node * before);
int compare(struct node * output1,int *output2);
void verify_testcases();
struct node 
{
	int data;
	struct node *next;
};
struct testcases
{
	int input1[10];
	int input2[10];
	int output[20];
}test[10]={
	{{1},{2},{3}},
	{{1,2,3,4},{1,2,3,4},{2,4,6,8}},
	{{9,9},{9,9},{1,9,8}},
	{{1,2},{1},{1,3}},
	{{3},{1,2},{1,5}},
	{{1,1,1,1,1,1,1,1},{1},{1,1,1,1,1,1,1,2}},
	{{9},{9},{1,8}},
	{{1,2,3},{},{1,2,3}},
	{{},{3,5,6},{3,5,6}},
	{{},{},{}},
};
void verify_testcases()
{
	int i;
	struct node *list1,*list2;
	for(i=0;i<10;i++)
	{
		
		list1=create_linkedlist(test[i].input1);
		list2=create_linkedlist(test[i].input2);		
		list1=add_list(list1,list2);
		if(compare(list1,test[i].output))
			printf("\npassed");
		else
			printf("\nfailed");
	}
}
int compare(struct node * output1,int *output2)
{
	int i=0;
	while(output1!=NULL)
	{
		if(output1->data==output2[i++])
		output1=output1->next;
		else
		return 0;
	}
	return 1;
}
int main()
{
	verify_testcases();
	return 0;
}
struct node *create_linkedlist(int * item)
{
	int i=1;
	struct node * start,*end=NULL;
	end=(struct node * )malloc (sizeof(struct node));
	if(item!='\0')
	{
		
		end->data=item[0];
		end->next=NULL;
	}
	start=end;
	while(item[i]!='\0') 
	{
		struct node * temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item[i];
		temp->next=NULL;
		end->next=temp;
		end=temp;
		i++;
	}
	return start;
}
struct node * add_list(struct node *list1,struct node * list2)
{
	int sum,carry=0;
	struct node * num1,*num2,*result;
	result=num1=list1=reverse_linkedlist(list1,NULL);
	num2=list2=reverse_linkedlist(list2,NULL);
	equalize_linkedlist(num1,num2);
	while(list1->next!=NULL)
	{
		sum=list1->data+list2->data;
		list1->data=(sum+carry)%10;
		carry=sum/10;
		list1=list1->next;
		list2=list2->next;
	}
	sum=list1->data+list2->data;
		list1->data=(sum+carry)%10;
		carry=sum/10;
		if(carry)
		{
			struct node * temp=(struct node *)malloc (sizeof(struct node));
			temp->data=1;
			temp->next=NULL;
			list1->next=temp;
		}
		
		result=reverse_linkedlist(result,NULL);
	return result;
}
void equalize_linkedlist(struct node *list1,struct node *list2)
{
	while(list1->next!=NULL||list2->next!=NULL)
	{
		if(list1->next==NULL)
		{
			struct node * temp=(struct node *)malloc(sizeof(struct node));
			temp->data=0;
			temp->next=NULL;
			list1->next=temp;
		}
		if(list2->next==NULL)
		{
			struct node * temp=(struct node *)malloc(sizeof(struct node));
			temp->data=0;
			temp->next=NULL;
			list2->next=temp;
		}
		list1=list1->next;
		list2=list2->next;
	}	
}

struct node * reverse_linkedlist(struct node * list,struct node * before)
{
	if(list==NULL)
	return before;
	struct node * next_node=list->next;
	list->next=before;
	reverse_linkedlist(next_node,list);
}
