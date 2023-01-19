#include "fun.h"

int main() {
	SSTable ST;
	int len = 7;
	ST_Init(ST, len);
	ST_Print(ST, len);

	ElemType key;
	scanf("%d", &key);
	int pos = Search_Seq(ST, key);							//顺序查找
	if (pos) {
		printf("值%3d在%3d\n", key, pos);
	}

	sort(ST.elem, len);										//冒泡排序
	ST_Print(ST, len);

	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);	//快速排序
	ST_Print(ST, len);

	pos = Binary_Search(ST, key);							//折半查找
	if (pos != -1) {
		printf("值%3d在%3d\n", key, pos);
	}
}