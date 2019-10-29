#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*int main()
{
	printf("PPID=%d,PID=%d",getppid(),getpid());
	while(1);
	return 0;
}*/
int main(int argc,char *argv[],char *env[])

{

	int i = 0;

	for(;env[i];i++)

	{

		printf("%s\n",env[i]);

	}
	extern char **environ;

	i = 0;

	for(; environ[i];i++)

	{

		printf("%s\n",environ[i]);

	}
	printf("%s\n",getenv("PATH"));
	return 0;

}





