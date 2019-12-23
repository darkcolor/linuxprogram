#include "myhead.h"
int main()
{
	pid_t p1,p2,p3;
	p1=fork();
	p2=fork();
	p3=fork();
	if(p1<0||p2<0||p3<0)
		{
			perror("fork failed.\n");
			return -1;

		}

	else if (p1==0)
	{
		
		printf("ppid=%d pid =%d\n",getppid(),getpid());
		exit(0);
		
	}
	else if (p2==0)
	{
		
		printf("ppid=%d pid =%d\n",getppid(),getpid());
		exit(0);
		
	}
	else if (p3==0)
	{
		
		printf("ppid=%d pid =%d\n",getppid(),getpid());
		exit(0);
		
	}
	else
	{
		wait(NULL);
		wait(NULL);
		wait(NULL);
		printf("parent end\n");
		return 0;		
	}

}
