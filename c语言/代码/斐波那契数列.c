#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i, n, a1=0, a2=1, next;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("%d, ", a1);
		next = a1 + a2;
		a1 = a2;
		a2 = next;
	}
	return 0;
}