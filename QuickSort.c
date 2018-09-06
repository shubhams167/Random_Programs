/**********************************************************************
*	This program is an implementation of quick sort algorithm.
*
*	Author: Shubham Singh
*	Date:	07 Sep 2018
**********************************************************************/

#include<stdio.h>

/**************************************************************************************************
*	Function:	Swaps passed formal arguments.
*	Input:		Two parameters: Two pointer-to-int to store address of two variables passed.
*	Output:		None.
**************************************************************************************************/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**************************************************************************************************
*	Function:	Creates partition around pivot element.
*	Input:		Three parameters: Array to partition, left index and right index
*	Output:		Index of sorted pivot element.
**************************************************************************************************/
int partition(int *a, int l, int r)
{
	int pivot = a[l], i = l, j = r + 1;//Select first element as pivot
	while(i < j)
	{
		do
		{
			j--;
		}while(pivot < a[j]);
		do
		{
			i++;
		}while(pivot > a[i]);
		if(i < j)
			swap(&a[i], &a[j]);
	}
	swap(&a[l], &a[j]);//Swap piot element with a[j]
	return j;
}

/**************************************************************************************************
*	Function:	To perform quick sort on array. 
*	Input:		Three parameters: Array to sort, left and right index of array.
*	Output:		None.
**************************************************************************************************/
void quickSort(int *a, int l, int r)
{
	int j;
	if(l < r)
	{
		j = partition(a, l, r);
		quickSort(a, l, j - 1);
		quickSort(a, j + 1, r);
	}
}

int main()
{
	int a[] = {20, 5, 23, 67, 20, 40, 30, 60}, n;
	n = sizeof(a)/sizeof(a[0]);
	quickSort(a, 0, n - 1);
	printf("Sorted array is: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
