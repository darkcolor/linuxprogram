#include "ahead.h"
void readfile()
{
	char *pchBuf = NULL;
	int  nLen = 0;
	char s[number];
	printf("请输入打开的文件的名字：\n");
	scanf("%s",s);
	FILE *pF  = fopen(s, "r"); //打开文件
	fseek(pF, 0, SEEK_END); //文件指针移到文件尾
	nLen = ftell(pF);  //得到当前指针位置, 即是文件的长度
	rewind(pF);    //文件指针恢复到文件头位置
	//动态申请空间, 为保存字符串结尾标志\0, 多申请一个字符的空间
	pchBuf = (char*) malloc(sizeof(char)*nLen+1);
	if(!pchBuf)
	{
		perror("内存不够!\n");
		exit(0);
	}
	//读取文件内容//读取的长度和源文件长度有可能有出入，这里自动调整 nLen
	nLen = fread(pchBuf, sizeof(char), nLen, pF);
	pchBuf[nLen] = '\0'; //添加字符串结尾标志
	printf("%s\n", pchBuf); //把读取的内容输出到屏幕看看
	fclose(pF);  //关闭文件
	free(pchBuf); //释放空间
	menu();
}
