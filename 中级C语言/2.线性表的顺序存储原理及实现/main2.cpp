//���Ա��˳���ʾ
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50			//�������Ա�ĳ���

typedef int ElemType;

typedef struct xianxingbiao{
	int data[MaxSize];		//���Ա�Ԫ��
	int len;				//��ǰ����
}sqList,*psqList;

typedef struct xianxingbiao2 {
	int* data;				//ָʾ��̬���������ָ��
	int Size, len;			//�������������͵�ǰ����
}sqList2, * psqList2;

void print(int a[MaxSize], int b) {
	for (int i = 0; i < b; i++) {
		printf("%d ", a[i]);
	}
	printf("\n%d\n", b);
}

int main() {
	//����
	//�жϲ���λ��i�Ƿ�Ϸ���1 <= i <= len+1��
	//�жϴ洢�ռ��Ƿ�������������x���Ƿ�ᳬ�����鳤�ȣ�
	sqList L = { {1,2,3,4,5,6,7,8,9}, 9 };
                //0,1,2,3,4,5,6,7,8
	ElemType i = 3;
	int x = 999;
	int j=L.len;
	if (i<1 || j + 1 < i || L.len >= MaxSize) {
		printf("error\n");
	}
	else {
		for (; j >= i; j--) {
			L.data[j] = L.data[j - 1];
		}
		L.data[j] = x;
		L.len++;
		print(L.data, L.len);
	}

	//ɾ��
	int k = 9;
	if (k < 1 || L.len < k || L.len == 0) {
		printf("error\n");
	}
	else {
		int e = L.data[k - 1];
		for (; k <= L.len; k++) {
			L.data[k - 1] = L.data[k];
		}
		L.len--;
		print(L.data, L.len);
		printf("%d\n", e);
	}

	//����
	int m = 999;
	int locationt;
	bool C = false;
	if (L.len > 0) {
		for (int i = 0; i < L.len; i++) {
			if (L.data[i] == m) {
				locationt = i + 1;
				C = true;
				break;
			}
		}
		if (C) {
			printf("OK %d",locationt);
		}
		else {
			printf("Not ok");
		}
	}
	else {
		printf("error\n");
	}


	//��̬����
	sqList2 L2;
	L2.data = (int*)malloc(sizeof(int) * MaxSize);	//C��������
	L2.data = new int[MaxSize];						//C++��������
}