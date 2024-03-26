#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int a = 0;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < 5; i++)
	{
		a = n + a * 10;
		sum += a;
	}
	printf("%d ", sum);
}