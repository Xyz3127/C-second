 //��Ŀ�����(!)
//�������������(+ - * / ȡģ)
//���ڹ�ϵ�����(> < == !=)
//�����߼������(&& ||)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	while (scanf("%d", &i) != EOF && i!= 1) {
		if (i > 0) {				//if�ж�
			printf("%d id bigger than 0\n", i);
		}
		else {
			printf("%d id smaller than 0\n", i);
		}
	}
	int total = 0;

	while (i<=100) {				//whileѭ��
		total = total + i;
		i++;
		printf("%d %d\n", i, total);
	}
	for (i=1, total=0; i <= 100; i++){//forѭ��
		if (i % 2 == 0) {
			continue;				//��������ѭ��
			break;
		}
		total = total + i;
		printf("%d %d\n", i, total);
		if (total > 2000) {
			break;					//����ѭ��
		}
	}
}