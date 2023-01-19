#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* prior;		//前驱指针
	struct DNode* next;			//后驱指针
}DNode, * DinkList;

//打印链表
void PrintDist(DinkList D) {
	DinkList Q = D;
	D = D->next;
	while (D != NULL) {
		printf("%d ", D->data);
		Q = D;
		D= D->next;
	}
	printf("\n");
	while (Q->prior != NULL) {
		printf("%d ", Q->data);
		Q = Q->prior;
	}
	printf("\n");
}

//双向链表头插法新建链表
DinkList CreatList1(DinkList& D) {
	DinkList s;
	ElemType x;
	D = (DinkList)malloc(sizeof(DNode));
	D->next = NULL;
	D->prior = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		s->next = D->next;
		if (D->next != NULL) {
			D->next->prior = s;
		}
		D->next = s;
		s->prior = D; 
		scanf("%d", &x);
	}
	return D;
}

//双向链表尾插法新建链表
DinkList CreatList2(DinkList& D) {
	D = (DNode*)malloc(sizeof(DNode));
	D->next = NULL;
	D->prior = NULL;
	DNode* s, * r = D;//r代表表尾结点
	ElemType x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;//结尾值的next为NULL
	return D;
}

//查找第几个节点的值(代码与单向链表一致)
DinkList GetElem(DinkList L, ElemType i) {
	if (i == 0) {
		return L;
	}
	if (i < 0) {
		return NULL;
	}
	DinkList p = L->next;
	ElemType j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

//按值查找(代码与单向链表一致)
DinkList GetElem2(DinkList L, ElemType i) {
	DinkList p = L->next;
	while (p && p->data != i) {
		p = p->next;//未找到会指向NULL
	}
	return p;
}

//往第i个位置插入元素
bool ListFrontInsert(DinkList D, ElemType i, ElemType e) {
	DinkList p = GetElem(D, i - 1);
	if (p == NULL) {
		return false;
	}
	DinkList s = (DNode*)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	s->prior = p;
	p->next->prior = s;
	p->next = s;
	return true;
}

//删除第i个位置的元素
bool ListDelete(DinkList D, ElemType i) {
	DinkList p = GetElem(D, i - 1);
	if (NULL == p) {
		return false;
	}
	DinkList q = GetElem(D, i);
	p->next = q->next;
	if (q->next != NULL) {
		q->next->prior = p;
	}
	free(q);
	q = NULL;
	return true;
}

int main() {
	DinkList D;

	//双向链表头插法新建链表
	CreatList1(D);
	PrintDist(D);

	//双向链表尾插法新建链表
	CreatList2(D);
	PrintDist(D);

	//查找第几个节点的值(代码与单向链表一致)
	DinkList search, search2;
	search = GetElem(D, 3);
	if (search == NULL) {
		printf("error\n");
	}
	else {
		printf("第3个元素是%d\n", search->data);
	}

	//按值查找(代码与单向链表一致)
	search2 = GetElem2(D, 5);
	if (search2 == NULL) {
		printf("error");
	}
	else {
		printf("查找到元素%d\n", search2->data);
	}

	//往第i个位置插入元素
	bool FI = ListFrontInsert(D, 3, 555);
	if (FI) {
		PrintDist(D);
	}

	//删除第i个位置的元素
	bool DD = ListDelete(D, 6);
	if (DD) {
		PrintDist(D);
	}
}