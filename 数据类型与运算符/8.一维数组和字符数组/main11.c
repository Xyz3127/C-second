#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define N 5

void print1(int a[], int len) {
	for (int i = 0; i < len; i++) {
		printf("a[%d]=%d\n", i, a[i]);
	}
}

void print2(char a[]) {//����ַ�������������Σ�
						//����Ҫ���볤�ȣ���Ϊ�������ַ�����β��'\0'����
	int i = 0;
	a[i] = a[i] - 32;
	while (a[i]) {
		printf("%c", a[i]);
		i++;
	}
	printf("\n");
}

int main()
{
	int j = 7;
	int a[N] = { 1,2,3,4,5 };//�������ñ������������÷��ų�����defind��
	int i = 3;
	//a[5] = 60;
	//a[6] = 70;
	//[7] = 80;
	print1(a, 4);//����˸��ֽڣ�����Խ��

	char c1[6] = { 'h','e','l','l','o' };
	char c2[8] = "hello";
	char c3[5] = "hello";//�ַ����鶨��ʱҪ��һ���ַ����������֡��̡���cc cc��
	printf("%s---%s---%s\n", c1, c2, c3);

	char e[20], f[20];
	scanf("%s%s", &e, &f);//����Ҫ�ӿո�,����ַ�����ʡ�пո���gets
	printf("%s-------%s\n", e, f);
	print2(c1);
}