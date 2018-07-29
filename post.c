#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
float comp(char symb, float op1,float op2)
{
switch(symb)
{
case '+' : return(op1+op2);
case '-' : return(op1-op2);
case '*' : return(op1*op2);
case '/' : return(op1/op1);
case '^' : return(pow(op1,op2));
case '$' : return(pow(op1,op2));
}

}
int main()
{
int i ,top;
char symb, post[20];
float op1,op2,res,s[10];
top=-1;
printf("Enter the postfix\n");
scanf("%s",post);
for(i=0;i<strlen(post);i++)
{
symb=post[i];
if(isdigit(symb))
s[++top]=symb-'0';
else
{
op2=s[top--];
op1=s[top--];
res= comp(symb,op1,op2);
s[++top]=res;
}
}
res=s[top--];
printf("the result is %f ",res);
}


