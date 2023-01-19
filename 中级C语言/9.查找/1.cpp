#include "fun.h"

void ST_Init(SSTable& ST, int len) {
	ST.TableLen = len + 1;		//多申请一个存放哨兵
	ST.elem = (ElemType*)calloc(1, sizeof(ElemType) * ST.TableLen);
	srand(time(NULL));
	for (int i = 0; i < ST.TableLen; i++) {
		ST.elem[i] = rand() % 100;
	}
}
void ST_Print(SSTable ST, int len) {
	for (int i = 0; i <= len; i++) {
		printf("%3d", ST.elem[i]);
	}
	printf("\n");
}
int Search_Seq(SSTable ST, ElemType key) {
	ST.elem[0] = key;
	int i;
	for (i = ST.TableLen - 1; ST.elem[i] != key; i--);
	return i;
}
void sort(ElemType elem[], int len) {
	int i, j, tmp;
	for (i = 1; i < len; i++) {
		for (j = i + 1; j <= len; j++) {
			if (elem[i] < elem[j]) {
				tmp = elem[i];
				elem[i] = elem[j];
				elem[j] = tmp;
			}
		}
	}
}
int compare(const void* left, const void* right) {
	return *(ElemType*)left - *(ElemType*)right;		//从小到大
}
int Binary_Search(SSTable L, ElemType key) {
	int low = 0, high = L.TableLen - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.elem[mid] == key) {
			return mid;
		}
		else if (L.elem[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}