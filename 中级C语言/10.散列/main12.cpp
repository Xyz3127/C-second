#include "fun.h"

int main() {
	const char* pStr[8] = { "qaz","wsx","edc","rfv","tgb","yhn","ujm","ik," };
	int i;
	const char* pHash_table[MaxKey] = { NULL };//散列表
	for (i = 0; i < 8; i++) {
		if (pHash_table[hash(pStr[i])] == NULL) {
			pHash_table[hash(pStr[i])] = pStr[i];
			printf("查找字符串%s,经过哈希计算公式的值是%d,在pHash_table中查找该值,得到字符串%s\n", pStr[i], hash(pStr[i]), pHash_table[hash(pStr[i])]);
		}
		else {
			printf("字符串%s和字符串%s计算所得哈希值冲突\n", pHash_table[hash(pStr[i])], pStr[i]);
		}
	}
}