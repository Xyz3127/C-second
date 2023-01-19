#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef int ElemType;
typedef struct {
	ElemType* elem;
	int TableLen;
}SSTable;

void ST_Init(SSTable& ST, int len);
void ST_Print(ElemType* elem, int len);
void BubbleSort1(ElemType* elem);
void BubbleSort(ElemType* elem);
int Partition(ElemType* elem, int left, int right);
void QuickSort(ElemType* elem, int low, int high);
void InsertSort(ElemType* elem);
void MidInsertSort(ElemType* elem);
void ShellSort(ElemType* elem);
void SelectSort(ElemType* elem);
void AdjustDown(ElemType* elem, int i, int len);
void HeapSort(ElemType* elem);
void Merge(ElemType* elem, int low, int mid, int high);
void MergeSort(ElemType* elem, int low, int high);
