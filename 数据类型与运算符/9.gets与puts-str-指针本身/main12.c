#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char c[20];//�ַ���������������ľ����ַ��������ʼ��ַ���������ַ�ָ��
	gets(c);	//ֻ�������ַ���
	//fgets(c, sizeof(c), stdin);//fgets��β��һ��'\n'
	puts(c);

	//strlen ͳ���ַ�������
	//strcpy ��ĳ���ַ������Ƶ��ַ�������
	//strcmp �Ƚ������ַ����Ĵ�С
	//strcat ���������ַ���

	printf("%d\n", strlen(c));

	char d[20];
	strcpy(d, c);
	printf("%s\n", d);

	int com = strcmp("how", "hello");//˳��Ƚ�ascii��
	printf("%d\n", com);

	strcat(c, "zxc");
	printf("%s\n", c);
}