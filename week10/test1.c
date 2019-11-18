#include "myhead.h"
static void fun1(void)
{
	printf("invoked callbackfun!\n");
}
int main()
{
	atexit(fun1);
	FILE *fp;
	char buf[]="buffer data!";
	if((fp=fopen("test.dat","w+"))==NULL)
	{
		perror("create file error!\n");
		exit(-1);
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("fputs fp failed!\n");
		exit(-1);
	}
	printf("hello  \n");
	return 0;
}
