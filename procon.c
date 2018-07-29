#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#define N 5
#define PERMS 0666

int *buffer;
int nextp=0,nextc=0;
int mutex,full,empty;    //semaphore variables

void producer()
{
 if(nextp == N)
 nextp=0;
 printf("\nEnter the data(producer) :");
 scanf("%d",(buffer+nextp));
 nextp++;
 }

void consumer()
{
 int g;
if(nextc == N)
 nextc=0;
 g=*(buffer+nextc++);
 printf("\nconsumer consumes the data:%d\n",g);
}

void sem_op(int id, int value)
{
 struct sembuf op;
 int v;
 op.sem_num=0;
 op.sem_op=value;
 op.sem_flg=SEM_UNDO;
 if((v=semop(id,&op,1)) < 0)
  printf("\n Error executing semop instruction");
}

void sem_create(int semid, int initval)
{
 int semval;
union semun
{
 int val;
 struct semid_ds *buf;
 unsigned short *array;
}s;

s.val=initval;
if((semval=semctl(semid,0,SETVAL,s))<0)
  printf("\n Erroe in executing semctl");
}

void sem_wait(int id)
{
 sem_op(id,-1);
}

void sem_signal(int id)
{
 sem_op(id,1);
}

int main()
{
 int shmid,i,pid;
 if((shmid=shmget(1000,1,PERMS|IPC_CREAT)) < 0)
 {
  printf("\n unable to create shared memory");
  }
 if((buffer=(int*)shmat(shmid,(char*)0,0)) == (int*)-1)
 {
  printf("\n Shared memory allocation error\n");
  exit(1);
  }

 if((mutex=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
   printf("\n can't create mutex semaphore");
   exit(1);
  }

 if((empty=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
  printf("\n can't create empty semaphore");
  exit(1);
  }

 if((full=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
 printf("\ncan't create full semaphore");
 exit(1);
  }

 sem_create(mutex,1);
 sem_create(empty,N);
 sem_create(full,0);
if((pid=fork()) < 0)
 {
  printf("\n Error in process creation");
  exit(1);
  }

else if(pid > 0)
 {
   printf("\n\n parent process id:%d",pid);
for(i=0;i<5;i++)
{
  sem_wait(empty);
  sem_wait(mutex);
  producer();
  sem_signal(mutex);
  sem_signal(full);
  }
wait();
}
else
{
 printf("\n\n Child process if %d",pid);
 for(i=0;i<5;i++)
{
 sem_wait(full);
 sem_wait(mutex);
 consumer();
 sem_signal(mutex);
 sem_signal(empty);
  }
 }
return 0;
}
