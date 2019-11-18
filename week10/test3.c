#include "myhead.h"
int g=10;
int main()
{
	int s=20;
	static int k=30;
	pid_t pid; //fpid表示fork函数返回的值  
    pid=vfork();   //vfork是 创建一个子进程，并和父进程的内存数据share一起用
    if (pid < 0)   
	{
        printf("error in vfork!");   
		exit(-1);
	}
    else if (pid == 0) {  
        printf("child:pid=%d :&g=%16p,&k=%16p,&s=%16p\n",getpid(),&g,&k,&s);   
		g=100;
		k=300;
		s=200;
		printf("child:pid=%d :&g=%d,&k=%d,&s=%d\n",getpid(),g,k,s);   
		//sleep(2);
		while(g!=400)
			printf("正在等待父进程赋值g=400!\n");
		_exit(0); //子进程必须调用exec或exit后父进程才可能被调度
    	//return 0;
    }  
	else {  
		g=400;
        printf("parent:pid=%d :&g=%16p,&k=%16p,&s=%16p\n",getpid(),&g,&k,&s);
        printf("parent:pid=%d :&g=%d,&k=%d,&s=%d\n",getpid(),g,k,s); 
		return 0; 
    }  
    return 0;
}
