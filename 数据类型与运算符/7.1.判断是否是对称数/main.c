#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//判断数是否对称
	int i;
	while (scanf("%d", &i) != EOF && i != 1 && i != 0) {
		int t = i, j=0, k;
		while(i) {
			k = i % 10;
			i = i / 10;
			j = j * 10 + k;
		}
		if (j == t) {
			printf("the num %d is symmetry\n", t);
		}
		else {
			printf("the symmetric number of %d is %d\n", t, j);
		}
		j = 0;
	}
	//判断字符串是否对称
	char c[100], d[100];

	rewind(stdin);//清理标准输入区

	gets(c);
	int j;
	for (i = strlen(c)-1, j = 0; i >= 0; i--, j++) {
		d[j] = c[i];
	}
	d[j] = 0;
	printf("%d", strcmp(d, c));
}