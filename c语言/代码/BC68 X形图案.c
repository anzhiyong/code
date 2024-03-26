#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; ++i)
		{
			int j = 0;
			for (j = 0; j < n; ++j)
			{
				if (j == i)
				{
					printf("*");
				}
				else if (j == n - i - 1)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}