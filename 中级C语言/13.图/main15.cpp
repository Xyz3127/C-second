#include "fun.h"

int main() {
	LGraph* pG1, * pG2;
	pG1 = create_example_lgraph();				//����ͼ
	pG2 = create_example_lgraph_directed();		//����ͼ
	print_lgraph(*pG1);
	print_lgraph(*pG2);
	DFSTraverse(*pG1);							//������ȱ���
	BFS(*pG1);
}