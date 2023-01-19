#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	while(rewind(stdin),scanf("%d", &i)!=EOF)//scanf发生错误返回EOF
											//EOF等于（-1）
											//rewind(stdin)清空输入缓存区
	{
		printf("i=%d\n", i);
	}
	return 0;
}