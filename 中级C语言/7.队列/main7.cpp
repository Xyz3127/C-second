#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int Elemtype;
typedef struct Queue {
	Elemtype data[MaxSize];//ֻ�ܴ�MaxSize-1��Ԫ��
	int front,rear;
}SqQueue;
void InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
bool isEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	return false;
}
bool EnQueue(SqQueue& Q, Elemtype x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
bool DeQueue(SqQueue& Q, Elemtype& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
int main() {
	SqQueue Q;
	bool ret;				//�洢����ֵ
	Elemtype element;		//�洢��������

	InitQueue(Q);			//��ʼ������

	ret = isEmpty(Q);		//�ж��Ƿ�Ϊ��
	if (ret) {
		printf("����Ϊ��\n");
	}

	ret = EnQueue(Q, 3);	//���
	ret = EnQueue(Q, 4);
	ret = EnQueue(Q, 5);
	if (ret) {
		printf("��ӳɹ�\n");
	}

	ret = DeQueue(Q, element);//����
	if (ret) {
		printf("����%d\n",element);
	}
}