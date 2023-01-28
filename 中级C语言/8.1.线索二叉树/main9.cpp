//��һ���ڵ������ָ������Һ���ָ���ǿյ�,�������������ǲ��ýڵ�ָ�����
//�Ƚ�������,�ٽ�����������

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct ThreadNode {
	ElemType c;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;
	int rtag;
}ThreadNode, * ThreadTree;
typedef struct tag {
	ThreadTree p;
	struct tag* pnext;
}tag_t, * ptag_t;

void inOrder(ThreadTree p) {
	if (p != NULL) {
		inOrder(p->lchild);
		putchar(p->c);
		inOrder(p->rchild);
	}
}
//������Խ������������Ľ������һ��������,֮��ѭ�����鹹������������////////
void InThread(ThreadTree& p, ThreadTree& pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);		//�ݹ�����������
		if (p->lchild == NULL) {
			p->lchild = pre;				//���Ϊ��,��д��ǰ�ڵ��ǰ��
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			//pre�ڵ��Һ���ΪNULL.������ָ���̽ڵ�p
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}
void CreateInThread(ThreadTree T) {
	ThreadTree pre = NULL;
	if (T != NULL) {
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
//�������������������µĵ�һ���ڵ�
ThreadTree Firstnode(ThreadTree p) {
	while (p->ltag == 0) {
		p = p->lchild;								//�����½ڵ㲻һ����Ҷ�ڵ�
	}
	return p;
}
//�����������ڵ��ܵĺ�̽ڵ�
ThreadTree Nextnode(ThreadTree p) {
	if (p->rtag == 0) {
		return Firstnode(p->rchild);
	}
	else {
		return p->rchild;
	}
}
//��������������������㷨
void Inorder(ThreadTree T) {
	printf("\n");
	for (ThreadTree p = Firstnode(T); p != NULL; p = Nextnode(p)) {
		printf("%c ", p->c);
	}
}
//////////////////////////////////////////////////////////////////////////////
int main() {
	ThreadTree pnew;								//pnew����ѭ��������
	char c;											//��������ַ�					
	ThreadTree tree = NULL;							//tree������
	ptag_t phead = NULL, ptail = NULL;				//phead���Ƕ���ͷ��ptail���Ƕ���β
	ptag_t listpnew = NULL, pcur = NULL;
	//abc de 
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		////////////////////////////��ѭ��Ԫ��///////////////////////////////////
		pnew = (ThreadTree)calloc(1, sizeof(ThreadNode));	//calloc����ռ䲢��ֵΪ0
		pnew->c = c;
		/////////////////////////////����ѭ��Ԫ����//////////////////////////////
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//
		listpnew->p = pnew;
		/////////////////////////////����Ϊ��ʱ��ʼ�����Ͷ���/////////////////////
		if (NULL == tree) {
			tree = pnew;							//����
			phead = listpnew;						//����ͷ
			ptail = listpnew;						//����β
			pcur = listpnew;
			continue;
		}
		//////////////////////////////������Ϊ��ʱ��β�巨��������////////////////
		else {
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		///////////////////////////////���ڵ�ǰΪ��ʱ��ǰ�����///////////////////
		if (pcur->p->lchild == NULL) {
			pcur->p->lchild = pnew;
		}
		//ǰ��Ϊ��ʱ,�ں������.phead,ptail,pur,listpnew��ʵ��ͬһ�����е�ָ��,ǰ��32���Ѿ�����Ԫ�طŵ���next����,��������pcur = pcur->pnext�Ǹ�����pcur
		else if (pcur->p->rchild == NULL) {
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}
	printf("\n---------------�������---------------\n");//�ȴ�ӡ��,�ٴ�ӡ��,�ٴ�ӡ��
	inOrder(tree);

	CreateInThread(tree);
	printf("\n%c %d", tree->lchild->rchild->lchild->c, tree->lchild->rchild->ltag);
	printf("\n%c %d\n", tree->lchild->rchild->rchild->c, tree->lchild->rchild->rtag);

	ThreadTree tmp = Firstnode(tree);			//��һ����Ҷ�ڵ�,Ҳ����˵��һ������������
	printf("��һ���ڵ�\n%c %d %d", tmp->c, tmp->ltag, tmp->rtag);

	tmp = tree;
	tmp = tmp;
	tmp = Nextnode(tmp);
	printf("\n%c %d %d", tmp->c, tmp->ltag, tmp->rtag);

	tmp = tree;
	Inorder(tmp);
}