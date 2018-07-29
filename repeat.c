#include<stdio.h>
#include<string.h>
void dup(char *a)
{
int i,j,k,n;
n=strlen(a);
for(i=0;i<n;i++)
{
for(j=k=i+1;k<=n;)
{
if(a[i]!=a[k])
{
a[j]=a[k];
j++;
k++;
}
else
{
k++;
}
}
}
}
int main()
{
int i;
char *a;
printf("||REPETITION OF CHARACTERS||\nPlease enter a string: \t");
scanf("%s",a);
dup(a);
printf("%s\n",a);
}


