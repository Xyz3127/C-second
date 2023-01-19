#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char c;
	float f;
	scanf("%d %c%f", &i, &c, &f);//混合输入时需要加一个空格
	printf("i=%-3d,c=%-3c,f=%.3f\n", i, c, f);
	//system("pause");
}