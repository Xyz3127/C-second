#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[5] = { 5,4,3,2,1 };
	int* p;
	p = a;
	int j = *p++; //��Ӽ��κ�ʱ���ǰѺ�Ӽ�ȥ��
					//�ڶ���������һ������� ���ȼ��Ƿ���ڼӼ�
	printf("a[0]=%d,\nj=%d,\n*p=%d,\na=%p,\np=%p\n", a[0],j,*p, a, p);
	p--;
	j = (*p)++;		//�����(*p)��a[0]��p[0]�ǵȼ۵� 
	printf("a[0]=%d,\nj=%d,\n*p=%d,\na=%p,\np=%p\n", a[0], j, *p, a, p);
}