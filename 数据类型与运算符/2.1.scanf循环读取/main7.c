#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	while(rewind(stdin),scanf("%d", &i)!=EOF)//scanf�������󷵻�EOF
											//EOF���ڣ�-1��
											//rewind(stdin)������뻺����
	{
		printf("i=%d\n", i);
	}
	return 0;
}