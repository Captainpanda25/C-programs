#include<stdio.h>
#include<string.h>
struct a
{
int age;
char name[50];
}o1,o2;
int main()
{
printf("Person1 name: \n");
scanf("%s",o1.name);
printf("Person1 age: \n");
scanf("%d",&o1.age);
printf("Person2 name: \n");
scanf("%s",o2.name);
printf("Person2 age: \n");
scanf("%d",&o2.age);
if((strcmp(o1.name,o2.name)==0)&&(o1.age==o2.age))
printf("Both the person's details are identical!\n");
else
printf("Both the person's details do not match! \n");
}

