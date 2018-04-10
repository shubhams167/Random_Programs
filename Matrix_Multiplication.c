//														MATRIX MULTIPLICATION
//Last edit 21:00, 10-04-2018 by Shubham_Singh

#include<stdio.h>

int main()
{
	int a[10][10],b[10][10],c[10][10],n,temp,sum=0,ic=0,jc=0;
	
	printf("Enter size of square matrices: ");
	scanf("%d",&n);
	
	printf("Enter matrix A: \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	
	printf("Enter matrix B: \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&b[i][j]);
	}
	
	for(int ia=0;ia<n;ia++)
	{
		for(int i=0;i<n;i++)
		{
		
			for(int ja=0;ja<n;ja++)
			{
				temp=a[ia][ja]*b[ja][i];
				sum+=temp;
			}
			c[ic][jc]=sum;
			sum=0;jc++;
		}
		ic++;jc=0;
	}
		
	printf("AxB=\n")
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
