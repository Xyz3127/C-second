#include "fun.h"

void inOrder(BiTree p) {
	if (p != NULL) {
		inOrder(p->lchild);
		printf("%3d", p->key);
		inOrder(p->rchild);
	}
}
void Creat_BST(BiTree& T, KeyType str[], int n) {
	T = NULL;
	for (int i = 0; i < n; i++) {
		BST_Insert(T, str[i]);
	} 
}
int BST_Insert(BiTree& T, KeyType k) {
	if (NULL == T) {
		T = (BiTree)calloc(1,sizeof(BiTNode));
		T->key = k;
		return 1;
	}
	else if (T->key == k) {
		return 0;
	}
	else if (k < T->key) {
		return BST_Insert(T->lchild, k);//���������T = (BiTree)calloc(1,sizeof(BiTNode));���,��Ϊ��һ���ڵ�����Ŀռ��ַ��ֵ��T->lchild
		T->key = k;
	}
	else if (k > T->key) {
		return BST_Insert(T->rchild, k);
	}
}
BiTree BST_Search(BiTree T, int k, BiTree& p) {
	p = NULL;
	while (T != NULL && k != T->key) {
		p = T;
		if (k < T->key) {
			T = T->lchild;
		}
		else {
			T = T->rchild;
		}
	}
	return T;								//δ���ҵ�����NULL
}
int BST_Delete(BiTree& T, KeyType k) {
	if (NULL == T) {
		return 0;
	}
	if (k < T->key) {
		BST_Delete(T->lchild, k);
	}
	else if (k > T->key) {
		BST_Delete(T->rchild, k);	
	}
	else {
		if (NULL == T->lchild) {
			BiTree temp = T;
			T = T->rchild;
			free(temp);
			temp = NULL;
			return 1;
		}
		else if (NULL == T->rchild) {
			BiTree temp = T;
			T = T->lchild;
			free(temp);
			temp = NULL;
			return 1;
		}
		else {	//ѡȡ�����������ֵ  ��  ����������С�ڵ�ȥ�滻
			BiTree temp = T->lchild;
			if (temp->rchild != NULL) {
				temp = temp->rchild;
			}
			T->key = temp->key;
			BST_Delete(T->lchild, temp->key);
		}
	}
}