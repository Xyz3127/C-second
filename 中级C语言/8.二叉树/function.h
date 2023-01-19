#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef char BiElemType;
typedef struct BiTNode {
	BiElemType c;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;
typedef struct tag {
	BiTree p;
	struct tag* pnext;
}tag_t, * ptag_t;

typedef BiTree Elemtype;

typedef struct Stack {
	Elemtype data[MaxSize];
	int top;
}SqStack;

typedef struct Queue {
	Elemtype data[MaxSize];
	int front, rear;
}SqQueue;

void InitStack(SqStack& S);
bool StackEmpty(SqStack S);
bool Push(SqStack& S, Elemtype x);
bool Gettop(SqStack S, Elemtype& x);
bool Pop(SqStack& S, Elemtype& x);

void InitQueue(SqQueue& Q);
bool isEmpty(SqQueue Q);
bool EnQueue(SqQueue& Q, Elemtype x);
bool DeQueue(SqQueue& Q, Elemtype& x);

void preOrder(BiTree p);
void inOrder(BiTree p);
void postOrder(BiTree p);
void inOrder2(BiTree p);
void levelOrder(BiTree p);