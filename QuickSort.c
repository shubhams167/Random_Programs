/**********************************************************************
*	This program is an implementation of quick sort algorithm.
*
*	Author: Shubham Singh
*	Date:	22 Oct 2018
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
	int pivot = a[r], i = l - 1, j;//Select last element as pivot
	for(j = l; j < r; j++)
	{
		if(a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[r]);//Swap pivot element with a[i + 1]
	return i + 1;
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

/*Driver code*/
int main()
{
	int a[] = {20, 5, 23, 67, 20, 40, 30, 60}, n;
	n = sizeof(a)/sizeof(a[0]);
	printf("Unsorted array is: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	quickSort(a, 0, n - 1);
	printf("\nSorted array is: ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
