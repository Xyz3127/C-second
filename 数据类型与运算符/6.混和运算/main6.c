#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 5;
	float j = i / 2;
	float k = (float)i / 2;//强制转化字符类型
	printf("%f\n%f", j, k);
}