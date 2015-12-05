//6.Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
//Ex: Input 1->2->3->4 and 1->2->3->4
//Output 2->4->6->8
#include<stdio.h>
#include<stdlib.h>
struct node *create_linkedlist(int * item);
void add_linkedlist_recursion(struct node * list1,struct node * list2,int * carry);
struct node * add_linkedlist_method2(struct node *list1,struct node * list2);
int length(struct node * list);
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
		list1=add_linkedlist_method2(list1,list2);
	
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

struct node * add_linkedlist_method2(struct node *list1,struct node *list2)
{
	struct node *new_list1=list1,*new_list2=list2;
	int length1=length(new_list1),length2=length(new_list2),len,carry=0;
	if(length1!=length2)
	{
		if(length1<length2)
		{
			while(length1!=length2)
			{
				struct node * temp=(struct node *)malloc(sizeof(struct node));
				temp->data=0;
				temp->next=list1;
				list1=temp;length1++;
			}
		}
		else
		{
			while(length1!=length2)
			{
				struct node * temp=(struct node *)malloc(sizeof(struct node));
				temp->data=0;
				temp->next=list2;
				list2=temp;length2++;
			}
		}
	}
	add_linkedlist_recursion(list1,list2,&carry);
	if(carry)
	{
		struct node * temp=(struct node *)malloc(sizeof(struct node));
		temp->data=1;
		temp->next=list1;
		list1=temp;
	}
	return list1;
}
int length(struct node * list)
{
	int length=0;
	while(list!=NULL)
	{
		list=list->next;
		length++;
	}
	return length;
}
void add_linkedlist_recursion(struct node * list1,struct node * list2,int *carry)
{
	int sum=0;
	if(list1==NULL)
	*carry=0;
	else
	{
		add_linkedlist_recursion(list1->next,list2->next,carry);
		sum=list1->data+list2->data;
		list1->data=(sum+*carry)%10;
		*carry=sum/10;
	}
}





