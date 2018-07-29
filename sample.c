#include<stdio.h>
int main()
{
int a,b,c;
char str[10];
scanf("%d%d",&a,&b);
if(a<10000&&b<a)
{
c=a-b;
sprintf(str,"%d",c);
if(str[0]=='1')
str[0]='8';
else
str[0]=str[0]-1;
printf("%s",str);
}
return 0;
} 
