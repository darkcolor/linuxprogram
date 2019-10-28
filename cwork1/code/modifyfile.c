#include "ahead.h"
void modifyfile()
{
	char s[number];
	int select;
	printf("请输入你要改变权限的文件名：\n");
	scanf("%s",s);
	printf("请输入你要改变的权限(数字)：\n");
	scanf("%d",&select);
	struct stat fileInfo;
    if (stat(s, &fileInfo) < 0)
		printf("文件不存在！");
	if (chmod(s, select) < 0)
        	printf("改变权限失败！                      \n");
	menu();
/*
参数 mode 有下列数种组合：
S_ISUID 04000 文件的 (set user-id on execution)位
S_ISGID 02000 文件的 (set group-id on execution)位
S_ISVTX 01000 文件的sticky 位
S_IRUSR (S_IREAD) 00400 文件所有者具可读取权限
S_IWUSR (S_IWRITE)00200 文件所有者具可写入权限
S_IXUSR (S_IEXEC) 00100 文件所有者具可执行权限
S_IRGRP 00040 用户组具可读取权限
S_IWGRP 00020 用户组具可写入权限
S_IXGRP 00010 用户组具可执行权限
S_IROTH 00004 其他用户具可读取权限
S_IWOTH 00002 其他用户具可写入权限
S_IXOTH 00001 其他用户具可执行权限
错误代码：
1、EPERM 进程的有效用户识别码与欲修改权限的文件拥有者不同, 而且也不具root 权限.
2、EACCESS 参数path 所指定的文件无法存取.
3、EROFS 欲写入权限的文件存在于只读文件系统内.
4、EFAULT 参数path 指针超出可存取内存空间.
5、EINVAL 参数mode 不正确
6、ENAMETOOLONG 参数path 太长
7、ENOENT 指定的文件不存在
8、ENOTDIR 参数path 路径并非一目录
9、ENOMEM 核心内存不足
10、ELOOP 参数path 有过多符号连接问题.
11、EIO I/O 存取错误
*/
}

