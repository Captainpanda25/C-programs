#include<stdio.h>
void swap(int* a, int* b)
{
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}

int main()
{
int a,b;
printf("Enter 2 numbers to be swapped:\na = ");
scanf("%d",&a);
printf("b = ");
scanf("%d",&b);
swap(&a,&b);
printf("\nSwapped numbers are: a = %d b = %d\n",a,b);
return 0;
}
