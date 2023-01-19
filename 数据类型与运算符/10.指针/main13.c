#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 5;
	int* p = &i;		//指针变量的初始化一定是某个变量取地址
	printf("%d\n", i);	//直接访问
	printf("%d\n", *p);	//间接访问

	float k = 1.23;
	int* q = &k;		//不能混用，整型和字符型在内存中的存储方式不同
	printf("%f\n", *q);

	int* a, * b, * c;	//定义指针每个都要加*
}