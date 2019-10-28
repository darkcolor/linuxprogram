#include "ahead.h"

void newfile()
{
	FILE *new_file;
	char s[number];
	printf("请输入你要创建文件的名字：\n");
	scanf("%s",s);
	//使用“读入”方式打开文件
    new_file = fopen(s, "r");

    //如果文件不存在
    if (new_file == NULL)
    {
        //使用“写入”方式创建文件
        new_file = fopen(s, "w+");
    }
    //关闭文件
    fclose(new_file);
	printf("创建成功！\n");
	menu();
	
}
