#include<stdio.h>
#include<stdlib.h>
#define max 50
struct queue
{
int ele[max];
int rear;
};
void insert(struct queue *,int e);
int removeEle(struct queue *);
int isempty(struct queue *);
int isfull(struct queue *);
void displayqueue(struct queue *);
int menu();
int main()
{
int element,choice;
struct queue q;
q.rear=-1;
do
{
printf("\n 1.issue token number for the patient waiting for the doctor \n");
printf("\n 2.after consultation delete the token number from the queue \n");
printf("\n 3.display the token numbers assigned to the patients waiting in the queue \n");
printf("\n 4.exit \n");
printf("enter your choice \n");
scanf("%d",&choice);
switch(choice)
{
case 1: if(isfull(&q))
printf("\n appointments not avail \n");
else
{
printf("issue the token number \n");
scanf("%d",&element);
insert(&q,element);
}
break;

case 2: if(isempty(&q))
printf("appointments avail \n");
else
printf("consultation over for patient %d ",removeEle(&q));
break;

case 3:displayqueue(&q);
break;

case 4:exit(0);
break;

default :printf("enter your choice correctly \n");
break;
}
}
while(choice!=4);
}
void insert(struct queue *pq,int e)
{
pq->rear++;
pq->ele[pq->rear]=e;
}
int removeEle(struct queue* pq)
{
int elerem=pq->ele[0],i;
for(i=1;i<=pq->rear;i++)
pq->ele[i-1]=pq->ele[i];
pq->rear--;
return elerem;
}
int isfull(struct queue* pq)
{
if(pq->rear==(max-1))
return(1);
else
return(0);
}
int isempty(struct queue* pq)
{
if(pq->rear==-1)
return(1);
else
return(0);
}
void displayqueue(struct queue* pq)
{
int i;
if(isempty(pq))
printf("appoinmetns not avil \n");
else
{
printf("token number still waiting for doctors is ");
for(i=0;i<=pq->rear;i++)
printf("\t %d",pq->ele[i]);
}
}

