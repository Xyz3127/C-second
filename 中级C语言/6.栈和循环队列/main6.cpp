#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
typedef int Elemtype;
typedef struct Stack {
	Elemtype data[MaxSize];
	int top;
}SqStack;					//FILO  LIFO
void InitStack(SqStack &S) {
	S.top = -1;				//Õ»Îª¿ÕÊ±top=-1
}
bool StackEmpty(SqStack S) {
	if (-1 == S.top) {
		return true;
	}
	return false;
}
bool Push(SqStack& S, Elemtype x) {
	if (S.top == MaxSize-1) {//Õ»Âú
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
int main() {
	SqStack S;
	InitStack(S);

	bool flag;				//ÅÐ¶ÏÕ»¿Õ
	flag = StackEmpty(S);
	if (flag) {
		printf("Õ»¿Õ\n");
	}

	Push(S, 3);				//ÈëÕ»
	Push(S, 4);
	Push(S, 5);

	Elemtype x;				//¶ÁÈ¡Õ»¶¥ÔªËØ
	flag = Gettop(S, x);
	if (flag) {
		printf("%d\n", x);
	}

	flag = Pop(S, x);		//µ¯³öÕ»¶¥ÔªËØ
	if (flag) {
		printf("%d\n", x);
	}
	flag = Gettop(S, x);
	if (flag) {
		printf("%d\n", x);
	}
}