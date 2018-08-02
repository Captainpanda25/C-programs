#include<stdio.h>
int main()
{
int i,j,k,n,count=0;
int a[50],b[50];
printf("Enter the frame size:\n");
scanf("%d",&n);
printf("Enter the data\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
j=0;
for(i=0;i<n;i++)
{



if(a[i]==1)
{
for(k=i;k<n&&a[k]==1&&count<5;k++)
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
printf("Byte stuffed\n");
for(i=0;i<j;i++)
printf("%d\n",b[i]);
return 0;
}


