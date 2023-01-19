#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5
typedef int Elemtype;
typedef struct Queue {
	Elemtype data[MaxSize];//只能存MaxSize-1个元素
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
	bool ret;				//存储返回值
	Elemtype element;		//存储出队序列

	InitQueue(Q);			//初始化队列

	ret = isEmpty(Q);		//判断是否为空
	if (ret) {
		printf("队列为空\n");
	}

	ret = EnQueue(Q, 3);	//入队
	ret = EnQueue(Q, 4);
	ret = EnQueue(Q, 5);
	if (ret) {
		printf("入队成功\n");
	}

	ret = DeQueue(Q, element);//出队
	if (ret) {
		printf("出队%d\n",element);
	}
}