#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MaxVertexNum 10

typedef char VertexType;
typedef int EdgeType;
//ÁÚ½Ó¾ØÕó
typedef struct {
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;
//ÁÚ½Ó±í
typedef struct _ENode {
	int ivex;
	struct _ENode* next_edge;
}ENode, *PENode;
typedef struct _VNode {
	VertexType data;
	ENode* first_edge;
}VNode;
typedef struct _LGraph {
	int vexnum;
	int edgnum;
	VNode vexs[MaxVertexNum];
}LGraph;

void link_last(ENode* node1, ENode* node2);
static int get_position(LGraph g, char ch);
LGraph* create_example_lgraph();
LGraph* create_example_lgraph_directed();
void print_lgraph(LGraph G);
static void DFS(LGraph G, int i, int visited[]);
void DFSTraverse(LGraph G);
void BFS(LGraph G);