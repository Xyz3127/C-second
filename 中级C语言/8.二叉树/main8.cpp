#include "function.h"

int main() {
	BiTree pnew;									//pnew����ѭ��������
	int i, j, pos;
	char c;											//��������ַ�					
	BiTree tree = NULL;								//tree������
	ptag_t phead = NULL, ptail = NULL;				//phead���Ƕ���ͷ��ptail���Ƕ���β
	ptag_t listpnew = NULL, pcur = NULL;			//listpnew������ѭ�����¶���
													//pcur����ָʾ������ڵ��λ��
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		////////////////////////////��ѭ��Ԫ��///////////////////////////////////
		pnew = (BiTree)calloc(1, sizeof(BiTNode));	//calloc����ռ䲢��ֵΪ0
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
	//abcdefghij
	printf("\n---------------ǰ�����---------------\n");//�ȴ�ӡ��,�ٴ�ӡ��,�ٴ�ӡ��;�������
	preOrder(tree);
	printf("\n---------------�������---------------\n");//�ȴ�ӡ��,�ٴ�ӡ��,�ٴ�ӡ��
	inOrder(tree);
	printf("\n---------------�������---------------\n");//�ȴ�ӡ��,�ٴ�ӡ��,�ٴ�ӡ��
	postOrder(tree);
	printf("\n------------��������ǵݹ�------------\n");
	inOrder2(tree);
	printf("\n---------------�������---------------\n");//������ȱ���
	levelOrder(tree);
}