#include "fun.h"

int Index(SString S[], SString T[]) {
	int i = 1, j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0]) {
		return i - T[0];
	}
	else {
		return 0;
	}
}
int Index_res(SString S[], SString T[]) {
	int i = 1, j = 1;
	int res = 0;
	while (i <= S[0]) {
		if (S[i] == T[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
		if (j > T[0]) {
			++res;
		}
	}
	return res;
}
void get_next(SString T[], int next[]) {
	int i = 1;
	next[1] = 0;						//恒为0
	int j = 0;
	while (i < T[0]) {					//T[0]记录字符串长度
		if (j == 0 || T[i] == T[j]) {	//当j=0时,说明回到了开头
			++i;
			++j;
			next[i] = j;				//记录重复出现的位置
		}
		else {
			j = next[j];				//不相同,找个位置重新比较
		}
	}
}
int KMP(SString S[], SString T[], int next[], int pos) {
	int i = pos;				//开始查找的位置
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j > T[0]) {
		return i - T[0];
	}
	else {
		return 0;
	}
}