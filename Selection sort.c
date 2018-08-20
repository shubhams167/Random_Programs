/*
*	Program to implement selection sort
*	Author:	Shubham Singh
*/

#include<stdio.h>

/*******************************************************	
*	Function: 	Perform selection sort on given array
*	Input:		Array to sort and size of array
*	Output:		None
*******************************************************/
void selectionSort(int *arr, const int size)
{
	int min, temp;
	for(int i = 0; i < size - 1; i++)
	{
		min = i;
		/*Find index of minimum element in unsorted part of array*/
		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		/*Swap minimum element with first element in unsorted part of array*/
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	int arr[] = {5, 3, 8, 9, 4, 15, 6, 7, 5, 10, 8}, size;
	size = sizeof(arr)/sizeof(int);
	selectionSort(arr, size);
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}
