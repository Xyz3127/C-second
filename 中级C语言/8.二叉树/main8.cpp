#include "function.h"

int main() {
	BiTree pnew;									//pnew用于循环的新树
	int i, j, pos;
	char c;											//输入的新字符					
	BiTree tree = NULL;								//tree是树根
	ptag_t phead = NULL, ptail = NULL;				//phead就是队列头，ptail就是队列尾
	ptag_t listpnew = NULL, pcur = NULL;			//listpnew是用于循环的新队列
													//pcur用于指示添加树节点的位置
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		////////////////////////////树循环元素///////////////////////////////////
		pnew = (BiTree)calloc(1, sizeof(BiTNode));	//calloc申请空间并赋值为0
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
	//abcdefghij
	printf("\n---------------前序遍历---------------\n");//先打印中,再打印左,再打印右;深度优先
	preOrder(tree);
	printf("\n---------------中序遍历---------------\n");//先打印左,再打印中,再打印右
	inOrder(tree);
	printf("\n---------------后序遍历---------------\n");//先打印左,再打印右,再打印中
	postOrder(tree);
	printf("\n------------中序遍历非递归------------\n");
	inOrder2(tree);
	printf("\n---------------层序遍历---------------\n");//广度优先遍历
	levelOrder(tree);
}