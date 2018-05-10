#include<stdio.h>

struct stdinfo
{
	char name[20];
	int roll,Class,fees;
}s;

int main()
{
	FILE *f=fopen("text.txt","r");
	if(f==NULL)
	{
		printf("File cannot be opened!");
		exit(0);
	}
	char more = 'y';
	printf("Enter details of students: \n");
	while(fscanf(f,"%d",&s.roll)!=EOF)
	{
		fgets(s.name,20,f);
		printf("%d ",s.roll);
		puts(s.name);	
	}
	fclose(f);
}
