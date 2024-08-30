#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <math.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 99999; i++)
	{
		int tmp = i;//各位数
		int count = 0;//n
		int sum = 0;

		while (tmp)
		{
			tmp /= 10;//各位数
			count++;
		}
		tmp = i;
		while (tmp)
		{
			sum += pow((tmp % 10), count);
			tmp /= 10;
		}
		if (sum == i)
		{
			printf("%d是水仙花数\n", i);
		}
	}
	return 0;
}