#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float i, f;//占用四个字节
	i = 1.234;
	f = 3e-3;
	printf("%f\n%f\n", i, f);

	char c, d;//占用一个字节
	c = 'a';
	printf("%c\n", c);
	printf("%c\n", 97);
	printf("%d\n", c);
}