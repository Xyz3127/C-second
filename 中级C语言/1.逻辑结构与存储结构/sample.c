#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

}

void print() {
	int n;
	char c;
	do {
		scanf("%d", &n);
		printf("%2d", n);
	} while (c = getchar() != '\n');
	printf("\nend");
}