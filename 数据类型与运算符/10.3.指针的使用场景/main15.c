#include <stdio.h>

void change1(int j) {
	j = 5;
}
void change2(int *j) {
	*j = 5;
}

int main()
{
	//指针的传递
	int i = 10;
	printf("before i=%d\n", i);
	change1(i);
	printf("after  i=%d\n", i);
	change2(&i);
	printf("third  i=%d\n", i);

	//指针的偏移
	int a[5] = { 1,2,3,4,5 };
	int* p;
	p= a;
	printf("%d\n", *(p+1));


	int a1 = 5;
	float a2 = 5;
	int* m = &a1;
	float* n = &a1;
	printf("%d\n", *n);
	int* l = n;
	printf("%d\n", *l);
}