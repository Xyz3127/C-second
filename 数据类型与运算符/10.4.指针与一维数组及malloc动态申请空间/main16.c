#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change1(char i[]) {
	*i = 'H';
}
void change2(char *j) {
	*(j+1) = 'E';
}

int main()
{
	char c[10] = "hello";
	change1(c);
	puts(c);
	change2(c);
	puts(c);

	//�ѿռ䣬�ռ䶯̬����
	int k;
	scanf("%d", &k);
	char* c2;
	c2 = (char*)malloc(k);//malloc����ռ�ĵ�λ���ֽ�
	strcpy(c2, "hello world");
	char* c3 = c2;
	c2++;
	puts(c2);
	free(c3);
	c2 = NULL;			//�ͷ�Ұָ��
}