#include<stdio.h>
int main()
{
int i,temp;
char a[10],b[10];
printf("Enter two strings\n");
scanf("%s%s",a,b);
int g=strlen(a);
temp=0;
for(i=0; a[i]!='\0',b[i]!='\0'; i++)
{
if(a[i] == b[i])
temp++;
else
break;
}
if(temp == g)
printf("Both strings are same.");
else
printf("Both strings are not same.");
return 0;
}


