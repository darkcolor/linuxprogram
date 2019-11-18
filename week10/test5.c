#include "myhead.h"
int g=10;
char a[100]={0};
int main(int argc,char *argv[])
{
	pid_t pid;
	int i;
	static int k=20;
	printf("test:pid=%d,&k=%16p,&g=%16p\n,&a=%16p\n",getpid(),&k,&g,a);  
	for(i=0;i<10;i++)
	{
		printf("test:g=%d,k=%d\n",g++,k++);
	}
	//_exit(0);
	return 0;
}
