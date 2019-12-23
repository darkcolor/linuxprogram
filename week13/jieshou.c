//实现一个信号接收程序sigreceive（其中信号安装由sigaction（））。
#include "myhead.h"
void new_op(int signum,siginfo_t *info,void *myact)
{
    printf("receive signal %d", signum);
    sleep(5);
}
int main(int argc,char *argv[])
{
    struct sigaction act;   
    int sig;
    sig=atoi(argv[1]);
     
    sigemptyset(&act.sa_mask);
    act.sa_flags=SA_SIGINFO;
    act.sa_sigaction=new_op;
     
    if(sigaction(sig,&act,NULL) < 0)
    {
        printf("install sigal error\n");
    }
     
    while(1)
    {
        sleep(2);
        printf("wait for the signal\n");
    }
	return 0;
}

