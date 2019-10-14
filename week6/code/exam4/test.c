#include "/home/rlk/linuxprogram/week6/code/exam3/lib.h"
int main()
{
	int a[NUMBER];
	urand(a,NUMBER);
	printf("maxvlaue=%d\n",max(a,5));
	printf("sumvlaue=%d\n",sum(a,5));
	return 0;
}
