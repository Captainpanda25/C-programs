#include<stdio.h>
int main()
{
char str[100];
char *ptr;
printf("Enter a string: ");
gets(str); 

for(ptr=str;*ptr!='\0';*ptr++)
{
if((*ptr=='}')&&(*ptr-1!='{'))
printf("uneven braces present");
else if(*ptr==']'&&*ptr-1!='[')
printf("uneven braces present");
else if(*ptr==')'&&*ptr-1!='(')
printf("uneven braces present");
}
printf("%c",*ptr);
}

