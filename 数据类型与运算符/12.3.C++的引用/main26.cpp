#include <stdio.h>
#include <stdlib.h>

//��&д���βε�λ����c++���﷨����Ϊ����
void modify_num(int& b) {
	++b;
}
void modify_pointer(int*& p) {

	p = (int*)malloc(17);
	
	p[0] = 5;
	
}
void change2(int* j) {
	*j = 5;
}
int main()
{
	int a = 10;
	modify_num(a);
	printf("a=%d\n", a);

	int i = 10;
	change2(&i);
	printf("i=%d\n", i);

	int* p = NULL;
	modify_pointer(p);
	printf("p[0]=%d\n", *p);

}