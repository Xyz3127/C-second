//һ��һ��Ԫ����10��5��2��1��40����ֵ��ÿ����ֵ����һ�ţ��м������ͣ�
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, j, k, m;
	int total=0;
	for (i = 1; i <= 37; i++) {
		for (j = 1; j <= 37; j++) {
			for (k = 1; k <= 37; k++)
				for (m = 1; m <= 37; m++) {
					if ((i + j + k + m == 40) && (10 * i + 5 * j + 2 * k + m == 100)) {
						total++;
						printf("%d %d %d %d\n", i, j, k, m);
					}
				}
		}
	}
	printf("%d", total);
}