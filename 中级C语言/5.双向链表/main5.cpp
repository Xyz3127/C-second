#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* prior;		//ǰ��ָ��
	struct DNode* next;			//����ָ��
}DNode, * DinkList;

//��ӡ����
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

//˫������ͷ�巨�½�����
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

//˫������β�巨�½�����
DinkList CreatList2(DinkList& D) {
	D = (DNode*)malloc(sizeof(DNode));
	D->next = NULL;
	D->prior = NULL;
	DNode* s, * r = D;//r�����β���
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
	r->next = NULL;//��βֵ��nextΪNULL
	return D;
}

//���ҵڼ����ڵ��ֵ(�����뵥������һ��)
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

//��ֵ����(�����뵥������һ��)
DinkList GetElem2(DinkList L, ElemType i) {
	DinkList p = L->next;
	while (p && p->data != i) {
		p = p->next;//δ�ҵ���ָ��NULL
	}
	return p;
}

//����i��λ�ò���Ԫ��
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

//ɾ����i��λ�õ�Ԫ��
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

	//˫������ͷ�巨�½�����
	CreatList1(D);
	PrintDist(D);

	//˫������β�巨�½�����
	CreatList2(D);
	PrintDist(D);

	//���ҵڼ����ڵ��ֵ(�����뵥������һ��)
	DinkList search, search2;
	search = GetElem(D, 3);
	if (search == NULL) {
		printf("error\n");
	}
	else {
		printf("��3��Ԫ����%d\n", search->data);
	}

	//��ֵ����(�����뵥������һ��)
	search2 = GetElem2(D, 5);
	if (search2 == NULL) {
		printf("error");
	}
	else {
		printf("���ҵ�Ԫ��%d\n", search2->data);
	}

	//����i��λ�ò���Ԫ��
	bool FI = ListFrontInsert(D, 3, 555);
	if (FI) {
		PrintDist(D);
	}

	//ɾ����i��λ�õ�Ԫ��
	bool DD = ListDelete(D, 6);
	if (DD) {
		PrintDist(D);
	}
}