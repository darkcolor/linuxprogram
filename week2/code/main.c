#include "hw1.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;
	if((fd = creat("file.hole",0664))<0)
		perror("creat failed!\n");
	if(write(fd,buf1,10) != 10)
		perror("write failed!\n");
	if(lseek(fd,40,SEEK_SET) == -1)
		perror("seek filed!\n");
	if(write(fd,buf2,10) != 10)
		perror("write error!\n");
	return 0;
}
