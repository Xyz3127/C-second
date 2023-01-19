#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//printf("%d", 'd');
	int a, b;
	//scanf("%d%d", &a, &b);
	//printf("a+b=%d\n", a+b);
	scanf("%d%d", &a, &b);
	printf("a=%d\n", a + b);

	char c;
	scanf("%c", &c);//字符串会读取"\n"
					//匹配标准输入缓存区内容
	printf("c=%c\n", c);

	scanf("%d", &b);//整数、浮点数、字符串会忽略“\n”
	printf("b=%d\n", b);
}