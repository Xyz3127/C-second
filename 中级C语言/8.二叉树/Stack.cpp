#include "function.h"

void InitStack(SqStack& S) {
	S.top = -1;				//Õ»Îª¿ÕÊ±top=-1
}
bool StackEmpty(SqStack S) {
	if (-1 == S.top) {
		return true;
	}
	return false;
}
bool Push(SqStack& S, Elemtype x) {
	if (S.top == MaxSize - 1) {//Õ»Âú
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
bool Gettop(SqStack S, Elemtype& x) {
	if (StackEmpty(S)) {
		return false;
	}
	x = S.data[S.top];
	return true;
}
bool Pop(SqStack& S, Elemtype& x) {
	if (StackEmpty(S)) {
		return false;
	}
	x = S.data[S.top--];
	return true;
}