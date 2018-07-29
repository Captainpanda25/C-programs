#include<stdio.h>
int main()
{
int i,temp;
char a[10],b[10];
printf("Enter two strings\n");
scanf("%s%s",a,b);
temp=0;
for(i=0; a[i]!='\0',b[i]!='\0'; i++)
{
if(a[i] == b[i])
temp++;
else
break;
}
if(temp == 0)
printf("Both strings are not same.");
else
printf("Both strings are same.");
return 0;
}


