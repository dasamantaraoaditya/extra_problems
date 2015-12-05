//9 . Largest Contiguous Sum Array .
//Ex : 1,2,3,5,-10,20,40 O/P : 20,40 Sum : 60
//Ex: 1 2 3 4 5 -2 -3 -4 -20 10 2 O/:P:1 2 3 4 5 Sum:15
#include<stdio.h>
#include<stdlib.h>
int * largest_contineous_sum(int * array,int * sum);
void verify_testcases();
int verify_output(int * output1,int * output2);
struct testcases
{
	int input[20];
	int output[20];
	int sum;
}test[10]=
{
	{{1,2,3},{1,2,3},6},
	{{1,-2,2,5},{2,5},7},
	{{6,8,-11,5,6},{6,8},14},
	{{6,8,9,-50,11,6,8,-30,22},{11,6,8},25},
	{{-11,-12,-3,-2,9},{9},9},
	{{9,-8,7,-6,5,-4,3,-2,1},{9},9},
	{{1,2,3,4,5,-10,5,4,-13,2,1},{1,2,3,4,5},15},
	{{1,2,-10,5,6,11,-20,1,-4},{5,6,11},22},
	{{9,8,7,-18,-5,-4,3,2,10,15,-2,-17,3,6,8},{3,2,10,15},30},
	{{1},{1},1},
};
int j;
int main()
{
	verify_testcases();
	return 0;
}
void verify_testcases()
{
	int * output1,sum,i;
	for(i=0;i<10;i++)
	{
		output1=largest_contineous_sum(test[i].input,&sum);
		if(sum==test[i].sum&&verify_output(output1,test[i].output))
		printf("\npassed");
		else
		printf("\nFAILED");
	}
}
int verify_output(int * output1,int * output2)
{
	int i=0;
	while(output1[i]!='\0')
	if(output1[i]==output2[i])
	i++;
	else
	return 0;
	return 1;
}
int * largest_contineous_sum(int * array,int * sum)
{
	int counter1,counter2,start,end,inter_sum,*result_array;
	*sum=-999999;
	for(counter1=0;array[counter1]!='\0';counter1++)
	{
		inter_sum=0;
		for(counter2=counter1;array[counter2]!='\0';counter2++)
		{
			inter_sum+=array[counter2];
			if(inter_sum>*sum)
			{
				*sum=inter_sum;
				start=counter1;
				end=counter2;
			}
		}
	}
	result_array=(int *)malloc(sizeof(int)*(end-start+1));
	for(counter1=0;start<=end;counter1++)
	result_array[counter1]=array[start++];
	result_array[counter1]='\0';
		
	return result_array;
}
