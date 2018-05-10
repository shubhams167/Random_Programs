							/* 		BUBBLE SORT		*/
#include<stdio.h>

void bubble(int *a,int n)
{
	int flag=1,temp;
	while(flag==1)
	{
		flag=0;
		for(int i=0;i<n-1;i++)
		{			
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				flag=1;
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int *a=NULL;
	a=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubble(a,n);
	printf("Sorted Array is: ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);	
	free(a);
	return 0;
}
