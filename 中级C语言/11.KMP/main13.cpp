#include "fun.h"

int main() {
	char S[256];
	char T[10];
	int next[10];
	int pos;
	int res;
	S[0] = strlen("abcabaaabaabcac");
	strcpy(S + 1, "abcabaaabaabcac");
	T[0] = strlen("abaa");
	strcpy(T + 1, "abaa");

	pos = Index(S, T);				//����ƥ��
	if (pos) {
		printf("ƥ��λ��%d\n", pos);
	}
	res = Index_res(S, T);			//ƥ�����
	if (res) {
		printf("ƥ�����%d\n", res);
	}

	get_next(T, next);				//next����
	pos = KMP(S, T, next, 1);		//KMP
	if (pos) {
		printf("ƥ��λ��%d\n", pos);
	}
	system("pause");
}