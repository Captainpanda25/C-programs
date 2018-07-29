#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#define MAXMESG 512
dg_echo(sockfd,pcli_addr,maxclilen)
int sockfd;
struct sockaddr *pcli_addr;
int maxclilen;
{
int n,clilen;
char mesg[MAXMESG];
for(;;)
{
printf("Hi IN SERVER\n");
clilen=maxclilen;
bzero(mesg,512);
n=recvfrom(sockfd,mesg,MAXMESG,0,pcli_addr,&clilen);
if(n<0)
printf("recvfrom error\n");
else
printf("recieved %s",mesg);
}
}
char *pname;
int main(int argc,char *argv[])
{
printf("shree\n");
int sockfd;
struct sockaddr_in serv_addr,cli_addr;
pname=argv[0];
fflush(stdout);
if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
printf("Can't open datagram socket\n");
else
printf("socket created\n");
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.0.102");
serv_addr.sin_port=htons(7084);
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
printf("can't bind local address\n");
else
printf("Binded\n");
dg_echo(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
}

