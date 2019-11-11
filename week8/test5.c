#include "myhead.h"
int main()
{
	int ret;
	printf("caller:pid=%d,ppid=%d\n",getpid(),getppid());
	ret=system("/home/rlk/linuxprogram/test/test5_1 123 456 hello");
	printf("after calling!\n");
	sleep(10);
	return 0;
}

