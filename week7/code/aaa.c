#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int globa = 4;

int main (void )
{
	pid_t pid;
	int vari = 5;

	printf ("before fork\n" );
	//printf ("before fork" );
	if ((pid = fork()) < 0){
	  printf ("fork error\n");
	  _exit (0);
	}else if (pid == 0){
	  globa++ ;
	  vari--;
	  printf("Child changed\n");
	  //printf("Child changed");
	}else
	  printf("Parent did not changde\n");
	  //printf("Parent did not changde");
	  printf("globa = %d vari = %d\n",globa,vari);
	  _exit(0);
}
