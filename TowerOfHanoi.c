#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
struct Stack
{
int capacity;
int top;
int *array;
};
typedef struct Stack *train;
train createstack(int capacity)
{
train stack=(train)malloc(sizeof(struct Stack));
stack->capacity=capacity;
stack->top=-1;
stack->array=(int *)malloc(stack->capacity*sizeof(int));
return stack;
}
int isfull(train stack)
{
return (stack->top==stack->capacity-1);
}
int isempty(train stack)
{
return (stack->top==-1);
}
void push(train stack, int car)
{
if(isfull(stack))
return;
else
stack->array[++stack->top]=car;
}
int pop(train stack)
{
if(isempty(stack))
return INT_MIN;
return stack->array[stack->top--];
}
void movecar(char from,char to,int car)
{
printf("Move the car %d from %c to %c\n",car,from,to);
}
void movecarsb2t(train src, train dest,char s, char d)
{
int track1topcar = pop(src);
int track2topcar = pop(dest);
if(track1topcar==INT_MIN)
{
push(src,track2topcar);
movecar(d,s,track2topcar);
}
else if(track2topcar==INT_MIN)
{
push(dest,track1topcar);
movecar(s,d,track1topcar);
}
else if(track1topcar>track2topcar)
{
push(src,track1topcar);
push(src,track2topcar);
movecar(d,s,track2topcar);
}
else
{
push(dest,track2topcar);
push(dest,track1topcar);
movecar(s,d,track1topcar);
}
}
void freight(int numofcars,train src,train aux,train dest)
{
int i, total;
char s='T', d='O',a='H';
if(numofcars%2==0)
{
char temp=d;
d=a;
a=temp;
}
total = pow(2,numofcars)-1;
for(i=numofcars;i>=1;i--)
push(src,i);
for(i=1;i<=total;i++)
{
if(i%3==1)
movecarsb2t(src,dest,s,d);
else if(i%3==2)
movecarsb2t(src,aux,s,a);
else if(i%3==0)
movecarsb2t(aux,dest,a,d);
}
}
int main()
{
int numofcars=4;
train src,dest,aux;
src=createstack(numofcars);
aux=createstack(numofcars);
dest=createstack(numofcars);
freight(numofcars,src,aux,dest);
return 0;
}


