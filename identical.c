#include<stdio.h>
#include<string.h>
{
char a[10],b[10];
printf("Enter two strings\n");
scanf("%s%s",a,b);
if(strcmp(a,b)==0)
printf("Strings are identical");
else 
printf("Strings are not identical");
}

