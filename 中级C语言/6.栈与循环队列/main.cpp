#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void print(int a[20], int num) {
	int i = 0;
	while (i <= num) {
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
}

int Fib1(int i) {
	if (i == 0) {
		return 0;
	}
	if (i == 1 || i == 2) {
		return 1;
	}
	return Fib1(i - 1) + Fib1(i - 2);
}

int Fib2(int i) {
	if (i == 0) {
		return 0;
	}
	if (i == 1 || i == 2) {
		return 1;
	}
	int j, last1 = 1, last2 = 1, tmp;
	for (j = 3; j <= i; j++) {
		tmp = last1 + last2;
		last1 = last2;
		last2 = tmp;
	}
	return last2;
}

int Fib3(int i) {
	//二阶常系数齐次线性差分方程
	int j= (float)(1 / sqrt(5) * pow(((1 + sqrt(5)) / 2), i) - 1 / sqrt(5) * pow(((1 - sqrt(5)) / 2), i));
	return j;
}

int main() {
	int F1[100] = { 0 }, F2[100] = { 0 }, F3[100] = { 0 };
	int num;
	scanf("%d", &num);//（小于等于46）
	for (int i = 0; i <= num; i++) {
		//F1[i] = Fib1(i);
		F2[i] = Fib2(i);
		F3[i] = Fib3(i);
	}
	print(F1, num);
	print(F2, num);
	print(F3, num);
}