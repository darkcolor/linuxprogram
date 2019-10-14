#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	printf("\nbefore calling!\n");
	sleep(5);
	i=system("./proj1");
	printf("\nafter calling!\n");
	printf("return value=%d\n",i);
	return 0;
}
