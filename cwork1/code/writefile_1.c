#include "ahead.h"
void writefile_1()
{
	FILE *fp;
	char s[number];
	char s1[number];
	printf("请输入要打开的文件名：\n");
	scanf("%s",s);
    fp = fopen(s, "w+");
	printf("请输入要写入的内容\n");
	scanf("%s",s1);
	fprintf(fp,"%s\n",s1);
    //关闭文件
    fclose(fp);
	menu();
}
