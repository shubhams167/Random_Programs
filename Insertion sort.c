/*
*	C program to implement in-place insertion sort
*/

#include<stdio.h>

/*******************************************************	
*	Function: 	Perform insertion sort on given array
*	Input:		Array to sort and size of array
*	Output:		None
*******************************************************/
void insertionSort(int *arr, const int size)
{
	int val, j;
	for(int i = 1; i < size; i++)
	{
		val = arr[i];
		j = i - 1;
		/*Shift all elements which are greater then val on left side of arr[i] to right by one index*/
		while(val < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		/*Insert val to it's appropriate position after shifting of elements*/
		arr[j + 1] = val;
	}
}

int main()
{
	int arr[] = {5, 3, 8, 9, 4, 15, 6, 7, 5, 10, 8}, size;
	size = sizeof(arr)/sizeof(int);
	insertionSort(arr, size);
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}
