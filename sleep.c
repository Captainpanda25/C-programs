#include<stdio.h>
#include<signal.h>
#include<unistd.h>
static void sig_alarm(int sig)
{
printf("YELLAH HABIBI!!!!!!\n");
return;
}
unsigned int sleep1(int secs)
{
if(signal(SIGALRM,sig_alarm)==SIG_ERR)
return(secs);
alarm(secs);
pause();
return(alarm(0));
}
int main()
{
sleep1(4);
}
