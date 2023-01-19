//当一个节点的左孩子指针或者右孩子指针是空的,线索二叉树就是不让节点指针空着
//先建二叉树,再建线索二叉树

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
//这里可以将中序遍历输出的结果存在一个数组中,之后循环数组构建线索二叉树////////
void InThread(ThreadTree& p, ThreadTree& pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);		//递归找树的左孩子
		if (p->lchild == NULL) {
			p->lchild = pre;				//左边为空,填写当前节点的前驱
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL) {
			//pre节点右孩子为NULL.就让其指向后继节点p
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
//////////////////////////////////////////////////////////////////////////////
int main() {
	ThreadTree pnew;								//pnew用于循环的新树
	char c;											//输入的新字符					
	ThreadTree tree = NULL;							//tree是树根
	ptag_t phead = NULL, ptail = NULL;				//phead就是队列头，ptail就是队列尾
	ptag_t listpnew = NULL, pcur = NULL;
	//abc de
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		////////////////////////////树循环元素///////////////////////////////////
		pnew = (ThreadTree)calloc(1, sizeof(ThreadNode));	//calloc申请空间并赋值为0
		pnew->c = c;
		/////////////////////////////队列循环元素素//////////////////////////////
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//
		listpnew->p = pnew;
		/////////////////////////////当树为空时初始化数和队列/////////////////////
		if (NULL == tree) {
			tree = pnew;							//树根
			phead = listpnew;						//队列头
			ptail = listpnew;						//队列尾
			pcur = listpnew;
			continue;
		}
		//////////////////////////////当树不为空时用尾插法创建队列////////////////
		else {
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		///////////////////////////////树节点前为空时在前面插入///////////////////
		if (pcur->p->lchild == NULL) {
			pcur->p->lchild = pnew;
		}
		//前不为空时,在后面插入.phead,ptail,pur,listpnew其实是同一个队列的指针,前面32行已经将新元素放到了next里面,因此这里的pcur = pcur->pnext是更新了pcur
		else if (pcur->p->rchild == NULL) {
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}
	printf("\n---------------中序遍历---------------\n");//先打印左,再打印中,再打印右
	inOrder(tree);
	CreateInThread(tree);
	printf("\n%c\n%d", tree->lchild->rchild->lchild->c, tree->lchild->rchild->lchild->ltag);
	printf("\n%c\n%d", tree->lchild->rchild->rchild->c, tree->lchild->rchild->rchild->rtag);
}