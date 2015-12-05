//5.Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
//Ex , n1=3 ,n2=5 and r=5, The merged table is 3,5,6,9,10,12,15(One more 15 is removed as its duplicate ) 18,20,21,24,25........so on .
//The rth num ie 5th number is 12 ,so OP is 12
#include<stdio.h>
#include<stdlib.h>
int find_rth_element_method2(int n1,int n2,int r);
struct testcases
{
	int n1;
	int n2;
	int r;
	int output;
}test[9]={
	{5,3,8,18},
	{0,1,8,0},
	{11,13,3,22},
	{16,5,6,25},
	{9,0,11,0},
	{9,9,9,81},
	{21,100,10,189},
	{0,0,20,0},
	{13,6,11,48},
};
int merg_tables(int * table1,int *table2,int r);
void verify_testcases();

int main()
{
	verify_testcases();
	return 0;
}
int * create_table(int n1,int r)
{
	int * table=(int *)malloc(sizeof(int)*r),i;
	table[0]=n1;
	for(i=1;i<r;i++)
	table[i]=n1+table[i-1];
	return table;
}
void verify_testcases()
{
	
	int val,i,*table_n1,*table_n2;
	for(i=0;i<9;i++)
	{
		table_n1=create_table(test[i].n1,test[i].r);
		table_n2=create_table(test[i].n2,test[i].r);
		
		val=merg_tables(table_n1,table_n2,test[i].r);
		//printf("%d",val);
		if(val==test[i].output)
		printf("\n1PASSED");
		else
		printf("\n1FAILED");
		val=find_rth_element_method2(test[i].n1,test[i].n2,test[i].r);
		//printf("%d",val);
		if(val==test[i].output)
		printf(",2PASSED");
		else
		printf(",2FAILED");
		
	}
}
int merg_tables(int * table1,int *table2,int r)
{
	int counter1=0,counter2=0,val=0;
	while(r)
	{
		if(table1[counter1]<table2[counter2])
		{
			val=table1[counter1];
			r--;
			counter1++;
		}
		else if(table1[counter1]>table2[counter2])
		{
			val=table2[counter2];
			r--;
			counter2++;
		}
		else
		{
			r--;
			val=table1[counter1];
			counter1++;
			counter2++;
		}
	}
	return val;
}

int find_rth_element_method2(int n1,int n2,int r)
{
	int org_val=0,n1_val=n1,n2_val=n2;

	while(r)
	{
		while(n1_val<n2_val&&r)
		{
			org_val=n1_val;
			n1_val+=n1;
			r--;
		}
		while(n1_val>n2_val&&r)
		{
			org_val=n2_val;
			n2_val+=n2;
			r--;
		}
		if(n1_val==n2_val)
		{
			org_val=n1_val;
			n1_val+=n1;
			n2_val+=n2;
			r--;
		}
	}
	return org_val;
}
