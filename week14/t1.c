#include "myhead.h"
int i=0;
void foo()
{
	int buffer[256];
	i++;
	printf("%d : call.\n");
	foo();
	

}
int main()
{
	foo();
	return 0;
}
