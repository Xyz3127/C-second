#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[5] = { 5,4,3,2,1 };
	int* p;
	p = a;
	int j = *p++; //后加加任何时候都是把后加加去掉
					//第二步看另外一个运算符 优先级是否高于加加
	printf("a[0]=%d,\nj=%d,\n*p=%d,\na=%p,\np=%p\n", a[0],j,*p, a, p);
	p--;
	j = (*p)++;		//这里的(*p)和a[0]和p[0]是等价的 
	printf("a[0]=%d,\nj=%d,\n*p=%d,\na=%p,\np=%p\n", a[0], j, *p, a, p);
}