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
	scanf("%c", &c);//�ַ������ȡ"\n"
					//ƥ���׼���뻺��������
	printf("c=%c\n", c);

	scanf("%d", &b);//���������������ַ�������ԡ�\n��
	printf("b=%d\n", b);
}