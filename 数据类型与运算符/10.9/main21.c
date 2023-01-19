#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(int** a, int* b) {
	*a = b;
}

int main()
{
	int i = 5, j = 10;
	int* pi = &i, * pj = &j;
	printf("%d %d %d\n", i, *pi, *pj);
	change(&pi, pj);
	printf("%d %d %d", i, *pi, *pj);
}