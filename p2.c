#include<stdio.h>                 //new code again
int s; 
void rec(int b[100])
{
int i,count=-1,j=0,a[50];
for(i=8;i<s-8;i++)
{
if(count==-1&&b[i]==1)
{
a[j]=b[i];
j++;
}
else if(count!=-1&&b[i]==1)
{
a[j]=b[i];
j++;
count++;
}
else if(b[i]==0&&count!=5)
{
a[j]=b[i];
j++;
count=0;
}
else if(count==5)
{
count=0;
}
}
printf("The data recieved after removing flags,header and trailer:\n");
for(i=0;i<j;i++)
{
printf("%d\n",a[i]);
}
}

int main()
{
int i,count,j,k,n,a[50],b[50],c[50];
int f[100];
printf("Enter the number of bits to be sent:\n");
scanf("%d",&n);
printf("Enter the data for each bit:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
c[0]=0;
c[1]=1;
c[2]=1;
c[3]=1;
c[4]=1;
c[5]=1;
c[6]=1;
c[7]=0;
j=0;
count=-1;
for(i=0;i<n;i++)
{
if(a[i]==1&&count!=-1)
{
b[j]=a[i];
count++;
if(count==5)
{
j++;
b[j]=0;
count=0;
}
j++;
}
else if(a[i]==1&&count==-1)
{
b[j]=a[i];
j++;
}
else if(a[i]==0)
{
b[j]=a[i];
j++;
count=0;
}
}
printf("Data after stuffing (if required) :\n");
for(i=0;i<j;i++)
printf("%d\n",b[i]);
k=8;
printf("Entire frame to be sent\n");
for(i=0;i<k;i++)
{
f[i]=c[i];
}
for(i=0;i<j;i++,k++)
{
f[k]=b[i];
}
for(i=0;i<8;i++,k++)
{
f[k]=c[i];
}
for(i=0;i<k;i++)
printf("%d\n",f[i]);
printf("\n");
s=k;
rec(f);
return 0;
}

