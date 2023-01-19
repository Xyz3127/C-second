#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char SString;

int Index(SString S[], SString T[]);
int Index_res(SString S[], SString T[]);
void get_next(SString T[], int next[]);
int KMP(SString S[], SString T[], int next[], int pos);