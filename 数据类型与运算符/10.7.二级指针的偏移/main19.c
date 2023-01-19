#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	scanf("%d", &i);
	char* p;
	p = (char*)malloc(i);

	rewind(stdin);
	//char c;
	//scanf("%c", c);

	gets(p);
	puts(p);

	return 0;
}