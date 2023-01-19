#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int KeyType;
typedef struct BiTNode {
	KeyType key;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

void inOrder(BiTree p);
void Creat_BST(BiTree& T, KeyType str[], int n);
int BST_Insert(BiTree& T, KeyType k);
BiTree BST_Search(BiTree T, int k, BiTree& p);
int BST_Delete(BiTree& T, KeyType k);