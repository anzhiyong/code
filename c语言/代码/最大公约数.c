#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
	scanf("%d %d", &a, &b);
	while (a % b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	printf("���Լ����%d\n", b);
}