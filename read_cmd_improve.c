#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
static void sig_int(int);

int main(void)
{
  char buf[512];
  pid_t pid;
  int status;
  
  if(signal(SIGINT,sig_int ) == SIG_ERR)
    printf("signal error ");
  
  printf("%%");
  
  while(fgets(buf,512,stdin)!= NULL){
   if(buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) -1 ] = 0;
   
   if((pid = fork()) <0)
   {  
     printf("fork error");
    }
    else if(pid == 0)
    {
     execlp(buf,buf,(char *)0);
     printf("could not execute %s ",buf);
     exit(127);
}
    if((pid = waitpid(pid,&status,0)) < 0)
       printf("wait pid err");
    printf("%%");
   }
   exit(0);
}

void sig_int(int signo)
{
  printf("interupt \n %%");
}

