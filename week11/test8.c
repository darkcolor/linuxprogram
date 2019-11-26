#include "myhead.h"
void init_daemon(void)    //生成守护进程
{
	pid_t child1,child2;
	int i;
	child1=fork();
	if(child1>0)
		exit(0);
	else if(child1<0)
	{
		perror("创建子进程失败!");
		exit(1);
	}
	setsid();
	chdir("/tmp");
	umask(0);
	for(i=0;i<NOFILE;i++)
	close(i);
	return;
}
