#include<stdio.h>
int main()
{
int a[20],i,count;
printf("Enter 15 numbers \n");
for(i=0;i<15;i++)
{
scanf("%d",&a[i]);
}
count=0;
for(i=0;i<15;i++)
{
if(a[i]%3==0)
printf("%d is divisible by 3\n",a[i]);
count++;
}
if(count==0)
printf("No number is divisble by 3");
return 0;
}

