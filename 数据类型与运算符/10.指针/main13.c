#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 5;
	int* p = &i;		//ָ������ĳ�ʼ��һ����ĳ������ȡ��ַ
	printf("%d\n", i);	//ֱ�ӷ���
	printf("%d\n", *p);	//��ӷ���

	float k = 1.23;
	int* q = &k;		//���ܻ��ã����ͺ��ַ������ڴ��еĴ洢��ʽ��ͬ
	printf("%f\n", *q);

	int* a, * b, * c;	//����ָ��ÿ����Ҫ��*
}