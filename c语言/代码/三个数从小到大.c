#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int k = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		k = b;
		b = a;
		a = k;

	}
	if (a < c)
	{
		k = c;
		c = a;
		a = k;
	}
	if (b < c)
	{
		k = c;
		c = b;
		b = k;
		
	}
	
	printf("%d %d %d ", a, b, c);
}