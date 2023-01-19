#include "fun.h"

int main() {
	SSTable ST;
	int len = 10;
	//memcpy(ST.elem,A,sizeof(A))           //Ω´ ˝◊ÈA∏¥÷∆µΩST.elem

	ST_Init(ST, len);
	ST_Print(ST.elem, len);
	///////////////////////Ωªªª≈≈–Ú//////////////////////
	printf("√∞≈›≈≈–Ú\n");
	ST_Init(ST, len);
	BubbleSort(ST.elem);					//√∞≈›≈≈–Ú
	ST_Print(ST.elem, len);

	printf("øÏÀŸ≈≈–Ú\n");
	ST_Init(ST, len);
	QuickSort(ST.elem, 1, ST.TableLen - 1);	//øÏÀŸ≈≈–Ú
	ST_Print(ST.elem, len);
	////////////////////////≤Â»Î≈≈–Ú//////////////////////
	printf("÷±Ω”≤Â»Î≈≈–Ú\n");
	ST_Init(ST, len);
	InsertSort(ST.elem);					//÷±Ω”≤Â»Î≈≈–Ú
	ST_Print(ST.elem, len);

	printf("’€∞Î≤Â»Î≈≈–Ú\n");
	ST_Init(ST, len);
	MidInsertSort(ST.elem);					//’€∞Î≤Â»Î≈≈–Ú 
	ST_Print(ST.elem, len);

	printf("œ£∂˚≈≈–Ú\n");
	ST_Init(ST, len);
	ShellSort(ST.elem);						//œ£∂˚≈≈–Ú 
	ST_Print(ST.elem, len);
	////////////////////////—°‘Ò≈≈–Ú//////////////////////
	printf("ºÚµ•—°‘Ò≈≈–Ú\n");
	ST_Init(ST, len);
	SelectSort(ST.elem);					//ºÚµ•—°‘Ò≈≈–Ú 
	ST_Print(ST.elem, len);

	printf("∂—≈≈–Ú\n");
	ST_Init(ST, len);
	HeapSort(ST.elem);						//∂—≈≈–Ú
	ST_Print(ST.elem, len);					//◊Û∫¢◊”:son=2*dad+1
	////////////////////////πÈ≤¢≈≈–Ú/////////////////////
	printf("πÈ≤¢≈≈–Ú\n");
	ST_Init(ST, len);
	MergeSort(ST.elem, 1, 10);					//πÈ≤¢≈≈–Ú 
	ST_Print(ST.elem, len);

}