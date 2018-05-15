			/* 		Program to reverse a string using pointer		*/

#include<stdio.h>
#include<string.h>

main()
{
	char str[50],temp_str[50];
	int i;
	char *ptr = str;
	scanf("%s",str);
	ptr = ptr + strlen(str) - 1;
	for(i = 0;i<strlen(str);i++)
	{
		temp_str[i] = *ptr; 
		ptr--;
	}
	temp_str[i] = '\0';
	strcpy(str,temp_str);
	printf("%s",str);
}

