//10. Print the last n lines of a file
#include<stdio.h>
#include<stdlib.h>
void print_last_nlines(char * f_name,int n);
int main()
{
	char f_name[30];
	int n;
	printf("\nENETR THE FILE NAME : ");
	gets(f_name);
	printf("\nENTER n : ");
	scanf("%d",&n);
	print_last_nlines(f_name,n);	
	return 0;
}
void print_last_nlines(char * f_name,int n)
{
	FILE *fp_dup,*fp_org;
	char ch;
	int counter1=0,counter2=0;
	fp_dup=fopen(f_name,"r");
	fp_org=fopen(f_name,"r");
	if(fp_org==NULL)
	{
		printf("UNABLE to OPEN FILE");
		exit(0);
	}
	while(!feof(fp_org))
	{
		if(fgetc(fp_org)=='\n')
		counter1++;
	}
	counter2=counter1-n;
		while(!feof(fp_dup))
	{
		ch=fgetc(fp_dup);
		if(ch=='\n')
		counter2--;
		if(counter2<=0)
		printf("%c",ch);
	}
	fclose(fp_dup);
	fclose(fp_org);
}
