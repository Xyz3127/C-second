#include "fun.h"

int main() {
	BiTree T;
	BiTree parent; //�洢���ڵ��ַ
	BiTree search;
	KeyType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str, 7);							//��������������
	inOrder(T);	printf("\n");
	search = BST_Search(T, 40, parent);				//����ֵ����ֵ�͸��ڵ��ַ
	if (search) {
		printf("ֵ=%d,���ڵ�=%d\n", search->key, parent->key);
	}
	int b = BST_Delete(T, 54);						//ɾ��ֵ
	if (b) {
		inOrder(T);	printf("\n");
	}
}