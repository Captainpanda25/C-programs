#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct allnode
{
char name[20];
struct allnode *next;
};
typedef struct allnode *t;
t tail=NULL;
void addnote(t newnode)
{
if(tail==NULL)
{
tail=newnode;
newnode->next=tail;
}
else
{
newnode->next = tail->next;
tail->next = newnode;
tail=newnode;
}
}
int main()
{
int i;
char players[10][10]={"player1","player2","player3","player4"};
t current;
for(i=0;i<4;i++)
{
t newnode;
newnode=(t)malloc(sizeof(struct allnode));
strcpy(newnode->name,players[i]);
addnote(newnode);
}
if(tail!=NULL)
{
current=tail->next;
while(1)
{
printf("its your turn \n");
puts(current->name);
printf("next \n");
sleep(3);
current=current->next;
}
current=tail;
printf("its your turn \n");
puts(current->name);
printf("next \n");
sleep(3);
current=NULL;
}
}



