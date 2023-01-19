#include "fun.h"

int main() {
	BiTree T;
	BiTree parent; //存储父节点地址
	BiTree search;
	KeyType str[] = { 54,20,66,40,28,79,58 };
	Creat_BST(T, str, 7);							//创建二叉排序树
	inOrder(T);	printf("\n");
	search = BST_Search(T, 40, parent);				//搜索值返回值和父节点地址
	if (search) {
		printf("值=%d,父节点=%d\n", search->key, parent->key);
	}
	int b = BST_Delete(T, 54);						//删除值
	if (b) {
		inOrder(T);	printf("\n");
	}
}