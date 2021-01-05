

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#if 0
int main()
{
	char str[2][20] = {"beijing", "zzzzzzzzzzzz" },*p=str;
	
	for (int i = 0; i < sizeof(str)/sizeof(str[0]); i++)
	{
		for (int j = 0; j < sizeof(str[0])/sizeof(str[0][0]); j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", strlen(p));

	return 0;
}
#endif
