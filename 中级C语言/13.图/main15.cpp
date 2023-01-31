#include "fun.h"

int main() {
	LGraph* pG1, * pG2;
	pG1 = create_example_lgraph();				//无向图
	pG2 = create_example_lgraph_directed();		//有向图
	print_lgraph(*pG1);
	print_lgraph(*pG2);
	DFSTraverse(*pG1);							//深度优先遍历
	BFS(*pG1);
}