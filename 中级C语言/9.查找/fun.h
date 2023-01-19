#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 50

typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable& ST, int len);
void ST_Print(SSTable ST, int len);
int Search_Seq(SSTable ST, ElemType key);
void sort(ElemType elem[], int len);
int Binary_Search(SSTable L, ElemType key);
int compare(const void* left, const void* right);