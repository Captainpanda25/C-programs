#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#define MAXLINE 512
dg_cli(fp,sockfd,pserv_addr,servlen)
FILE *fp;
int sockfd;
struct sockaddr* pserv_addr;
int servlen;
{
printf("dg_client");
int n;
char sendline[MAXLINE],recvline[MAXLINE+1];
while(fgets(sendline,MAXLINE,fp)!=NULL)
{
printf("in while\n");
n=strlen(sendline);
printf("%d\n",n);
if(sendto(sockfd,sendline,n,0,pserv_addr,servlen)!=n)
printf("error in sending\n");
else 
printf("sent\n");
}
if(ferror(fp))
printf("error reading file\n");
}
char *pname;
int main(int argc,char *argv[])
{
printf("sana");
int sockfd, x;
struct sockaddr_in cli_addr,serv_addr;
pname=argv[0];
printf("hi\n");
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.0.102");
serv_addr.sin_port=htons(7084);
if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
printf("Can't open datagram socket\n");
else
printf("socket created\n");
cli_addr.sin_family=AF_INET;
cli_addr.sin_addr.s_addr=inet_addr("192.168.0.102");
cli_addr.sin_port=htons(7085); 
x=bind(sockfd,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
if(x<0)
printf("Can't bind local address\n");
else
dg_cli(stdin,sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
exit(0);
}

