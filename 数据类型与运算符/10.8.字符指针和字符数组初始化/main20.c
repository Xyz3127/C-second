#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* p = "hello";			//�׵�ַ��ֵ�op
	char c[10] = "hello";		//�ȼ���strcpy(c, "hello")
	c[0] = 'H';
	printf("p[0]=%c\n", p[0]);
	printf("c[0]=%c\n", c[0]);
	//p[0] = 'H';				//�����ԶԳ��������ݽ����޸�
	p = "world";				//���ַ����ĵ�ַ����p
	puts(p);
	//c="world";				//�Ƿ�
	return 0;
}