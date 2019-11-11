/*要查看一个进程的虚拟地址空间的内存布局，需要设置阻塞，当直接运行时，程序执行的速度非常快以至于来不及查看，所以需要设置阻塞*/
#include <stdio.h>
#include <malloc.h>
int a;
static int b=10;
int main(int argc,char* argv[],char* envp[])
{
	int a=10;//stack
	char* p=(char*)malloc(sizeof(char));//heap
	printf("a=%d,p=0x%x\n",a,p);//动态链接库，*.so
	getchar();//设置阻塞，也可以使用sleep（）函数来解决
	getchar();
	return 0;
}
