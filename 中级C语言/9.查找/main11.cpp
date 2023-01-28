#include "fun.h"

int main() {
	SSTable ST;
	int len = 7;
	ST_Init(ST, len);
	ST_Print(ST, len);

	ElemType key;
	scanf("%d", &key);
	int pos = Search_Seq(ST, key);							//˳�����
	if (pos) {
		printf("ֵ%3d��%3d\n", key, pos);
	}

	sort(ST.elem, len);										//ð������
	ST_Print(ST, len);

	qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);	//��������
	ST_Print(ST, len);

	pos = Binary_Search(ST, key);							//�۰����
	if (pos != -1) {
		printf("ֵ%3d��%3d\n", key, pos);
	}
}