#include "function.h"

void preOrder(BiTree p) {
	if (p != NULL) {
		putchar(p->c);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
void inOrder(BiTree p) {
	if (p != NULL) {
		inOrder(p->lchild);
		putchar(p->c);
		inOrder(p->rchild);
	}
}
void postOrder(BiTree p) {
	if (p != NULL) {
		postOrder(p->lchild);
		postOrder(p->rchild);
		putchar(p->c);
	}
}
void inOrder2(BiTree T) {
	SqStack S;
	InitStack(S);BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {				//当一个节点不为空,压栈,并取左孩子
			Push(S, p);
			p = p->lchild;
		}
		else {					//为空时弹出栈中元素并打印,获取打印元素右节点
			Pop(S, p);putchar(p->c);
			p = p->rchild;
		}
	}
}
void levelOrder(BiTree T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);
	while (!isEmpty(Q)) {
		DeQueue(Q, p); putchar(p->c);
		if (p->lchild != NULL) {
			EnQueue(Q, p->lchild);
		}
		if (p->rchild != NULL) {
			EnQueue(Q, p->rchild);
		}
	}
}