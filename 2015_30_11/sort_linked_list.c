/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
void swap(struct node *a, struct node *b);
void insert_at_end(struct node *inter);
struct node * sortLinkedList(struct node *head) {
  int swapped, i;
    struct node *ptr1,*start;
    struct node *lptr = NULL;
 	start=head;
    /* Checking for empty list */
    if (ptr1 == NULL)
        return NULL;
 	if(start==NULL)
 	return NULL;
    do
    {
        swapped = 0;
        ptr1 = head;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->num > ptr1->next->num)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    return start;
}

void swap(struct node *a, struct node *b)
{
    int temp = a->num;
    a->num = b->num;
    b->num = temp;
}
int main()
{
	struct node *start=NULL,*end=NULL,*head=NULL;
	int len,i,k;
	scanf("%d",&len);
	end=(struct node *)malloc(sizeof(struct node));
	start=end;
	scanf("%d",&end->num);
	end->next=NULL;
	for(i=1;i<len;i++)
	{
	insert_at_end(end);
	}
	head=start;
start=sortLinkedList(head);
	for(i=0;start!='\0';i++)
	{
		printf("%d",start->num);
		start=start->next;
	}
	return 0;
}
void insert_at_end(struct node *inter)
{
	struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&temp->num);
		temp->next=NULL;
		while(inter->next!=NULL)
		inter=inter->next;
		inter->next=temp;
	
}
