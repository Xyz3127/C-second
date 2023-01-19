#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* print_stack() {
	char a[] = "i am stack";
	puts(a);
	return a;
}

char* print_malloc() {
	char* a = (char*)malloc(20);
	strcpy(a, "i am malloc");
	puts(a);
	return a;
}

int main()
{
	char* p, * q;
	p = print_stack();
	puts(p);	//栈空间会随着子函数的结束而释放
	q = print_malloc();
	puts(q);	//堆空间不会随子函数的结束而释放，必须自己free
}