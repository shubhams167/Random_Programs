#include<stdio.h>

struct stdinfo
{
	char name[20];
	int roll,Class,fees;
}s;

int main()
{
	FILE *f=fopen("text.txt","w");
	if(f==NULL)
	{
		printf("File cannot be opened!");
		exit(0);
	}
	char more = 'y';
	printf("Enter details of students: ");
	while(more == 'y')
	{
		scanf("%d",&s.roll);
		fflush(stdin);
		fgets(s.name,20,stdin);
		fprintf(f,"%d",s.roll);
		fputs(s.name,f);
		printf("Enter more?(y): ");
		more = getche();
	}
	fclose(f);
}
