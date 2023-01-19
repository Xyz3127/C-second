#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c[20];//字符数组的数组名里存的就是字符数组的起始地址，类型是字符指针
	gets(c);	//只能用于字符串
	//fgets(c, sizeof(c), stdin);//fgets结尾多一个'\n'
	puts(c);

	//strlen 统计字符串长度
	//strcpy 将某个字符串复制到字符数组中
	//strcmp 比较两个字符串的大小
	//strcat 连接两个字符串

	printf("%d\n", strlen(c));

	char d[20];
	strcpy(d, c);
	printf("%s\n", d);

	int com = strcmp("how", "hello");//顺序比较ascii码
	printf("%d\n", com);

	strcat(c, "zxc");
	printf("%s\n", c);
}