#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	while (scanf("%c", &c) != EOF)
	{
		if (c != '\n')
		{
			c = c - 32;
			printf("%c", c);
		}
		else
		{
			printf("\n");
		}
	}
}