#include "ahead.h"
void viewfile()
{
	char s[number];
	printf("请输入你查看权限的文件名：\n");
	scanf("%s",s);
	
	struct stat fileInfo;

	if (stat(s, &fileInfo) < 0)
	{	
		printf("文件不存在");
		menu();
	}
	printf("%d\n",fileInfo.st_mode & 1023);
	menu();
}
