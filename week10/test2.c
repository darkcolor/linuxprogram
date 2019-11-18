#include "myhead.h"
int g=88;
int main ()   
{   
    pid_t pid; //fpid表示fork函数返回的值  
    int v=99;  
    pid=vfork();   //vfork是 创建一个子进程，并和父进程的内存数据share一起用
    if (pid < 0)   
	{
        printf("error in vfork!");   
		exit(-1);
	}
    else if (pid == 0) {  
		g++;
		v++;
        printf("child:pid=%d,g=%d,v=%d\n",getpid(),g,v);   
		//  exit(0); //子进程必须调用exec或exit后父进程才可能被调度
    	//return 0;
    }  
    else {  
        printf("return value=%d\n",pid);   
        printf("parent:pid=%d,g=%d,v=%d\n",getpid(),g,v); 
		return 0; 
    }  
}
