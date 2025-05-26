#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<string.h>
int main(int argc,char *argv[])
{
    fprintf(stderr,"EACCES : %s \n",strerror(EACCES));
   errno = ENOENT;
   perror(argv[0]);
   exit(0);
}
