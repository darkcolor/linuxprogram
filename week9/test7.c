#include "myhead.h"
static void __attribute__((constructor)) before_main(void)
{
	printf("Before test Mian!\n");
}
static void callback1()
{
	printf("Callback1 is running\n");
}
static void callback2()
{
	printf("Callback2 is running\n");
}
static void callback3()
{
	printf("Callback3 is running\n");
}
int main(int argc,char* argv[])
{
	int i;
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test7:pid=%d,ppid=%d\n",getpid(),getppid());
	for(int i=0;i<argc;i++)
		printf("test7: %d : %s\n",i,argv[i]);
	printf("test Main function finished\n");
	//sleep(5);
	return 0;
}
