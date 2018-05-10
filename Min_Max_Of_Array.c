					/* 	Minimum and Maximum element of an array	*/

#include<stdio.h>

void min_max_array(int *a)
{
	int min,max;
	min = max = a[0];
	for(int i=0;i<10;i++)
	{
		if(a[i]<min)
			min = a[i];		
		if(a[i] > max)
			max = a[i];
	}
	printf("Maximum element of array = %d",max);	
	printf("\nMinimum element of array = %d",min);
}

int main()
{
	int arr[10];
	for(int i=0;i<10;i++)
		scanf("%d",&arr[i]);
	min_max_array(arr);
	return 0;
}
