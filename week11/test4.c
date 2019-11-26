#include "myhead.h"
void pr_exit(int s, int pid)
{
	int sig;
	if (WIFEXITED(s))
	{
		printf("process %d nomal termination, exit s = %d \n",pid,WEXITSTATUS(s));
	}
	else if (WIFSIGNALED(s))
	{
		sig = WTERMSIG(s);
		printf("process %d abnomal termination, exit signal number = %d %s \n",pid,sig.
		#ifdef WCOREDUMP
			WCOREDUMP(s)?"(core file grenerated)":"");
		#else
			"");
		#endif
		psignal(sig,"");
	}
	else if (WIFSIGNALED(s))
	{
		sig = WSTOPSIG(s);
		printf("process %d stopped,signal number = %d: \n",pid,sig);
		psignal(sig,"");
	}
}

int zero = 0;

int main()
{
	int pid,s;
	//int pid1,pid2,pid3,s1,s2,s3;
	if((pid = fork()) == 0)
	{
		exit(0);
	}
	if((pid = fork()) == 0)
	{
		abort();
	}
	if((pid = fork()) == 0)
	{
		s = s/zero;
		exit(0);
	}
	/*
	pid1 = wait(&s1);
	pid2 = wait(&s2);
	pid3 = wait(&s3);
	pr_exit(s1,pid1);
	pr_exit(s2,pid2);
	pr_exit(s3,pid3);
	*/
	while((pid = wait(&s)) >= 0)
	{
		pr_exit(s,pid);
	}
	perror("parent wait over!\n");
	exit(0);
}

