#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//��ӡ����
void PrintList(LinkList L) {
	L = L->next;
	while (L != NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

//ͷ�巨�½�����
LinkList CreatList1(LinkList& L) {
	LinkList s;
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
					//ѭ������L->next = L;
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

//β�巨�½�����
LinkList CreatList2(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	LNode* s, * r = L;//r�����β���
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

//���ҵڼ����ڵ��ֵ
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

//��ֵ����
LinkList GetElem2(LinkList L, ElemType i) {
	LinkList p = L->next;
	while (p && p->data != i) {
		p = p->next;//δ�ҵ���ָ��NULL
	}
	return p;
}

//����i��λ�ò���Ԫ��
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

//ɾ����i��λ�õ�Ԫ��
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

	//ͷ�巨�½�����
	CreatList1(L);
	PrintList(L);

	//β�巨�½�����
	CreatList2(L);
	PrintList(L);

	//���ҵڼ����ڵ��ֵ
	LinkList search, search2;
	search = GetElem(L, 2);
	if (search == NULL) {
		printf("error\n");
	}
	else {
		printf("��2��Ԫ����%d\n", search->data);
	}

	//��ֵ����
	search2 = GetElem2(L, 5);
	if (search2 == NULL) {
		printf("error\n");
	}
	else {
		printf("���ҵ�Ԫ��%d\n", search2->data);
	}

	//����i��λ�ò���Ԫ��
	bool FI=ListFrontInsert(L, 1, 555);
	if (FI) {
		PrintList(L);
	}

	//ɾ����i��λ�õ�Ԫ��
	bool LD = ListDelete(L, 3);
	if (LD) {
		PrintList(L);
	}
}