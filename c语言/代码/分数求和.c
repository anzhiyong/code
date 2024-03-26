#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	
	int i = 0;
	int n = 1;
	double sum=0;
	for (i = 1; i <= 100; i++)
	{
		sum += n*1.0 / i;
		n = -n;
	}
	printf("%f", sum);
}