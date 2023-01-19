#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//打印链表
void PrintList(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

//头插法新建链表
LinkList CreatList1(LinkList& L) {
	LinkList s;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
					//循环链表：L->next = L;
					//while (L != L)
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		//printf("%p\n%p\n%p\n", L->next, s, s->next);
		s->data = x;
		s->next = L->next;
		L->next = s;
		//printf("%p\n%p\n%p\n", L->next, s, s->next);
		scanf("%d", &x);
	}
	return L;
}

//尾插法新建链表
LinkList CreatList2(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s, * r = L;//r代表表尾结点
	ElemType x;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		//printf("%p\n%p\n%p\n", L->next, s, s->next);
		s->data = x;
		r->next = s;
		r = s;
		//printf("%p\n%p\n%p\n", L->next, s, s->next);
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//查找第几个节点的值
LinkList GetElem(LinkList L, ElemType i) {
	if (i == 0) {
		return L;
	}
	if (i < 0) {
		return NULL;
	}
	LinkList p = L->next;
	ElemType j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

//按值查找
LinkList GetElem2(LinkList L, ElemType i) {
	LinkList p = L->next;
	while (p && p->data != i) {
		p = p->next;//未找到会指向NULL
	}
	return p;
}

//往第i个位置插入元素
bool ListFrontInsert(LinkList L, ElemType i, ElemType e) {
	LinkList p = GetElem(L, i - 1);
	if (p == NULL) {
		return false;
	}
	LinkList s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//删除第i个位置的元素
bool ListDelete(LinkList L, ElemType i) {
	LinkList p = GetElem(L, i - 1);
	if (NULL == p) {
		return false;
	}
	LinkList q = GetElem(L, i);
	p->next = q->next;
	free(q);
	q = NULL;
	return true;
}

int main() {
	LinkList L;

	//头插法新建链表
	CreatList1(L);
	PrintList(L);

	//尾插法新建链表
	CreatList2(L);
	PrintList(L);

	//查找第几个节点的值
	LinkList search, search2;
	search = GetElem(L, 2);
	if (search == NULL) {
		printf("error\n");
	}
	else {
		printf("第2个元素是%d\n", search->data);
	}

	//按值查找
	search2 = GetElem2(L, 5);
	if (search2 == NULL) {
		printf("error\n");
	}
	else {
		printf("查找到元素%d\n", search2->data);
	}

	//往第i个位置插入元素
	bool FI=ListFrontInsert(L, 1, 555);
	if (FI) {
		PrintList(L);
	}

	//删除第i个位置的元素
	bool LD = ListDelete(L, 3);
	if (LD) {
		PrintList(L);
	}
}