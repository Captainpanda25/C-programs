#include<stdio.h>
int s;
void rec(int b[50])
{
int i,count=0,j=0,k,a[50];
for(i=0;i<s;i++)
{
if(b[i]==1)
{
for(k=i;k<s;k++)
{

if(count<5&&b[k]==1)
{
a[j]=b[k];
count++;
j++;
}

else if(count<5&&b[k]==0)
{
a[j]=b[k];
j++;
count=0;
}

else if(count==5)
{
count=0;
}

i=k;
}
}
else
{
a[j]=b[i];
j++;
}
}
printf("The data recieved\n");
for(i=0;i<j;i++)
{
printf("%d\n",a[i]);
}

}
int main()
{
int i,count,j,k,n,a[50],b[50],c[50];
printf("Enter the number of frames to be sent\n");
scanf("%d",&n);
printf("Enter the data for each frame:\n");
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
count=0;
for(i=0;i<n;i++)
{
if(a[i]==1)
{
for(k=i;k<n&&a[k]==1&&count<=5;k++)
{
b[j]=a[k];
count++;
if(count==5)
{
j++;
b[j]=0;
}
j++;
i=k;
}
count=0;
}
else
{
b[j]=a[i];
j++;
}
}
printf("After stuffing\n");
printf("Data:\n");
for(i=0;i<j;i++)
{
printf("%d\n",b[i]);
}
printf("\n");
s=j;
rec(b);
return 0;
}

