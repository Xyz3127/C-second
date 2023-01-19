#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
	int vexnum, arcnum;
}MGraph;

