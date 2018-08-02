#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
int i,fd=-1;
ssize_t br, bw;
char buf[50];
if(argc==1)
{
perror("Error, no file!");
return 0;
}

for(i=1;i<argc;i++)
{

if((fd=open(argv[i],O_RDWR))==-1)
{
perror("File cannot be opened");
return 0;
}

if((br=read(fd,buf,50))==-1)
{
perror("File cannot be read");
return 0;
}

else if((bw=write(1,buf,br))==-1)
{
perror("Error in writing");
printf("\n");
return 0;
}

}
return 0;
}


