#include "fun.h"

void ST_Init(SSTable& ST, int len) {
	ST.TableLen = len + 1;
	ST.elem = (ElemType*)calloc(1, sizeof(ElemType) * ST.TableLen);
	ST.elem[0] = len;
	srand(time(NULL));
	for (int i = 1; i <= ST.elem[0]; i++) {
		ST.elem[i] = rand() % 100;
	}
}
void ST_Print(ElemType* elem, int len) {
	for (int i = 0; i <= len; i++) {
		printf("%3d", elem[i]);
	}
	printf("\n");
}
void BubbleSort1(ElemType* elem) {
	int i, j, tmp;
	for (i = 1; i <= elem[0]; i++) {
		for (j = i + 1; j <= elem[0]; j++) {
			if (elem[i] > elem[j]) {		//��С������
				tmp = elem[i];
				elem[i] = elem[j];
				elem[j] = tmp;
			}
		}
	}
}
void BubbleSort(ElemType* elem) {
	int i, j, tmp;
	bool flag;
	for (i = 1; i < elem[0]; i++) {
		flag = true;
		for (j = elem[0]; j > i; j--) {
			if (elem[j-1] < elem[j]) {		//�Ӵ�С��
				tmp = elem[j-1];
				elem[j-1] = elem[j];
				elem[j] = tmp;
				flag = false;
			}
		}
		if (flag) {
			break;
		}
	}
}
int Partition(ElemType* elem, int left, int right) {
	int k, i, tmp;
	k = i = left;
	for (; i < right; i++) {
		if (elem[i] < elem[right]) {		//��С������
			tmp = elem[i];
			elem[i] = elem[k];
			elem[k] = tmp;
			k++;
		}
	}
	tmp = elem[k];
	elem[k] = elem[right];
	elem[right] = tmp;
	return k;
}
void QuickSort(ElemType* elem, int low, int high) {
	if (low < high) {
		int pivotpos = Partition(elem, low, high);
		QuickSort(elem, low, pivotpos - 1);
		QuickSort(elem, pivotpos + 1, high);
	}
}
void InsertSort(ElemType* elem) {
	int i, j, n = elem[0];
	for (i = 2; i <= n; i++) {//������λ����Ϊ�ڱ�λ��,�ӵڶ���Ԫ�ؿ�ʼ��ǰ��
		if (elem[i] > elem[i - 1]) {
			//�Ӵ�С
			elem[0] = elem[i];//�ݴ�λ��
			for (j = i - 1; elem[j] < elem[0]; j--) {
				//�Ӵ�С
				elem[j + 1] = elem[j];//�ƶ�Ԫ��(ֱ�Ӹ���,��˳���Ĳ�������)
			}
			elem[j + 1] = elem[0];//���ݴ�Ԫ�ز��뵽��Ӱλ��
		}
	}
	elem[0] = n;
}
void MidInsertSort(ElemType* elem) {
	int i, j, n = elem[0];
	int low, high, mid;
	for (i = 2; i <= n; i++) {//������λ����Ϊ�ڱ�λ��,�ӵڶ���Ԫ�ؿ�ʼ��ǰ��
		elem[0] = elem[i];
		low = 1; high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if(elem[mid] > elem[i]){
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		for (j = i - 1; j >= high+1; j--) {
			elem[j + 1] = elem[j];
		}
		elem[high + 1] = elem[0];//���ݴ�Ԫ�ز��뵽��Ӱλ��
	}
	elem[0] = n;
}
void ShellSort(ElemType* elem) {
	int dk, i, j;
	int n = elem[0];
	for (dk = n / 2; dk >= 1; dk = dk / 2) {
		for (i = dk + 1; i <= n; i++) {
			if (elem[i] > elem[i - dk]) {
				elem[0] = elem[i];
				for (j = i - dk; j > 0 && elem[0] > elem[j]; j = j - dk) {
					elem[j + dk] = elem[j];
				}
				elem[j + dk] = elem[0];
			}
		}
	}
	elem[0] = n;
}
void SelectSort(ElemType* elem) {
	int i, j, min, tmp, n = elem[0];
	for (i = 1; i < n; i++) {
		min = i;
		for (j = i + 1; j <= n; j++) {
			if (elem[j] < elem[min]) {
				min = j;
			}
		}
		if (min != i) {
			tmp = elem[min];
			elem[min] = elem[i];
			elem[i] = tmp;
		}
	}
}
void AdjustDown(ElemType* elem, int i, int len) {
	int dad = i;
	int son = 2 * dad + 1;//�����±�
	int tmp;
	while (son <= len) {
		if (son + 1 <= len && elem[son] > elem[son + 1]) {//�Ӵ�С
			son++;
		}//�Ƿ����Һ���,�Ƚ����Һ���
		if (elem[son] < elem[dad]) {//�Ӵ�С
			tmp = elem[dad];
			elem[dad] = elem[son];
			elem[son] = tmp;
			dad = son;
			son = 2 * dad + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(ElemType* elem) {
	int i, len = elem[0];//len=11(����Ԫ��)
	int tmp;
	//���������
	for (i = len / 2; i >= 0; i--) {
		AdjustDown(elem, i, len);
	}
	tmp = elem[0];
	elem[0] = elem[len];
	elem[len] = tmp;
	for (i = len - 1; i > 0; i--) {
		AdjustDown(elem, 0, i);//ʣ��Ԫ�ص���
		tmp = elem[0];
		elem[0] = elem[i];
		elem[i] = tmp;
	}
}
void Merge(ElemType* elem, int low, int mid, int high) {
	ElemType* B = (ElemType*)malloc(sizeof(elem)*(elem[0]+1));
	memcpy(B, elem, sizeof(elem) * (elem[0] + 1));
	int i, j, k;
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
		if (B[i] <= B[j]) {//��С����
			elem[k] = B[i++];
		}
		else {
			elem[k] = B[j++];
		}
	}
	while (i <= mid) {
		elem[k++] = B[i++];
	}
	while (j <= mid) {
		elem[k++] = B[j++];
	}
}
void MergeSort(ElemType* elem, int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(elem, low, mid);
		MergeSort(elem, mid + 1, high);
		Merge(elem, low, mid, high);
	}
}