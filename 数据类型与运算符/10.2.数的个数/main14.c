#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num, tmp, i, j;
	scanf("%d", &num);

	int a[100];
	//����
	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}
	//ð������
	for (j = 0; j < num; j++) {
		for (i = j; i < num; i++) {
			if (a[j] > a[i]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	//���������˳��
	for (i = 0; i < num; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	//ͳ�Ʋ�������ִ�����Ե���͸���
	int max=0, count=1, number;
	for (i = 0; i < num - 1; i++) {
		tmp = a[i];
		if (tmp == a[i + 1]) {
			count++;
			if (count >= max) {
				number = tmp;
				max = count;
			}
		}
		else {
			count = 1;
		}
	}
	printf("the max number is %d, the count is %d", number, max);
}