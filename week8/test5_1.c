#include "myhead.h"
int x=100;
int main(int argc,char* argv[])
{
	int y=0;
	static int w=33;
	printf("caller:pid=%d,ppid=%d\n",getpid(),getppid());
	for(int i=0;i<argc;i++)
		printf("%d : %s\n",i,argv[i]);
	printf("test1:address x=%ld,y=%ld,w=%ld\n");
	sleep(10);
	return 0;
}
