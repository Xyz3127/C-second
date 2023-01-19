#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int f(int i) {
	if (1 == i) {
		return 1;
	}
	return i * f(i - 1);//第一步先写公式
}
int step(int i) {
	if (i == 1 || i == 2) {
		return i;
	}
	return step(i - 1) + step(i - 2);
}
int main()
{
	int a = 5;
	int b = f(a);
	float c = ((float)b) / 7;
	printf("%.3f\n", c);

	int n;
	scanf("%d", &n);
	int m = step(n);
	printf("%d", m);
}