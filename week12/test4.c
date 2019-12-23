#include "myhead.h"
int main()
{
	pid_t p1, p2, p3;
	int fd1[2], fd2[2];
	
	pipe(fd1);
	pipe(fd2);
	
	p1 = fork();	
	if(p1 < 0)
	{
		perror("fork1 failed.\n");
		return -1;
	}
	else if(p1 == 0)
	{
		close(fd1[0]);
		char b1[10];
		printf("child1: pid=%d ppid=%d\n", getpid(), getppid());
		write(fd1[1], &b, sizeof(b1));
		printf("child1: write 1\n");
		close(fd1[1]);
		exit(0);
	}
	else
	{
		p2 = fork();
		if(p2 < 0)
		{
			perror("fork2 failed.\n");
			return -1;
		}
		else if(p2 == 0)
		{
			close(fd2[0]);
			char b = '2';
			printf("child2: pid=%d ppid=%d\n", getpid(), getppid());
			write(fd2[1], &b, sizeof(b));
			printf("child2: write 2\n");
			close(fd2[1]);
			exit(0);
		}
		else
		{
			p3 = fork();
			if(p3 < 0)
			{
				perror("fork3 failed.\n");
				return -1;
			}
			else if(p3 == 0)
			{
				close(fd1[1]);
				char buf[2];
				memset(buf, 0, 2);
				printf("child3: pid=%d ppid=%d\n", getpid(), getppid());
				read(fd1[0], buf, 1);
				printf("child3: read %s\n", buf);
				close(fd1[0]);
				exit(0);
			}
			else
			{
				wait(NULL);
			}
			wait(NULL);
		}
		wait(NULL);
		printf("parent: end\n");
		close(fd2[1]);
		char buf[2];
		memset(buf, 0, 2);
		read(fd2[0], buf, 1);
		printf("parent: read %s\n", buf);
		close(fd2[0]);
		exit(0);
	}
}

