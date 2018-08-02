#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 50
typedef struct stack
{
int data[max];
int top;
}stack;
int precedence(char);
void init( stack* );
int empty( stack* );
int full( stack* );
int pop( stack* );
void push( stack* ,int);
int top(stack*);
void infixtoprefix(char infix[],char prefix[]);
void infixtopostfix(char infix[],char postfix[]);
int main()
{
char infix[30],postfix[30],prefix[30];
printf("enter the infix expression \n");
scanf("%s",infix);
infixtoprefix(infix,prefix);
infixtopostfix(infix,postfix);
printf("postfix expression is %s \n\nprefix expression is %s \n\n",postfix,prefix);
}

void infixtoprefix(char infix[],char prefix[])
{
int i,j;
char temp,in1[30];
for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
in1[j]=infix[i];
in1[j]='\0';
for(i=0;in1[i]!='\0';i++)
{
if(in1[i]=='(')
in1[i]=')';
else
if(in1[i]==')')
in1[i]='(';
}
infixtopostfix(in1,prefix);
for(i=0,j=strlen(prefix)-1;i<j;i++,j--)
{
temp=prefix[i];
prefix[i]=prefix[j];
prefix[j]=temp;
}
}

void infixtopostfix(char infix[],char postfix[])
{
stack s;
char x;
int i,j;
init(&s);
j=0;
char token;
for(i=0;infix[i]!='\0';i++)
{
token=infix[i];
if(isalnum(token))
postfix[j++]=token;
else
if(token=='(')
push(&s,'(');
else
if(token==')')
while((x=pop(&s))!='(')
postfix[j++]=x;
else
{
while(precedence(token)<=precedence(top(&s))&&!empty(&s))
{
x=pop(&s);
postfix[j++]=x;
}
push(&s,token);
}
}
while(!empty(&s))
{
x=pop(&s);
postfix[j++]=x;
}
postfix[j]='\0';
}
int precedence(char x)
{
if(x=='(')
return (0);
 if(x=='+'|| x=='-')
return (1);
 if(x=='*'|| x=='/'|| x=='%')
return (2);
else
return(3);
}
void init(stack* s)
{
s->top=-1;
}
int empty(stack* s)
{
if(s->top==-1) return(1);
return(0);
}
int full(stack* s)
{
if(s->top==max-1)return(1);
return(0);
}
void push(stack* s,int x)
{
s->data[++s->top]=x;
}
int pop(stack* s)
{
int x;
x=s->data[s->top--];
return(x);
}
int top(stack* p)
{
return(p->data[p->top]);
}

