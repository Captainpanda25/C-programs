#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node* left;
struct node* right;
};
typedef struct node *t;
t root=NULL;
t insert(t ,int );
void inorder(t );
void preorder(t );
void postorder(t );
int main()
{
int i,n,x;
printf("how many datas do you want to enter : \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("data %d ",i+1);
scanf("%d",&x);
root=insert(root,x);
}
printf("inorder traversal \n");
inorder(root);
printf("\npreorder traversal \n");
preorder(root);
printf("\npostorder traversal \n");
postorder(root);
return 0;
}
t insert(t r,int x)
{
if(r==NULL)
{
r=(t)malloc(sizeof(struct node));
r->info=x;
r->left=NULL;
r->right=NULL;
}
else if(x<r->info)
{
r->left=insert(r->left,x);
}
else 
{
r->right=insert(r->right,x);
}
return r;
}
void inorder(t r)
{
if(r!=NULL)
{
inorder(r->left);
printf("%d\t",r->info);
inorder(r->right);
}
}
void preorder(t r)
{
if(r!=NULL)
{
printf("%d\t",r->info);
preorder(r->left);
preorder(r->right);
}
}
void postorder(t r)
{
if(r!=NULL)
{
postorder(r->left);
postorder(r->right);
printf("%d\t",r->info);
}
}

