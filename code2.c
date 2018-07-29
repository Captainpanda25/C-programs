#include<stdio.h>
#include<string.h>
void main()
{
char s[100],a[100][100];
int i=0,j=0,k=0;
printf("\n Dev>>");
printf("Please enter a command line:\n");
gets(s);
while(s[i]!='\0')
{
if((s[i]!=' ')&&(s[i]!='"')&&(s[i]!='\t'))
{
a[j][k]=s[i];
k++;
i++;
}
else if((s[i]==' ')||(s[i]=='\t'))
{
j++;
k=0;
i++;
}
else if(s[i]=='"')
{
i++;
while(s[i]!='"')
{
a[j][k]=s[i];
i++;
k++;
}
i++;
}
}
j++;
a[j][0]='\0';
for(i=0;a[i][0]!='\0';i++)
{
printf("%s",a[i]);
printf("\n");
}
}
