#include "fun.h"

int main() {
	SSTable ST;
	int len = 10;
	//memcpy(ST.elem,A,sizeof(A))           //������A���Ƶ�ST.elem

	ST_Init(ST, len);
	ST_Print(ST.elem, len);
	///////////////////////��������//////////////////////
	printf("ð������\n");
	ST_Init(ST, len);
	BubbleSort(ST.elem);					//ð������
	ST_Print(ST.elem, len);

	printf("��������\n");
	ST_Init(ST, len);
	QuickSort(ST.elem, 1, ST.TableLen - 1);	//��������
	ST_Print(ST.elem, len);
	////////////////////////��������//////////////////////
	printf("ֱ�Ӳ�������\n");
	ST_Init(ST, len);
	InsertSort(ST.elem);					//ֱ�Ӳ�������
	ST_Print(ST.elem, len);

	printf("�۰��������\n");
	ST_Init(ST, len);
	MidInsertSort(ST.elem);					//�۰�������� 
	ST_Print(ST.elem, len);

	printf("ϣ������\n");
	ST_Init(ST, len);
	ShellSort(ST.elem);						//ϣ������ 
	ST_Print(ST.elem, len);
	////////////////////////ѡ������//////////////////////
	printf("��ѡ������\n");
	ST_Init(ST, len);
	SelectSort(ST.elem);					//��ѡ������ 
	ST_Print(ST.elem, len);

	printf("������\n");
	ST_Init(ST, len);
	HeapSort(ST.elem);						//������
	ST_Print(ST.elem, len);					//����:son=2*dad+1
	////////////////////////�鲢����/////////////////////
	printf("�鲢����\n");
	ST_Init(ST, len);
	MergeSort(ST.elem, 1, 10);					//�鲢���� 
	ST_Print(ST.elem, len);

}