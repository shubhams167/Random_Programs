#include<stdio.h>
#include<windows.h>
#include<string.h>

int main()
{
	FILE *f;
	f=fopen("text.txt","r");
	if(f==NULL)
	{
		printf("File cannot be opened!");
		exit(0);
	}
	char s[50],word[50];
	int flag=0;
	printf("Enter word to scan: ");
	scanf("%s",word);
	while(fscanf(f,"%s",s)!=EOF)
	{
		printf("%s\n",s);
		if(strcmp(s,word)==0)
			flag++;
	}
	fclose(f);
	if(flag)
		printf("'%s' occurs %d times in file",word,flag);
	else
		printf("'%s' doesn't exist in file",word);
}
