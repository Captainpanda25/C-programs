#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *lt,*rt;
}*start = NULL;
typedef struct node *t;
void insertcars(int *x)
{
t new;
new = (t)malloc(sizeof(struct node));
new->info=*x;
if(start==NULL)
new->lt=new->rt=NULL;
else
{
new->rt=start;
start->lt=new;
}
start=new;
}
void insertlt(int *x, int *key)
{
t new, p=start;
int flag=0;
while(p!=NULL)
{
if(p->info==*key)
{
flag=1;
break;
}
p=p->rt;
}
if(flag==1)
{
new = (t)malloc(sizeof(struct node));
new->info=*x;
new->rt=new->lt=NULL;
if(p==start)
{
new->rt=p;
p->lt=new;
start=new;
return;
}
new->rt=p;
new->lt = p->lt;
p->lt->rt=new;
p->lt=new;
}
else 
printf("\n Car not present\n");
}
void droppedoff(int *key)
{
t p=start;
while(p!=NULL)
{
if(start==NULL)
{
printf("\nNo cars available\n");
return;
}
if(p->info==*key&&p==start)
{
start=start->rt;
start->lt = NULL;
free(p);
}
if(p->info==*key)
{
p->lt->rt=p->rt;
p->rt->lt=p->lt;
free(p);
}
p=p->rt;
}
}
void showtrain()
{
t p=start;
while(p!=NULL)
{
printf("%d\t",p->info);
p=p->rt;
}
}
int main()
{
int ch, no,key;
while(ch!=5)
{
printf("1.Insert from front\n");
printf("2.Insert left of previous car\n");
printf("3.Dropped of car number\n");
printf("4.Show cars\n");
printf("5.Exit\n");
printf("Enter choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter car no\n");
scanf("%d",&no);
insertcars(&no);
break;
case 2: printf("Enter car no\n");
scanf("%d",&no);
printf("Enter car no to be linked\n");
scanf("%d",&key);
insertlt(&no,&key);
break;
case 3: printf("Enter car no to be dropped\n");
scanf("%d",&key);
droppedoff(&key);
break;
case 4: showtrain();
printf("\n");
break;
case 5: exit(0);
default: printf("Invalid ch\n");
break;
}
}
return 0;
}

