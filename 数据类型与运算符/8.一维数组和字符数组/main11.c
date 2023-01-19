#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define N 5

void print1(int a[], int len) {
	for (int i = 0; i < len; i++) {
		printf("a[%d]=%d\n", i, a[i]);
	}
}

void print2(char a[]) {//输出字符串不像输出整形，
						//不需要输入长度，因为可以用字符串结尾的'\0'结束
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
	int a[N] = { 1,2,3,4,5 };//不可以用变量，但可以用符号常量（defind）
	int i = 3;
	//a[5] = 60;
	//a[6] = 70;
	//[7] = 80;
	print1(a, 4);//间隔八个字节，访问越界

	char c1[6] = { 'h','e','l','l','o' };
	char c2[8] = "hello";
	char c3[5] = "hello";//字符数组定义时要多一个字符，否则会出现“烫”（cc cc）
	printf("%s---%s---%s\n", c1, c2, c3);

	char e[20], f[20];
	scanf("%s%s", &e, &f);//不需要加空格,如果字符串本省有空格，用gets
	printf("%s-------%s\n", e, f);
	print2(c1);
}