#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void mul(int n)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n;
	printf("ÇëÊäÈëÐÐÊý£º");
	scanf("%d", &n);
	mul(n);
	return 0;
}