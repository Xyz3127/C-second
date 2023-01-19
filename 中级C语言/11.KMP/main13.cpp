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

	pos = Index(S, T);				//暴力匹配
	if (pos) {
		printf("匹配位置%d\n", pos);
	}
	res = Index_res(S, T);			//匹配次数
	if (res) {
		printf("匹配次数%d\n", res);
	}

	get_next(T, next);				//next函数
	pos = KMP(S, T, next, 1);		//KMP
	if (pos) {
		printf("匹配位置%d\n", pos);
	}
	system("pause");
}