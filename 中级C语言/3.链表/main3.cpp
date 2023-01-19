#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void modify(char*& p) {
	p = (char*)malloc(100);//申请空间
	fgets(p, 100, stdin);//如果传入的是指针变量，中间参数是指针指向的空间大小
}

int main() {
	char* p;
	modify(p);
	puts(p);
}