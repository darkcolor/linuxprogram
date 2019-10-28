#include "ahead.h"

//菜单函数，显示菜单并提供功能选择
void menu()
{
	while(1)
	{
		char ch;
		int selectNumber=0;
		printf("********版本：1.0*************\n");
		printf("0.退出                      \n");
		printf("1.创建新文件                 \n");
		printf("2.写文件                    \n");
		printf("3.读文件                    \n");
		printf("4.修改文件权限               \n");
		printf("5.查看当前文件权限            \n");
		printf("6.帮助                      \n");
		printf("*****************************\n");
		printf("请输入您的选择：");
		scanf("%d",&selectNumber);
		ch = selectNumber;
		switch(ch)
		{
			case 0:printf("感谢您的使用！\n");
				   exit(0);
			case 1:newfile();
				   break;
			case 2:writefile_1();
				   break;
			case 3:readfile();
				   break;
			case 4:modifyfile();
				   break;
			case 5:viewfile();
				   break;
			case 6:message();
				   break;
			default:printf("输入错误，请重新输入。\n");
					break;
		}
	
	}
}
