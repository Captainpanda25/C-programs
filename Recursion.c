#include<stdio.h>
#include<stdlib.h>
int week=0;
int loan(int value)
{
if(value<=0)
{
week++;
return(week);
}
else 
{
week++;
}
printf("Loan repayed in %d week(s) is %d\n",week,value);
return loan(value-20);
}
int main()
{
int n=0;
printf("Selena loan amount is $210\n");
n=loan(210);
printf("selena repays $210 in %d weeks",n);
return 0;
}

