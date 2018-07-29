#include<stdio.h>
#include<stdlib.h>
struct node
{
int data, key;
struct node *next, *prev;
};
typedef struct node *t;
t head =NULL;
t last =NULL;
void displayfor()
{
if(head!=NULL)
{
t ptr=head;
printf("\n[");
while(ptr!=NULL)
{
printf("(%d,%d)",ptr->key,ptr->data);
ptr=ptr->next;
printf(" ");
}
printf("]");
}
}
void displayback()
{
if(last!=NULL)
{
t ptr=last;
printf("\n[");
while(ptr!=NULL)
{
printf("(%d,%d)",ptr->key,ptr->data);
ptr=ptr->prev;
printf(" ");
}
printf("]");
}
}
void insertf(int key, int data)
{
t p=(t)malloc(sizeof(struct node));
p->data=data;
p->key=key;
if(head==NULL)
{
p->next=p->prev=NULL;
head=last=p;
}
else
{
t temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=p;
p->prev=temp;
last=p;
p->next=NULL;
}
}
void insertl(int key, int data)
{
t p=(t)malloc(sizeof(struct node));
p->key=key;
p->data=data;
if(head==NULL)
{
last=p;
}
else
{
last->next=p;
p->prev=last;
}
last=p;
}
t deletef()
{
t p=head;
if(head->next==NULL)
{
last=NULL;
}
else
{
head->next->prev=NULL;
}
head=head->next;
return p;
}
t deletel()
{
t p=last;
if(head->next==NULL)
{
head=NULL;
}
else
{
last->prev->next=NULL;
}
last=last->prev;
return p;
}
void inserta(int data, int newkey, int key)
{
t p=(t)malloc(sizeof(struct node));
p->data=data;
p->key=newkey;
t temp=head;
while(temp->data!=key)
{
printf("%d!!!!%d\n",temp->data,temp->key);
temp=temp->next;
if(temp==NULL)
return ;
}
if(temp->next==NULL)
{
last->next=p;
p->prev=last;
last=p;
}
else
{
p->next=temp->next;
(temp->next)->prev=p;
p->prev=temp;
temp->next=p;
}
return;
}
int main()
{
insertf(1,10);
insertf(2,20);
insertf(3,30);
insertf(4,1);
insertf(5,40);
insertf(6,56);
printf("\n list first to last:\n");
displayfor();
printf("\nlast to first:\n");
displayback();
printf("\n LIST AFTER deleting first record:\n");
deletef();
displayfor();
printf("\nlist after deleting last record:\n");
deletel();
displayfor();
printf("\nlist, insert after key(4):\n");
inserta(4,7,13);
displayfor();
return 0;
}
