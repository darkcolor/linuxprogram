#include "myhead.h"
int main()
{
	int ret;
	printf("caller:pid=%d,ppid=%d\n",getpid(),getppid());
	//execl("/home/rlk/linuxprogram/test/test5_1","./test5_1","123","456",NULL);
	char *const envp[] = {"test5_1","1","2","3",NULL};
	execv("./test5_1",envp);
	printf("after calling!\n");
	sleep(5);
	return 0;
	
}
