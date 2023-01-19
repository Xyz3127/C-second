#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* p = "hello";			//首地址赋值給p
	char c[10] = "hello";		//等价于strcpy(c, "hello")
	c[0] = 'H';
	printf("p[0]=%c\n", p[0]);
	printf("c[0]=%c\n", c[0]);
	//p[0] = 'H';				//不可以对常量区数据进行修改
	p = "world";				//将字符串的地址赋给p
	puts(p);
	//c="world";				//非法
	return 0;
}