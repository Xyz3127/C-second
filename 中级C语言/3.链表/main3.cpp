#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void modify(char*& p) {
	p = (char*)malloc(100);//����ռ�
	fgets(p, 100, stdin);//����������ָ��������м������ָ��ָ��Ŀռ��С
}

int main() {
	char* p;
	modify(p);
	puts(p);
}