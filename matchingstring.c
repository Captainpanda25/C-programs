#include<stdio.h>
int main()
{
int i;
char str1[20], str2[20];
printf("Please enter any 2 words of your choice:\n");
scanf("%s%s",str1,str2);
printf("\n");
for(i=0;str1[i]==str2[i]&&str1[i]!='\0';i++)
{
if(str1[i]>str2[i])
printf("Not happening. %c does not match %c!",str1[i],str2[i]);
else if(str1[i]<str2[i])
printf("NO! Try harder. %c doesn't match %c!",str1[i],str2[i]);
else 
printf("Woah! %c matches with %c!",str1[i],str2[i]);
}
return 0;
}

