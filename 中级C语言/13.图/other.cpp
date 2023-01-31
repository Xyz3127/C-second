#include "fun.h"

//����ch��martrix�����е�λ��
static int get_position(LGraph g, char ch) {//static ȫ�ֱ���
	int i;
	for (i = 0; i < g.vexnum; i++) {
		if (g.vexs[i].data == ch) {
			return i;
		}
	}
	return -1;
}
static void link_last(ENode* list, ENode* node)
{
	ENode* p = list;
	while (p->next_edge)
		p = p->next_edge;
	p->next_edge = node;
}
LGraph* create_example_lgraph() {
	char c1, c2;
	char vexs[] = { 'A','B','C','D','E','F','G' };
	char edges[][2] = {
		{'A','C'},
		{'A','D'},
		{'A','F'},
		{'B','C'},
		{'C','D'},
		{'E','G'},
		{'F','G'}
	};
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	int elen = sizeof(edges) / sizeof(edges[0]);

	int i, p1, p2;
	ENode* node1, * node2;
	LGraph* pG;//pG��ʾͼ
	if ((pG = (LGraph*)calloc(1, sizeof(LGraph))) == NULL) {
		//memset(pG, 0, sizeof(LGraph));	//memset��malloc��Ͽ��Դﵽcalloc����0��Ч��,��memset���Ը��Ի���ֵ(��һ����0)
	}
	pG->vexnum = vlen;
	pG->edgnum = elen;
	//��ʼ������
	for (i = 0; i < pG->vexnum; i++) {
		pG->vexs[i].data = vexs[i];
		pG->vexs[i].first_edge = NULL;
	}
	//��ʼ����
	for (i = 0; i < pG->edgnum; i++) {
		//��ȡ�ߵ���ʼ����ͽ�������
		c1 = edges[i][0];
		c2 = edges[i][1];
		//���ض����±�
		p1 = get_position(*pG, c1);
		p2 = get_position(*pG, c2);

		//��ʼ��node1
		node1 = (ENode*)calloc(1, sizeof(ENode));
		node1->ivex = p2;
		//��node1���ӵ�"p1���������ĩβ"
		if (pG->vexs[p1].first_edge == NULL) {
			pG->vexs[p1].first_edge = node1;
		}
		else {
			link_last(pG->vexs[p1].first_edge, node1);
		}

		//��ʼ��node2
		node2 = (ENode*)calloc(1, sizeof(ENode));
		node2->ivex = p1;
		if (pG->vexs[p2].first_edge == NULL) {
			pG->vexs[p2].first_edge = node2;
		}
		else {
			link_last(pG->vexs[p2].first_edge, node2);
		}
	}
	return pG;
}
LGraph* create_example_lgraph_directed() {
	char c1, c2;
	char vexs[] = { 'A','B','C','D','E','F','G' };
	char edges[][2] = {
		{'A','C'},
		{'A','D'},
		{'A','F'},
		{'B','C'},
		{'C','D'},
		{'E','G'},
		{'F','G'}
	};
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	int elen = sizeof(edges) / sizeof(edges[0]);

	int i, p1, p2;
	ENode* node1;
	LGraph* pG;//pG��ʾͼ
	if ((pG = (LGraph*)calloc(1, sizeof(LGraph))) == NULL) {
		//memset(pG, 0, sizeof(LGraph));	//memset��malloc��Ͽ��Դﵽcalloc����0��Ч��,��memset���Ը��Ի���ֵ(��һ����0)
	}
	pG->vexnum = vlen;
	pG->edgnum = elen;
	//��ʼ������
	for (i = 0; i < pG->vexnum; i++) {
		pG->vexs[i].data = vexs[i];
		pG->vexs[i].first_edge = NULL;
	}
	//��ʼ����
	for (i = 0; i < pG->edgnum; i++) {
		//��ȡ�ߵ���ʼ����ͽ�������
		c1 = edges[i][0];
		c2 = edges[i][1];
		//���ض����±�
		p1 = get_position(*pG, c1);
		p2 = get_position(*pG, c2);

		//��ʼ��node1
		node1 = (ENode*)calloc(1, sizeof(ENode));
		node1->ivex = p2;
		//��node1���ӵ�"p1���������ĩβ"
		if (pG->vexs[p1].first_edge == NULL) {
			pG->vexs[p1].first_edge = node1;
		}
		else {
			link_last(pG->vexs[p1].first_edge, node1);
		}
	}
	return pG;
}
void print_lgraph(LGraph G) {
	int i;
	ENode* node;
	printf("List Graph:\n");
	for (i = 0; i < G.vexnum; i++) {
		printf("%d(%C): ", i, G.vexs[i].data);
		node = G.vexs[i].first_edge;
		while (node != NULL) {
			printf("%d(%C) ", node->ivex, G.vexs[node->ivex].data);
			node = node->next_edge;
		}
		printf("\n");
	}
}
static void DFS(LGraph G, int i, int visited[]) {
	ENode* node;
	visited[i] = 1;
	printf("%c ", G.vexs[i].data);
	node = G.vexs[i].first_edge;
	while (node != NULL) {
		if (!visited[node->ivex]) {
			DFS(G, node->ivex, visited);
		}
		node = node->next_edge;//���ʹ���ָ����һ���ڵ�
	}
}
void DFSTraverse(LGraph G) {
	int i;
	int visited[MaxVertexNum] = { 0 };
	printf("DFS: ");
	for (i = 0; i < G.vexnum; i++) {//��һ���ڵ���������Ľڵ���ѭ������
		if (!visited[i]) {
			DFS(G, i, visited);
		}
	}
	printf("\n");
}
void BFS(LGraph G) {
	int i, j, k;
	int head = 0, rear = 0;
	int queue[MaxVertexNum];
	int visited[MaxVertexNum] = { 0 };
	ENode* node;
	printf("BFS: ");
	for (i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			printf("%c ", G.vexs[i].data);
			queue[rear++] = i;
		}
		while (head != rear) {
			j = queue[head++];
			node = G.vexs[j].first_edge;
			while (node != NULL) {
				k = node->ivex;
				if (!visited[k]) {
					visited[k] = 1;
					printf("%c ", G.vexs[k].data);
					queue[rear++] = k;
				}
				node = node->next_edge;
			}
		}
	}
	printf("\n");
}