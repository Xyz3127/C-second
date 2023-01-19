 //单目运算符(!)
//高于算数运算符(+ - * / 取模)
//高于关系运算符(> < == !=)
//高于逻辑运算符(&& ||)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	while (scanf("%d", &i) != EOF && i!= 1) {
		if (i > 0) {				//if判断
			printf("%d id bigger than 0\n", i);
		}
		else {
			printf("%d id smaller than 0\n", i);
		}
	}
	int total = 0;

	while (i<=100) {				//while循环
		total = total + i;
		i++;
		printf("%d %d\n", i, total);
	}
	for (i=1, total=0; i <= 100; i++){//for循环
		if (i % 2 == 0) {
			continue;				//结束本轮循环
			break;
		}
		total = total + i;
		printf("%d %d\n", i, total);
		if (total > 2000) {
			break;					//结束循环
		}
	}
}