#include "fun.h"

int main() {
	const char* pStr[8] = { "qaz","wsx","edc","rfv","tgb","yhn","ujm","ik," };
	int i;
	const char* pHash_table[MaxKey] = { NULL };//ɢ�б�
	for (i = 0; i < 8; i++) {
		if (pHash_table[hash(pStr[i])] == NULL) {
			pHash_table[hash(pStr[i])] = pStr[i];
			printf("�����ַ���%s,������ϣ���㹫ʽ��ֵ��%d,��pHash_table�в��Ҹ�ֵ,�õ��ַ���%s\n", pStr[i], hash(pStr[i]), pHash_table[hash(pStr[i])]);
		}
		else {
			printf("�ַ���%s���ַ���%s�������ù�ϣֵ��ͻ\n", pHash_table[hash(pStr[i])], pStr[i]);
		}
	}
}