#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;//占用四个字节
	//i = 123; //10进制
	//i = 0173; //8进制
	i = 0x7b; //16进制
	printf("%d\n", i);
}